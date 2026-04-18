#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

int main(int argc, char *argv[]) {
  // 1. Silence unused parameter warnings
  (void)argc;
  (void)argv;

  // 2. Initialize SDL Video
  if (SDL_Init(SDL_INIT_VIDEO) <= 0) {
    SDL_Log("Failed to init SDL: %s", SDL_GetError());
    return -1;
  }

  // 3. Create a Window
  SDL_Window *window = SDL_CreateWindow("SDL3 GPU API in NvChad", 800, 600, 0);

  // 4. Create the GPU Device
  SDL_GPUDevice *gpu =
      SDL_CreateGPUDevice(SDL_GPU_SHADERFORMAT_SPIRV, true, nullptr);
  if (!gpu) {
    SDL_Log("Failed to create GPU device: %s", SDL_GetError());
    return -1;
  }
  
  // 5. Claim the window for the GPU
  SDL_ClaimWindowForGPUDevice(gpu, window);

  bool running = true;
  SDL_Event event;

  // 6. The Game Loop
  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        running = false;
      }
    }

    SDL_GPUCommandBuffer *cmd = SDL_AcquireGPUCommandBuffer(gpu);
    if (!cmd)
      continue;

    SDL_GPUTexture *swapchain_texture;
    if (SDL_AcquireGPUSwapchainTexture(cmd, window, &swapchain_texture, nullptr,
                                       nullptr)) {

      // FIXED: Use C++ empty braces {} for zero-initialization to satisfy
      // -Wextra
      SDL_GPUColorTargetInfo color_target{};

      color_target.texture = swapchain_texture;

      // FIXED: Removed the C-style compound literal parentheses
      color_target.clear_color = SDL_FColor{0.2f, 0.2f, 0.2f, 1.0f};

      color_target.load_op = SDL_GPU_LOADOP_CLEAR;
      color_target.store_op = SDL_GPU_STOREOP_STORE;

      SDL_GPURenderPass *pass =
          SDL_BeginGPURenderPass(cmd, &color_target, 1, nullptr);
      SDL_EndGPURenderPass(pass);
    }

    SDL_SubmitGPUCommandBuffer(cmd);
  }

  // 7. Cleanup
  SDL_ReleaseWindowFromGPUDevice(gpu, window);
  SDL_DestroyGPUDevice(gpu);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
