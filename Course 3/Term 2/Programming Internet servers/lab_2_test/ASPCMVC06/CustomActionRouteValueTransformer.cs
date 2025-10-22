using Microsoft.AspNetCore.Mvc.Routing;

namespace ASPCMVC06
{
    public class CustomRouteConstraint : IRouteConstraint
    {
        public bool Match(HttpContext httpContext, IRouter route, string routeKey, RouteValueDictionary values, RouteDirection routeDirection)
        {
            var action = values["action"] as string;
            var id = values["id"] as string;
            if (action == "M01")
            {
                return id == "1";
            }
            else if (action == "M02")
            {
                return string.IsNullOrEmpty(id);
            }
            return false;
        }
    }

    public class CustomRouteConstraint2 : IRouteConstraint
    {
        public bool Match(HttpContext httpContext, IRouter route, string routeKey, RouteValueDictionary values, RouteDirection routeDirection)
        {
            foreach (var item in values)
            {
                Console.WriteLine("item: " + item);
            }

            var action = values["action"] as string;
            var value = values["value"] as string;
            var controller = values["controller"] as string;
            Console.WriteLine("action: " + action);
            Console.WriteLine("value: " + value);

            if (action == "M03" && value == "")
            {
                Console.WriteLine("action: " + action);
                Console.WriteLine("value: " + value);
                Console.WriteLine("controller: " + controller);


                Console.WriteLine(controller);

                Console.WriteLine(1);
                return false;
            }


            
            return true;
        }
    }
}
