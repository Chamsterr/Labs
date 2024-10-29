using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Services;

namespace WebApplication1.Controllers
{
    public class HomeController : Controller
    {
        //ServiceReference1.Service1Client client = new ServiceReference1.Service1Client("Add", "");

        public ActionResult Index()
        {
            //ViewBag.Message = client.Add(1, 2);
            return View();
        }

        public ActionResult About()
        {
            ViewBag.Message = "Your application description page.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }
    }
}