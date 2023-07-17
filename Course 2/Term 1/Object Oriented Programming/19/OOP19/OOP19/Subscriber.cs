using Lab_19_20_OOP;
using System;
using System.Collections.Generic;
using System.Data.SqlTypes;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_19_20_OOP
{
    // класс абстрактной фабрики
    public abstract class SubsriberFactory
    {
        public abstract string CreateService();
    }
    // Фабрика создания летящего героя с арбалетом
    public class Subsriber3GFactory : SubsriberFactory
    {
        public override string CreateService()
        {
            return "3G";
        }
    }
    // Фабрика создания бегущего героя с мечом
    public class Subsriber4GFactory : SubsriberFactory
    {
        public override string CreateService()
        {
            return "4G";
        }
    }
    // клиент - сам супергерой
    public class Subsriber
    {
        private List<Service> services = new List<Service>();
        private string typeWIC;
        private Bill bill;
        private int _id;
        public Subsriber(SubsriberFactory factory, int id)
        {
            bill = new Bill();
            bill.summa = 0;
            typeWIC = factory.CreateService();
            _id = id;
        }
        public Subsriber(SubsriberFactory factory, int id, ICallable call)
        {
            bill = new Bill();
            bill.summa = 0;
            typeWIC = factory.CreateService();
            _id = id;
            Callable = call;
        }
        public void AddService(Service service)
        {
            services.Add(service);
            bill.summa += service.total;
        }
        public int GetBill()
        {
            return bill.summa;
        }
        public void UseServices()
        {
            Console.Write($"Абонент #{_id}, типа ");
            if (typeWIC == "3G")
                Console.BackgroundColor = ConsoleColor.DarkCyan;
            if (typeWIC == "4G")
                Console.BackgroundColor = ConsoleColor.DarkGreen;
            Console.WriteLine($"{typeWIC} на связи");
            Console.ResetColor();
            if (services != null)
                foreach (Service service in services)
                    service.DoService();
            else
                Console.WriteLine("Услуги не подключены");
        }
        public int GetID()
        {
            return _id;
        }
        public override string ToString()
        {
            return Convert.ToString(_id);
        }

        public ICallable Callable { private get; set; }
        public void Call()
        {
            Console.Write($"Абонент #{_id}. ");
            Callable.Call();
        }
        public void SendMessage(Country country)
        {
            FromCountryToCountry.FromBelarusToCountry(country);
        }
    }
    //
    public interface ICallable
    {
        public void Call();
    }

    public class Call440HZ : ICallable
    {
        public void Call()
        {
            Console.WriteLine("Разговаривает на частоте 440HZ");
        }
    }

    class Call650HZ : ICallable
    {
        public void Call()
        {
            Console.WriteLine("Разговаривает на частоте 650HZ");
        }
    }
}