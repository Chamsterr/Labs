using System;
using System.ComponentModel;
using System.IO;
using System.Reflection.PortableExecutable;
using System.Text;
using System.Text.Json;
using static System.Net.Mime.MediaTypeNames;

interface I<T>
{
    void Add(T item);
    void Remove(T item);

    List<T> FindGreater(T x);
    List<T> FindLess(T x);
}


public class Set<T> : I<T>
{
    public List<T> numbers = new List<T>();

    public Set()
    {
        numbers = new List<T>();
    }
    public void Add(T item)
    {
        numbers.Add(item);
    }
    public void Remove(T item)
    {
        numbers.Remove(item);
    }
    public List<T>? FindGreater(T x)
    {
        List<T>? answers = new List<T>() ;
        for (int i = 0; i < numbers.Count; i++)
        {
            int? var;
            int? nextVar;

            if (numbers[i] is int)
            {
                var = numbers[i] as int?;
                nextVar = x as int?;
            }
            else if (numbers[i] is char)
            {
                var = numbers[i] as char?;
                nextVar = x as char?;
            }
            else
            {
                throw new WrongType("FindGreater работает только для типвов char и int");
                return answers;
            }

            if (var > nextVar)
            {
                answers.Add(numbers[i]);
            }
         }
            return answers;
    }

    public List<T>? FindLess(T x)
    {
        List<T>? answers = new List<T>();
        for (int i = 0; i < numbers.Count; i++)
        {
            int? var;
            int? nextVar;

            if (numbers[i] is int)
            {
                var = numbers[i] as int?;
                nextVar = x as int?;
            }
            else if (numbers[i] is char)
            {
                var = numbers[i] as char?;
                nextVar = x as char?;
            }
            else
            {
                throw new WrongType("FindLess работает только для типвов char и int");
                return answers;
            }

            if (var < nextVar)
            {
                answers.Add(numbers[i]);
            }
        }
        return answers;
    }
    public Set(List<T> numbers)
    {
        this.numbers = numbers;
    }

    public static Set<T> operator +(Set<T> set, Set<T> set2)
    {
        foreach (T i in set2.numbers)
        {
            set.numbers.Add(i);
        }
        return set;
    }
    public static bool operator >=(Set<T> set, Set<T> set2)
    {
        if (set.numbers.Count >= set2.numbers.Count)
        {
            return true;
        }
        return false;
    }
    public static bool operator <=(Set<T> set, Set<T> set2)
    {
        if (set.numbers.Count <= set2.numbers.Count)
        {
            return true;
        }
        return false;
    }

    public static implicit operator int(Set<T> set)
    {
        return set.numbers.Count;
    }
    public static T operator %(Set<T> set, int i)
    {
        return set.numbers[i];
    }
    public void PrintSet()
    {
        foreach (T i in numbers)
        {
            Console.Write($"{i} ");
        }
        Console.WriteLine();
    }

    public List<T>? Check(T x)
    {
        throw new NotImplementedException();
    }

    public void Write(string filename)
    {
        using (StreamWriter writer = new StreamWriter(filename, false))
        {
            writer.WriteLineAsync($"Set - {this.ToString()}, кол-во: {this.numbers.Count}");
        }
    }

    public void Read(string filename)
    {
        using (StreamReader reader = new StreamReader(filename))
        {
            string text = reader.ReadToEnd();
            Console.WriteLine(text);
        }
    }
}

public class QuestionsList<T> where T: Question 
{
    public List<T> list = new List<T>();
    public QuestionsList()
    {
        list = new List<T>();
    }
    public void Add(T item)
    {
        list.Add(item);
    }
}

class Program
{
    static void Main(string[] args)
    {
        Set<int> set = new Set<int>();
        set.Add(1);
        set.Add(2);
        set.Add(3);

        foreach (int i in set.FindGreater(1))
        {
            Console.WriteLine(i);
        }

        Console.WriteLine("---------------------------------");
        foreach (int i in set.FindLess(4))
        {
            Console.WriteLine(i);
        }

        Set<char> set_str = new Set<char>();
        set_str.Add('a');
        set_str.Add('b');
        set_str.Add('c');

        Console.WriteLine("---------------------------------");
        foreach (char i in set_str.FindGreater('a'))
        {
            Console.WriteLine(i);
        }

        Console.WriteLine("---------------------------------");
        foreach (char i in set_str.FindLess('c'))
        {
            Console.WriteLine(i);
        }
        set.Write("log.txt");
        set.Read("log.txt");
        Console.WriteLine();
    }
}