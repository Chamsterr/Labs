using Microsoft.AspNetCore.Builder;
using Microsoft.Extensions.DependencyInjection;
using Newtonsoft.Json.Linq;
using Microsoft.AspNetCore.Mvc.NewtonsoftJson;

var builder = WebApplication.CreateBuilder(args);

// ��������� ��������� ������������ � Newtonsoft.Json
builder.Services.AddControllers()
    .AddNewtonsoftJson(); // �������� ��� ������

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

// ���������� ����������� �����
app.UseStaticFiles();

// �������� ������������� ������
app.UseSession();

// ����������� �������������
app.UseRouting();

app.UseAuthorization();

// �������������� �� Index.html �� ���������
app.MapGet("/", () => Results.Redirect("/Index.html"));

// ����������� ������������
app.MapControllers();

app.Run();
