using Microsoft.AspNetCore.Builder;
using Microsoft.Extensions.DependencyInjection;
using Newtonsoft.Json.Linq;
using Microsoft.AspNetCore.Mvc.NewtonsoftJson;

var builder = WebApplication.CreateBuilder(args);

// Добавляем поддержку контроллеров и Newtonsoft.Json
builder.Services.AddControllers()
    .AddNewtonsoftJson(); // Добавьте эту строку

builder.Services.AddDistributedMemoryCache();
builder.Services.AddSession(options =>
{
    options.IdleTimeout = TimeSpan.FromMinutes(20);
    options.Cookie.HttpOnly = true;
    options.Cookie.IsEssential = true;
});

// Swagger
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

var app = builder.Build();

if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

// Используем статические файлы
app.UseStaticFiles();

// Включаем использование сессий
app.UseSession();

// Настраиваем маршрутизацию
app.UseRouting();

app.UseAuthorization();

// Перенаправляем на Index.html по умолчанию
app.MapGet("/", () => Results.Redirect("/Index.html"));

// Регистрация контроллеров
app.MapControllers();

app.Run();
