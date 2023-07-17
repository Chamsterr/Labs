using Lab_19_20_OOP;
using System;
using System.Diagnostics.Metrics;
using System.Numerics;
using System.Threading;

namespace Lab_19_20_OOP
{
    public class TelephoneExchange : ITelephoneExchange
    {
        public readonly string title;
        public Administrator Administrator { get; set; }
        List<Subsriber> SubsribersList = new List<Subsriber>();
        public Sandwich? sandwich;
        public CompanyDirector companyDirector;
        public Cleaner Cleaner;
        public TelephoneExchange(string title, string AdministratorName, CompanyDirector companyDirector)
        {
            this.title = title;
            Administrator = Administrator.getInstance(AdministratorName);
            sandwich = null;
            this.companyDirector = companyDirector;
        }
        public void AddSubscriber(Subsriber subsriber)
        {
            SubsribersList.Add(subsriber);
        }
        public void GetInfo()
        {
            Console.WriteLine("|----------------------------------------------------|");

            if (sandwich != null)
            {

                Console.BackgroundColor = ConsoleColor.Gray;
                Console.ForegroundColor = ConsoleColor.Black;
                Console.WriteLine($"Хлеб: {sandwich.compound}");
                Console.ResetColor();
            }
            Console.WriteLine($"Станция {title}, администратор {Administrator.Name}");
            if (SubsribersList != null)
                foreach (Subsriber subscriber in SubsribersList)
                    Console.WriteLine($"Абноент ID: {subscriber.ToString()}");
            else
                Console.WriteLine("Нет абонентов");
            Console.WriteLine("|----------------------------------------------------|");
        }
        public ITelephoneExchange Clone()
        {
            return new TelephoneExchange(this.title, this.Administrator.Name, this.companyDirector);
        }
        public void CheckSubByID(int _id)
        {
            foreach (Subsriber subscriber in SubsribersList)
            {
                if (subscriber.GetID() == _id)
                {
                    if (Administrator.CheckSub(subscriber))
                    {
                        Console.WriteLine($"У абонента(ID: {subscriber.GetID()}) счет не превышает 200");
                    }
                    else
                    {
                        Console.WriteLine($"У абонента(ID: {subscriber.GetID()}) счет превышает 200");
                    }
                    break;
                }
            }
        }
        public void EatSandwich()
        {
            if (sandwich != null)
            {
                Console.WriteLine("Сьел бутерброд.");
                sandwich = null;
            }
            else Console.WriteLine("Бутерброда нет.");
        }
        public void DirectorWork()
        {
            companyDirector.DoWork();
            companyDirector.GiveMoney();
        }
    }
    public class Program
    {
        public static void Main()
        {
            // Декоратор (Decorator)
            // Мост (Bridge)

            // создаем доброго директора
            CompanyDirector goodDirector = new GoodCompanyDirector(new EnglishLanguage());

            // создаем доброго директора
            CompanyDirector badDirector = new BadCompanyDirector(new RussianLanguage());

            // содаем объект пекаря
            Baker baker = new Baker();
            // создаем билдер для ржаного хлеба
            BreadBuilder builder = new RyeBreadBuilder();
            // выпекаем
            Bread ryeBread = baker.Bake(builder);
            // оздаем билдер для пшеничного хлеба
            builder = new WheatBreadBuilder();
            Bread wheatBread = baker.Bake(builder);

            Sandwich sandwich1 = new RyeBreadSandwich(ryeBread);
            sandwich1 = new CheeseSandwich(sandwich1);

            Sandwich sandwich2 = new WheatBreadSandwich(wheatBread);
            sandwich2 = new CheeseSandwich(sandwich2);
            sandwich2 = new MeatSandwich(sandwich2);


            Service SMS = new SMS();
            Service VideoCall = new VideoCall();
            TelephoneExchange telephoneExchange = new TelephoneExchange("Velcom", "Петя", goodDirector);
            Subsriber subsriber3G = new Subsriber(new Subsriber3GFactory(), 476, new Call440HZ());
            subsriber3G.Call();
            subsriber3G.Callable = new Call650HZ();
            subsriber3G.Call();
            telephoneExchange.AddSubscriber(subsriber3G);
            subsriber3G.AddService(SMS);
            subsriber3G.UseServices();
            telephoneExchange.sandwich = sandwich1;
            telephoneExchange.CheckSubByID(476);

            subsriber3G.SendMessage(Country.Poland);

            telephoneExchange.Cleaner = new Cleaner(new AngerState());
            telephoneExchange.Cleaner.Cleaning(Purity.Purely);
            telephoneExchange.Cleaner.Cleaning(Purity.Purely);
            telephoneExchange.Cleaner.Cleaning(Purity.Dirty);
            telephoneExchange.Cleaner.Cleaning(Purity.Dirty);

            Subsriber subsriber4G = new Subsriber(new Subsriber4GFactory(), 798, new Call440HZ());
            telephoneExchange.AddSubscriber(subsriber4G);
            subsriber4G.AddService(VideoCall);
            subsriber4G.UseServices();
            telephoneExchange.DirectorWork();
            // директору надо поговорить с русскими
            telephoneExchange.companyDirector.Language = new RussianLanguage();
            telephoneExchange.DirectorWork();
            telephoneExchange.GetInfo();

            telephoneExchange.EatSandwich();
            telephoneExchange.EatSandwich();

            TelephoneExchange telephoneExchange3 = new TelephoneExchange("Velcom", "Петя", badDirector);
            telephoneExchange3.sandwich = sandwich2;
            telephoneExchange3.DirectorWork();

            ITelephoneExchange TelephoneExchange2 = new TelephoneExchange("MTC", "Вася", badDirector);
            TelephoneExchange2.GetInfo();
            ITelephoneExchange clonedTelephoneExchange2 = TelephoneExchange2.Clone();
            clonedTelephoneExchange2.GetInfo();

        }
    }
}