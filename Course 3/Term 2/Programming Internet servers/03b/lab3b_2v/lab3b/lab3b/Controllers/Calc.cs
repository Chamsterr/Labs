using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;

namespace lab3a_new.Controllers;


[Authorize(Roles = "Employee, Master")]
public class CalcController:Controller
{

    [HttpGet]
    public IActionResult Index()
    {
        return View("Calc");
    }

    [HttpGet]
    public IActionResult Sum()
    {
        ViewBag.press = "+";
        return View("Calc");
    }

    [HttpPost]
    public IActionResult Sum(float? x, float? y)
    {
        ViewBag.press = "+";
        ViewBag.x = x;
        ViewBag.y = y;
        ViewBag.result = x + y;
        return View("Calc");
    }
    [HttpGet]
    public IActionResult Sub()
    {
        ViewBag.press = "-";
        return View("Calc");
    }

    [HttpPost]
    public IActionResult Sub(float? x, float? y)
    {
        ViewBag.press = "-";
        ViewBag.x = x;
        ViewBag.y = y;
        ViewBag.result = x - y;
        return View("Calc");
    }
    [HttpGet]
    public IActionResult Mul()
    {
        ViewBag.press = "*";
        return View("Calc");
    }

    [HttpPost]
    public IActionResult Mul(float? x, float? y)
    {
        ViewBag.press = "*";
        ViewBag.x = x;
        ViewBag.y = y;
        ViewBag.result = x * y;
        return View("Calc");
    }
    [HttpGet]
    public IActionResult Div()
    {
        ViewBag.press = "/";
        return View("Calc");
    }

    [HttpPost]
    public IActionResult Div(float? x, float? y)
    {
        ViewBag.press = "+";
        ViewBag.x = x;
        ViewBag.y = y;
        if (ViewBag.y != 0) ViewBag.result = x / y;
        else ViewBag.result = "err";
        return View("Calc");
    }
}