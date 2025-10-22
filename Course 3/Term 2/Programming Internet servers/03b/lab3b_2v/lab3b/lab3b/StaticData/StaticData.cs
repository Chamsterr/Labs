using lab7.Models;

namespace lab7.StaticData;

public static class StaticData
{
    public static List<User> users = new()
    {
        new User() { Email = "Admin@admin.admin1", Password = "Admin@admin.admin1", Roles = new[] { Roles.Administrator } },
        new User() { Email = "Master@master.master1", Password = "Master@master.master1", Roles = new[] { Roles.Master } },
        new User() { Email = "Employee@employee.employee1", Password = "Employee@employee.employee1", Roles = new[] { Roles.Employee } },
    };
}