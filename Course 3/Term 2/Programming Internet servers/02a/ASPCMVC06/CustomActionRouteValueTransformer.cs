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

            Console.WriteLine("action: " + action);
            Console.WriteLine("value: " + value);

            if (action == "M03" && value == "")
            {
                return false;
            }

            /*if (action == "M01")
            {
                return true;
            }
            else if (action == "M02")
            {
                return true;
            }
            else if (action == "M03")
            {
                return true;
            }
            else if(action == "" && value == "")
            {
                return false;
            }
            return false;*/

            return true;
        }
    }
}
