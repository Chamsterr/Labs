var builder = WebApplication.CreateBuilder(args);

builder.Services.AddControllersWithViews();

var app = builder.Build();

if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Error");
}

app.MapControllerRoute(
    name: "rgf",
    pattern: "{controller=Start}/{action=Index}");

app.Run();
