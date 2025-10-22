 var builder = WebApplication.CreateBuilder(args);

var app = builder.Build();

if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Error");
}


app.MapGet("/", async context =>
{
    try
    {
        var redirectUrl = "http://localhost:5007";

        context.Response.Redirect(redirectUrl);
    }
    catch (Exception ex)
    {
        context.Response.StatusCode = 500;
        await context.Response.WriteAsync($"An error occurred: {ex.Message}");
    }
});

app.UseStaticFiles();

app.Run();