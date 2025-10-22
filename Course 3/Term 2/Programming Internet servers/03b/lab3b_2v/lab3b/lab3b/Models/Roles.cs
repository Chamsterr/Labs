using System.Reflection;
namespace lab7.Models;

public static class Roles
{
    public const string Administrator = "Administrator";
    public const string Master = "Master";
    public const string Employee = "Employee";
    public static List<string> roles=new(){Administrator, Master, Employee};

   
}