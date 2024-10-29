using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace ClientWeb.Controllers
{
    public class HomeController : Controller
    {
        ServiceReference1.ServiceClient service1 = new ServiceReference1.ServiceClient("BasicHttpBinding_IService");
        public ActionResult Index()
        {
            return View();
        }

        [HttpPost]
        public ActionResult AddNumbers(int number1, int number2)
        {
            ViewBag.Message = service1.Add(number1, number2).ToString();
            return View("Index");
        }

        [HttpPost]
        public ActionResult Concat(string srt1, double double2)
        {
            ViewBag.Message2 = service1.Concat(srt1, double2);
            return View("Index");
        }


        [HttpPost]
        public ActionResult Sum(string string3, int int3, float float3, string string4, int int4, float float4)
        {
            ClientWeb.ServiceReference1.A a1 = new ClientWeb.ServiceReference1.A { s = string3, k = int3, f = float3 };
            ClientWeb.ServiceReference1.A a2 = new ClientWeb.ServiceReference1.A { s = string4, k = int4, f = float4 };


            var result = service1.Sum(a1, a2);
            ViewBag.Message3 = result.s + result.k.ToString() + result.f.ToString();
            return View("Index");
        }
    }
}