let savedDarkMode = localStorage.getItem("data_bs_theme")

if( savedDarkMode == "light" )
{
    document.documentElement.setAttribute('data-bs-theme','light'); 
}
else
{
    if( savedDarkMode == null )
    {
        localStorage.setItem("data_bs_theme", "dark");
    }
    
    document.documentElement.setAttribute('data-bs-theme','dark'); 
}