using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Routing.Constraints;
using System;

namespace ASPCMVC06
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var builder = WebApplication.CreateBuilder(args);
            builder.Services.AddRazorPages();

            var app = builder.Build();
            if (!app.Environment.IsDevelopment())
            {
                app.UseExceptionHandler("/Error");
            }

            app.UseRouting();




            app.MapRazorPages();
#pragma warning disable ASP0014 
            app.UseEndpoints(endpoints =>
            {
                ///MResearch/M01/1
                ///MResearch/M01
                ///MResearch
                /// /
                ////MResearch/M02
                endpoints.MapControllerRoute(
                    name: "M01",
                    pattern: "/{MResearch?}/{action}/{id?}",
                    defaults: new { controller = "TMResearch", action = "M01" },
                    constraints: new { MResearch = "MResearch", action = "M01|M02", id = new CustomRouteConstraint() }
                    );

                ///V2/MResearch/M01
                ///V2
                ///V2/MResearch
                ///V2/MResearch/M02
                endpoints.MapControllerRoute(
                    name: "V2",
                    pattern: "V2/{MResearch?}/{action}",
                    defaults: new { controller = "TMResearch", action = "M02" },
                    constraints: new { action = "M01|M02", MResearch = "MResearch" }
                );

                ///V3/MResearch/string/M01
                ///V3/MResearch/string/M02
                ///V3
                ///V3/MResearch/string/
                ///V3/MResearch/string/M03
                endpoints.MapControllerRoute(
                    name: "V3",
                    pattern: "V3/{MResearch?}/{value}/{action}",
                    defaults:   new { controller = "TMResearch", action = "M03", value = "" },
                    constraints: new { action = "M01|M02|M03", MResearch = "MResearch", value = new CustomRouteConstraint2()}
                );

                endpoints.MapControllerRoute(
                     name: "MXX",
                     pattern: "{*url}",
                     defaults: new { controller = "TMResearch", action = "MXX" });
            });
#pragma warning restore ASP0014 // Suggest using top level route registrations

            app.Run();
        }

    }
}
