using System.Collections;
using System.Diagnostics;
using Microsoft.AspNetCore.Mvc;
using lab3b.Models;
using lab7.StaticData;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Identity;
using Microsoft.DotNet.Scaffolding.Shared.CodeModifier.CodeChange;

namespace lab3b.Controllers;

public class HomeController : Controller
{
    public IActionResult Index()
    {
        return View();
    }
    [Authorize]
    public IActionResult Privacy()
    {
        return View();
    }
}