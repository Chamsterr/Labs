using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

class Test
{
    public int test;
    private Test()
    {
        test = 3;
    }
}
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
            if (value <= 1 || value >= 300)
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
    private string buildingType { get; set; }
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
        return $"{adress}";
    }
}


namespace OOP2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            House.PrintInfoAboutClass();

            House house = new House(1, 2, "Tihay", "semi detached");
            house.WriteStreet();
            int lifetimeH1 = house.lifetime;
            int whenOverhaulH1;
            house.Overhaul(ref lifetimeH1, out whenOverhaulH1);
            Console.WriteLine($"Капитальный ремонт через: {whenOverhaulH1} \n");

            House house2 = new House();
            house2.WriteStreet();
            int lifetimeH2 = house2.lifetime;
            int whenOverhaulH2;
            house2.Overhaul(ref lifetimeH2, out whenOverhaulH2);
            Console.WriteLine($"Капитальный ремонт через: {whenOverhaulH2} \n");

            Console.WriteLine(house.ToString());
            Console.WriteLine(house.Equals(house2));
            Console.WriteLine(house.GetType());

            House[]? listOfHouses = new House[] { house, house2 };
            List<House> listOfHousesThatHaveСertainRooms = new List<House>();

            List<House> listOfHousesThatHaveСertainRoomsInDist = new List<House>();

            listOfHouses[0] = house;
            listOfHouses[1] = house2;

            Console.WriteLine();
            Console.Write("Введите количество комнат: ");
            int? amount = Convert.ToInt32(Console.ReadLine());

            Console.Write("Введите нижнюю границу между этажами: ");
            int? distBetweenFloor1 = Convert.ToInt32(Console.ReadLine());


            Console.Write("Введите верхнию границу между этажами: ");
            int? distBetweenFloor2 = Convert.ToInt32(Console.ReadLine());

            for (int i = 0; i < listOfHouses.Length; i++)
            {
                if (listOfHouses[i].numberOfRooms == amount)
                {
                    listOfHousesThatHaveСertainRooms.Add(listOfHouses[i]);
                }

                if (listOfHouses[i].numberOfRooms == amount && distBetweenFloor1 <= listOfHouses[i].floor && listOfHouses[i].floor <= distBetweenFloor2)
                {
                    listOfHousesThatHaveСertainRoomsInDist.Add(listOfHouses[i]);
                }
            }

            if (listOfHousesThatHaveСertainRooms.Count == 0)
            {
                Console.WriteLine("Таких квартир нет");
            }
            else
            {
                Console.WriteLine("Комнаты которые имеют заданное число комнат:");
            }

            for (int i = 0; i < listOfHousesThatHaveСertainRooms.Count; i++)
            {
                if (listOfHousesThatHaveСertainRooms[i] != null)
                {
                    Console.WriteLine(listOfHousesThatHaveСertainRooms[i].adress + " " + listOfHousesThatHaveСertainRooms[i].apartmentNumber);
                }
            }

            if (listOfHousesThatHaveСertainRoomsInDist.Count == 0)
            {
                Console.WriteLine("Таких квартир нет ");
            }
            else
            {
                Console.WriteLine("Комнаты которые имеют заданное число комнатна на заданном промежутке:");
            }

            for (int i = 0; i < listOfHousesThatHaveСertainRoomsInDist.Count; i++)
            {
                if (listOfHousesThatHaveСertainRooms[i] != null)
                {
                    Console.WriteLine(listOfHousesThatHaveСertainRoomsInDist[i].adress + " " + listOfHousesThatHaveСertainRoomsInDist[i].apartmentNumber);
                }
            }

            var house3 = new { id = 13, apartmentNumber = 24, square = 34, floor = 4, numberOfRooms = 3, adress = "Gastello", buildingType = "flat", lifetime = 2027 };

            Console.WriteLine($" \nId - {house3.id} \n" +
                              $"Номер квартиры - {house3.apartmentNumber} \n" +
                              $"Площадь - {house3.square} \n" +
                              $"Этаж - {house3.floor}  \n" +
                              $"Количество комнат - {house3.numberOfRooms}  \n" +
                              $"Улица - {house3.adress}  \n" +
                              $"Тип здания - {house3.buildingType}  \n" +
                              $"Cрок эксплуатации до {house3.lifetime}");
        }
    }
}