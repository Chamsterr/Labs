
using Microsoft.VisualBasic;
using System;
using System.Net.Sockets;

delegate void DrSayUP();

class Dressirovchik
{
    public event DrSayUP SaidUp;

    public void UP()
    {
        Console.WriteLine("Дрессировщик: UP!");
        SaidUp?.Invoke();
    }
}

class Horse
{
    string _name;
    public Horse(string name)
    {
        _name = name;
    }

    public void DoUp()
    {
        Console.WriteLine($"{_name} *встает на дыбы*");
    }

}
class SuperLinkedList<T> : LinkedList<T>
{
    public new void Remove(T item)
    {
        if (!Contains(item))
            throw new Exception($"Элемента {item} нет в {this.ToString()}");
        Console.WriteLine($"Удаление {item} из {this.ToString()}");
        base.Remove(item);
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        Dressirovchik dressirovchik = new Dressirovchik(); 

        Horse horse = new Horse("Стрела");
        Horse horse1 = new Horse("Победа");
        Horse horse2 = new Horse("Непослушная лошадь");

        dressirovchik.SaidUp += horse.DoUp;
        dressirovchik.SaidUp += horse1.DoUp;
        

        dressirovchik.UP();
        Console.WriteLine();


        try
        {
            SuperLinkedList<string> sll = new SuperLinkedList<string>();
            sll.AddLast("hello");
            sll.AddFirst("hellow");
            sll.AddFirst("1234567");
            sll.AddFirst("123456");
            sll.AddFirst("12345");
            sll.AddFirst("1234");

            Console.WriteLine($"В {sll.ToString()} находится: ");
            foreach (string i in sll)
            {
                Console.WriteLine(i);
            }
            Console.WriteLine();

            sll.Remove("1234567");

            Console.WriteLine($"В {sll.ToString()} находится: ");
            foreach (string i in sll)
            {
                Console.WriteLine(i);
            }
            Console.WriteLine();

/*            sll.Remove("12345678");*/

            Console.WriteLine($"Элементы {sll.ToString()} длины строк которых < 6: ");
            var selectedSLL = from p in sll
                              where p.Length < 6
                              select p;

            foreach (string si in selectedSLL)
            {
                Console.WriteLine(si);
            }

        }
        catch (Exception e)
        {
            Console.WriteLine(e.Message);
        }

    }
}