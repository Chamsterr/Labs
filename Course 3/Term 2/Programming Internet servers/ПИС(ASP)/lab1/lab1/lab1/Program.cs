using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Hosting;
using static System.Net.WebRequestMethods;

var builder = WebApplication.CreateBuilder(args);
var app = builder.Build();

var prepareAnswer = (string method, string parmA, string parmB) 
    => $"{method}-Http-KNV:ParmA={parmA ?? "�� �����"},ParmB={parmB ?? "�� �����"}";

app.MapGet("{text}.KNV", (string? ParmA, string? ParmB) => prepareAnswer("GET", ParmA, ParmB));

app.MapPost("{text}.KNV", (string? ParmA, string? ParmB) => prepareAnswer("POST", ParmA, ParmB));

app.MapPut("{text}.KNV", (string? ParmA, string? ParmB) => prepareAnswer("PUT", ParmA, ParmB));

app.MapPost("Sum", (string? x, string? y) =>
{
    if(x is null) return "�������� x �� ��������";
    if(y is null) return "�������� y �� ��������";
    if(!int.TryParse(x, out var xValue)) return "�������� x �� �������� ������";
    if(!int.TryParse(y, out var yValue)) return "�������� y �� �������� ������";

    return (xValue + yValue).ToString();
});

app.MapGet("Multiply", (context) =>
{
    context.Response.Headers.Add("Content-Type", "text/html");
    return context.Response.WriteAsync(@"
    <html>
        <body>
            <script>
                function send() {
                    var x = 1;
                    var y = 2;
                    var xhr = new XMLHttpRequest();
                    xhr.open('POST', `Multiply?x=${x}&y=${y}`, true);
                    xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
                    xhr.onreadystatechange = function() {
                        if (xhr.readyState !== XMLHttpRequest.DONE) return; 
                        alert('Result: ' + xhr.responseText);
                    }
                    xhr.send();
                }�
                send();
            </script>
        </body>
    </html>
    "); 
});

app.MapPost("Multiply", (string? x, string? y) =>
{
    if(x is null) return "�������� x �� ��������";
    if(y is null) return "�������� y �� ��������";
    if(!int.TryParse(x, out var xValue)) return "�������� x �� �������� ������";
    if(!int.TryParse(y, out var yValue) ) return "�������� y �� �������� ������";
    return (xValue * yValue).ToString();
});

app.MapGet("MultiplyForm", (context) =>
{
    context.Response.Headers.Add("Content-Type", "text/html");
    return context.Response.WriteAsync(@"
    <html>
        <body>
            <form action='MultiplyForm' method='post'>
                <input type='number' name='x' />
                <input type='number' name='y' />
                <input type='submit' value='Multiply' />
            </form>
        </body>
    </html>
    "); 
});

app.MapPost("MultiplyForm", (context) =>
{
    var x = context.Request.Form["x"];
    var y = context.Request.Form["y"];
    var res = "";

    var sx = x[0];
    var sy = y[0];

    if(sx is null) res = "�������� x �� ��������";
    if(sy is null) res = "�������� y �� ��������";
    if(!int.TryParse(sx, out var xValue)) res = "�������� x �� �������� ������";
    if(!int.TryParse(sy, out var yValue)) res = "�������� y �� �������� ������";

    if(res == string.Empty)
        res = (xValue * yValue).ToString();

    return context.Response.WriteAsync(res);
});

app.Run();