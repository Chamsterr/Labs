using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_17_18_OOP
{
    // класс абстрактной фабрики
    public abstract class SubsriberFactory
    {
        public abstract string CreateService();
    }

    public class Subsriber3GFactory : SubsriberFactory
    {
        public override string CreateService()
        {
            return "3G";
        }
    }
    public class Subsriber4GFactory : SubsriberFactory
    {
        public override string CreateService()
        {
            return "4G";
        }
    }

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
            Console.WriteLine($"Абонент #{_id}, типа {typeWIC} на связи");
            if (services != null)
                foreach (Service service in services)
                    service.DoService();
            else
                Console.WriteLine("Услуги не подключены");
        }
        public override string ToString()
        {
            return Convert.ToString(_id);
        }
    }
}