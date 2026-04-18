# 1. Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.20)

# 2. NvChad / Clangd Support: Generate the autocomplete database
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 3. Define the project name
# CRITICAL FIX: Do NOT name your project exactly "SDL". 
# It causes namespace collisions with the actual SDL library.
project(SDL_GPU_App 
    VERSION 1.0.0 
    LANGUAGES CXX
)

# 4. Default to a Debug build if none is specified (gives you better crash logs)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug/Release)" FORCE)
endif()

# 5. Find external libraries
find_package(SDL3 REQUIRED)

# 6. Define your executable and source files
add_executable(${PROJECT_NAME} 
    src/main.cpp
)

# 7. Configure Target Properties (Modern CMake uses target_* instead of global set() where possible)
# Enforce C++23 strictly for this target
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

# Add header directories
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 8. THE LINKER FIX: Tell CMake to actually attach SDL3 to your game
target_link_libraries(${PROJECT_NAME} PRIVATE 
    SDL3::SDL3
)

# 9. Strict compiler warnings (Treat warnings as errors to catch bugs early)
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

# cmake -DCMAKE_BUILD_TYPE=Release -B build
# cmake --build build
