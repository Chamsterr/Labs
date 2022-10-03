using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

public partial class Person
{
    public void Move()
    {
        Console.WriteLine("I am moving");
    }
}
class Test
{
    public int test;
    private Test()
    {
       test = 3;
    }
}
class House
{
    static int counter = 0;

    public readonly int id;
    public int apartmentNumber {get;set;}

    public int square { get; set; }
    public int floor { get; set; }
    public int numberOfRooms { get; set; }
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

    public House() {
        counter++;
        apartmentNumber = 1;
        square = 135;
        floor = 1;
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


    public void Overhaul(ref int lifetime, out int whenOverhaul)
    {
        whenOverhaul = lifetime - DateTime.Now.Year;
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

            House[] listOfHouses = new House[] { house, house2 };
            House[] listOfHousesThatHaveСertainApart = new House[10];

            listOfHouses[0] = house;
            listOfHouses[1] = house2;

            Console.Write("Введите количество квартир ");
            int? amount = Convert.ToInt32(Console.ReadLine());

            for (int i = 0; i < listOfHouses.Length; i++)
            {
                if (listOfHouses[i].numberOfRooms == amount)
                {
                    listOfHousesThatHaveСertainApart.Append(listOfHouses[i]);
                    Console.WriteLine(listOfHouses[i].adress + " " + listOfHouses[i].apartmentNumber);
                }
            }
            

        }
    }
}
