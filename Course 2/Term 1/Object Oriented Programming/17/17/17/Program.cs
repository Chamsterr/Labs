//Телефонная станция.Администратор осуществляет подключение
//Абонентов.Абонент может выбрать одну или несколько из
//предоставляемых Услуг.Абонент оплачивает Счет за разговоры и Услуги.
//Администратор может просмотреть список неоплаченных Счетов и
//заблокировать Абонента.
using System.Threading;

namespace Lab_17_18_OOP
{
    public class TelephoneExchange : ITelephoneExchange
    {
        public readonly string title;
        public Administrator Administrator { get; set; }
        List<Subsriber> SubsribersList = new List<Subsriber>();
        public Bread bread;
        public TelephoneExchange(string title, string AdministratorName)
        {
            this.title = title;
            Administrator = Administrator.getInstance(AdministratorName);
        }
        public void AddSubscriber(Subsriber subsriber)
        {
            SubsribersList.Add(subsriber);
        }
        public void GetSubscribers()
        {
            if (bread != null)
                Console.WriteLine($"Хлеб: {bread.ToString()}");
            Console.WriteLine($"Станция {title}, администратор {Administrator.Name}");
            if (SubsribersList != null)
                foreach (Subsriber subscriber in SubsribersList)
                    Console.WriteLine($"{subscriber.ToString()}");
            else
                Console.WriteLine("Нет абонентов");
        }
        public ITelephoneExchange Clone()
        {
            return new TelephoneExchange(this.title, this.Administrator.Name);
        }
    }
    public class Program
    {
        public static void Main()
        {
            // содаем объект пекаря
            Baker baker = new Baker();
            // создаем билдер для ржаного хлеба
            BreadBuilder builder = new RyeBreadBuilder();
            // выпекаем
            Bread ryeBread = baker.Bake(builder);
            Console.WriteLine(ryeBread.ToString());
            // оздаем билдер для пшеничного хлеба
            builder = new WheatBreadBuilder();
            Bread wheatBread = baker.Bake(builder);
            Console.WriteLine(wheatBread.ToString());

            Service SMS = new SMS();
            Service VideoCall = new VideoCall();
            TelephoneExchange telephoneExchange = new TelephoneExchange("Velcom", "Петя");
            Subsriber subsriber3G = new Subsriber(new Subsriber3GFactory(), 476);
            telephoneExchange.AddSubscriber(subsriber3G);
            subsriber3G.AddService(SMS);
            subsriber3G.UseServices();
            telephoneExchange.bread = wheatBread;

            Subsriber subsriber4G = new Subsriber(new Subsriber4GFactory(), 798);
            telephoneExchange.AddSubscriber(subsriber4G);
            subsriber4G.AddService(VideoCall);
            subsriber4G.UseServices();

            telephoneExchange.GetSubscribers();


            ITelephoneExchange TelephoneExchange2 = new TelephoneExchange("MTC", "Вася");
            ITelephoneExchange clonedTelephoneExchange2 = TelephoneExchange2.Clone();
            clonedTelephoneExchange2.GetSubscribers();

            Console.ReadLine();
        }
    }

}