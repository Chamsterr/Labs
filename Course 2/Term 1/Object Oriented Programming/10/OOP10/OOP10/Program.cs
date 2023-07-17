using System;
using System.ComponentModel;

partial class House
{
    int apartmentNumberBase = 1;
    int floorBase = 1;
    int squareBase = 1;
    int numberOfRoomsBase = 1;
    static int counter = 0;
    static int currentYear;


    public readonly int id;
    public int apartmentNumber
    {
        set
        {
            if (apartmentNumber < 0)
                Console.WriteLine("Номер квартиры должен быть положительный");
            else
                apartmentNumberBase = value;
        }

        get
        {
            return apartmentNumberBase;
        }
    }
    private int square
    {
        set
        {
            if (value <= 0)
                Console.WriteLine("Площадь должен быть положительной");
            else
                squareBase = value;
        }

        get
        {
            return squareBase;
        }
    }
    public int floor
    {
        set
        {
            if (value < 1 || value >= 300)
                Console.WriteLine("Этаж должен быть в диапозоне от 1 до 300");
            else
                floorBase = value;
        }

        get
        {
            return floorBase;
        }
    }
    public int numberOfRooms
    {
        set
        {
            if (numberOfRoomsBase > 1)
                Console.WriteLine("Количество комнат должно быть положительным: ");
            else
                numberOfRoomsBase = value;
        }

        get
        {
            return numberOfRoomsBase;
        }
    }
    public string adress { get; set; }
    public string buildingType { get; set; }
    public int lifetime { get; set; }



    public House(int floor, int numberOfRooms, string adress, string buildingType, int apartmentNumber = 2, int square = 135, int lifetime = 2025)
    {
        counter++;
        this.apartmentNumber = apartmentNumber;
        this.square = square;
        this.floor = floor;
        this.numberOfRooms = numberOfRooms;
        this.adress = adress;
        this.buildingType = buildingType;
        this.lifetime = lifetime;
        id = (apartmentNumber * adress.Length) / numberOfRooms * square / floor;
    }
    public House()
    {
        counter++;
        apartmentNumber = 1;
        square = 135;
        floor = 3;
        numberOfRooms = 1;
        adress = "Peresedenskay";
        buildingType = "mansion";
        lifetime = 2024;
        id = GetHashCode();
    }
    public House(int apartmentNumber, int square, int floor, int numberOfRooms, string adress, string buildingType)
    {
        counter++;
        this.apartmentNumber = apartmentNumber;
        this.square = square;
        this.floor = floor;
        this.numberOfRooms = numberOfRooms;
        this.adress = adress;
        this.buildingType = buildingType;
        id = GetHashCode();
    }
    static House()
    {
        currentYear = DateTime.Now.Year;
    }


    public void Overhaul(ref int lifetime, out int whenOverhaul)
    {
        whenOverhaul = lifetime - currentYear;
    }
    static public void PrintInfoAboutClass()
    {
        Console.WriteLine($"Это класс House\n");
    }
    public void WriteStreet()
    {

        Console.WriteLine($"Id - {id} \n" +
                          $"Номер квартиры - {apartmentNumber} \n" +
                          $"Площадь - {square} \n" +
                          $"Этаж - {floor}  \n" +
                          $"Количество комнат - {numberOfRooms}  \n" +
                          $"Улица - {adress}  \n" +
                          $"Тип здания - {buildingType}  \n" +
                          $"Cрок эксплуатации до {lifetime}");
    }


    public override int GetHashCode()
    {
        return (apartmentNumber * adress.Length) / numberOfRooms * square / floor;
    }
    public override bool Equals(object obj)
    {
        return false;
    }
    public override string ToString()
    {
        return $"{adress}" ;
    }
}

public class Person
{
    public string name;
    public string adress;
    public Person(string n, string ad)
    {
        name = n;
        adress = ad;
    }
}


class Program
{
    static void Main(string[] args)
    {
        string[] months = {"June", "July", "May", "December", "January", "August", "September", "October", "March", "April", "November", "February" };

        int lenght = Convert.ToInt32(Console.ReadLine());

        var selectedSLL = from p in months
                          where p.Length == lenght
                          select p;
        foreach (string si in selectedSLL)
        {
            Console.WriteLine(si);
        }
        Console.WriteLine("----------------------------");

        var winterAndSummer = months
             .Where(n => n == "June" || n == "July" || n == "August" || n == "December" || n == "January" || n == "February")
            .Select(n => n);
        foreach (string si in winterAndSummer)
        {
            Console.WriteLine(si);
        }
        Console.WriteLine("----------------------------");

        var orderedMonths = from p in months
                            orderby p
                            select p;
        foreach (string si in orderedMonths)
        {
            Console.WriteLine(si);
        }

        Console.WriteLine("----------------------------");
        var containsU = from p in months
                        where p.Contains('u') && p.Length > 4
                        select p;
        foreach (string si in containsU)
        {
            Console.WriteLine(si);
        }
        Console.WriteLine("----------------------------");

        Console.WriteLine("-------------Task2---------------");
        List<House> listOfHouses = new List<House>() 
        { 
            new House(5, 35, 4, 4, "Tichay", "flat"),
            new House(1, 55, 3, 1, "Sverdlova", "dom"),
            new House(25, 100, 3, 2, "Bobruyskay", "house"),
            new House(35, 25, 1, 1, "Bobruyskay", "flat"),
            new House(6, 45, 5, 2, "Sverdlova", "flat"),
            new House(5, 20, 1, 1, "Tichay", "flat"),
            new House(15, 25, 1, 3, "Ozernoe", "house"),
            new House(25, 35, 3, 4, "Ozernoe", "house"),
            new House(26, 65, 3, 4, "Bobruyskay", "flat"),
            new House(17, 37, 2, 3, "Ozernoe", "flat"),
            new House(5, 35, 4, 1, "Graznay", "house"),
        };

        var cuurentRooms = from p in listOfHouses
                           where p.numberOfRooms == 4
                           select p;
        foreach (object si  in cuurentRooms)
        {
            House? obj = si as House;
            Console.WriteLine($"{obj.apartmentNumber} {obj.adress} - кол-во комнат {obj.numberOfRooms}");
        }
        Console.WriteLine("----------------------------");


        var Street = listOfHouses.Where(p => (p.adress == "Tichay" && p.buildingType == "flat")).Take(5);

        foreach (object si in Street)
        {
            House? obj = si as House;
            Console.WriteLine($"{obj.apartmentNumber} {obj.adress} - кол-во комнат {obj.numberOfRooms}");
        }
        Console.WriteLine("----------------------------");


        var listOfflats = listOfHouses.Where(p => (p.numberOfRooms == 2 && (p.floor < 5 && p.floor > 1)));

        foreach (object si in listOfflats)
        {
            House? obj = si as House;
            Console.WriteLine($"{obj.apartmentNumber} {obj.adress} - кол-во комнат {obj.numberOfRooms}");
        }
        Console.WriteLine("----------------------------");

        List<Person> humans = new List<Person> { new Person("Nikita", "Tichay"), new Person("Nikita2", "Sverdlova") };

        List<House> listOfHouses2 = new List<House>()
        {
            new House(5, 35, 4, 4, "Tichay", "flat"),
            new House(1, 55, 3, 1, "Sverdlova", "dom")
        };
        var citezens = from c in humans
                       join p in listOfHouses2 on c.adress equals p.adress
                       select new { apartmentNumber = p.apartmentNumber, name = c.name, adress = p.adress };

        foreach (var obj in citezens) {
            Console.WriteLine($"{obj.name} живет на улице {obj.adress} {obj.apartmentNumber}");
        }
        Console.WriteLine("----------------------------");
    }
}