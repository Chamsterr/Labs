using Microsoft.AspNetCore.Mvc;

namespace ASPMVC03.Controllers
{
    public class StartFirstController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }

        public IActionResult One()
        {
            return View();
        }

        public IActionResult Two()
        {
            return View();
        }

        public IActionResult Three()
        {
            return View();
        }
    }
}
