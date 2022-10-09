using System;
using System.Collections.Generic;
using System.Drawing;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using static Set;
using static System.Net.Mime.MediaTypeNames;


public class Set
{
    public class Production
    {
        public int Id { get; set; }
        public string? OrganizationName { get; set; }
    }

    public class Developer
    {
        public string? FullName { get; set; }
        public int? Id { get; set; }
        public string? Department { get; set; }

    }

    public List<int> numbers = new List<int>();

    public Set()
    {
        numbers.Add(0);
    }
    public Set(List<int>numbers)
    {
        this.numbers = numbers;
    }
    public static Set operator ++(Set set)
    {
        Random rnd = new Random();
        set.numbers.Add(rnd.Next(0, 10));
        return set;
    }
    public static Set operator --(Set set)
    {
        set.numbers.Remove(set.numbers.Last());
        return set;
    }
    public static Set operator +(Set set, Set set2)
    {
        foreach (int i in set2.numbers)
        {
            set.numbers.Add(i);
        }
        return set;
    }
    public static bool operator >=(Set set, Set set2)
    {
        if (set.numbers.Count >= set2.numbers.Count)
        {
            return true;
        }
        return false;
    }
    public static bool operator <=(Set set, Set set2)
    {
        if (set.numbers.Count <= set2.numbers.Count)
        {
            return true;
        }
        return false;
    }

    public static implicit operator int(Set set)
    {
        return set.numbers.Count;
    }
    public static int operator %(Set set , int i)
    {
        return set.numbers[i];
    }
    public void PrintSet()
    {
        foreach (int i in numbers)
        {
            Console.Write($"{i} ");
        }
        Console.WriteLine();
    }
}

static class StatisticOperation
{
    public static Set SetSubtraction(Set set, Set set2)
    {
        for (int i = 0; i < set2.numbers.Count; i++)
        {
            if (set.numbers.Contains(set2.numbers[i]))
            {
                set.numbers.Remove(set2.numbers[i]);
            }
        }
        return set;
    }

    public static bool CheckingForTheOrderOfaSet(Set set)
    {
        for (int i = 0; i < set.numbers.Count; i++)
        {
            if (set.numbers[i] > set.numbers[i + 1])
            {
                return false;
            }
        }
        return true;
    }

    public static StringBuilder EncryptionStr(String str)
    {
        StringBuilder sb = new StringBuilder();
        for (int x = 0; x < str.Length; x++)
        {
            sb.Append((char)(str[x] + 1));
        }
        return sb;
    }
}
class Program
{    static void Main(string[] args)
    {
        Set set = new Set();

        Console.Write($"множество до ++ - ");
        set.PrintSet();

        set++;

        Console.Write($"множество после ++ - ");
        set.PrintSet();

        Set set2 = new Set();   
        Console.Write($"множество2 - ");
        set2.PrintSet();

        set2 = set2 + set;
        Console.Write($"множество2 + множество - ");
        set2.PrintSet();

        Console.WriteLine($"множество >= множество2 - {set >= set2} \nмножество <= множество2 - {set <= set2}");

        Console.WriteLine($"Мощность множества множество - {(int)set}");

        Console.WriteLine($"Элемент множества - {set%1}");


        List<int> numbers_ = new List<int>() { 1, 2, 4, 3, 4};
        Set set3 = new Set(numbers_);
        Console.WriteLine(SetExtension.CheckingForTheOrderOfaSet(set3));

        string str = "test";

        Console.WriteLine(SetExtension.EncryptionStr(str));

        Set.Production production = new Set.Production();
        production.Id = 1;
        production.OrganizationName = "Norm";
        Console.WriteLine($"{production.Id}. {production.OrganizationName}");

        Set.Developer developer = new Set.Developer();
        developer.Id = 1;
        developer.FullName = "Mikita Koukel Viktaravich";
        developer.Department = "Dom";
        Console.WriteLine($"{developer.Id}. {developer.FullName} {developer.Department}");

        List<int> numbers_1 = new List<int>() { 1, 2, 3, 4 };
        Set set4 = new Set(numbers_1);

        List<int> numbers_2 = new List<int>() { 3, 4, 5, 6, 7 };
        Set set5 = new Set(numbers_2);

        StatisticOperation.SetSubtraction(set4, set5).PrintSet();
    }
}
