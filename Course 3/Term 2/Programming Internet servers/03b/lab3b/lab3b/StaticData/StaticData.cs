using lab7.Models;

namespace lab7.StaticData;

public static class StaticData
{
    public static List<User> users = new()
    {
        new User() { Email = "admin@gmail.com", Password = "123456QWERTYa!", Roles = new[] { Roles.Administrator } },
    };
}