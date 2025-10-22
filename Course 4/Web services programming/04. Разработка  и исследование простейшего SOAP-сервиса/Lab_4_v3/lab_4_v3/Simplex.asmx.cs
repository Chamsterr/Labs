using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Script.Services;
using System.Web.Services;

namespace _04
{
    /// <summary>
    /// Summary description for Simplex
    /// </summary>
    [WebService(Namespace = "http://knv/", Description = "<h1>Lab4 hamster Glavnyi</h1>")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.Web.Script.Services.ScriptService]
    public class Simplex : System.Web.Services.WebService
    {

        [WebMethod(MessageName = "Add", Description = "Возвращает значение суммы двух параметров")]
        public int Add(int x, int y)
        {
            return x + y;
        }

        [WebMethod(MessageName = "Concat", Description = "Возвращает конкатенацию первого и второго параметров ")]
        public string Concat(string s, double d)
        {
            return $"{s}{d}";
        }

        [WebMethod(MessageName = "Sum", Description = "Сумма двух объектов A")]
        public A Sum(A a1, A a2)
        {
            var result = new A(a1.s + a2.s, a1.k + a2.k, a1.f + a2.f);
            return result;
        }

        [ScriptMethod(ResponseFormat = ResponseFormat.Json)]
        [WebMethod()]
        public string AddS(string req)
        {
            dynamic jsonObject = Newtonsoft.Json.JsonConvert.DeserializeObject(req);

            int x = jsonObject.x;
            int y = jsonObject.y;

            var result = new
            {
                sumres = x + y
            };

            return Newtonsoft.Json.JsonConvert.SerializeObject(result);
        }
    }

    public class A
    {
        public string s;
        public int k;
        public float f;

        public A()
        {
        }

        public A(string v1, int v2, float v3)
        {
            s = v1;
            k = v2;
            f = v3;
        }
    }
}
