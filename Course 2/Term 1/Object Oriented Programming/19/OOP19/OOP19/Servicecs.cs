using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_19_20_OOP
{
    //абстрактный класс - услуга
    public abstract class Service
    {
        public int total { get; set; }
        public Service(int sum)
        {
            total = sum;
        }
        public abstract void DoService();
    }

    // класс видео звонок
    public class VideoCall : Service
    {
        public VideoCall() : base(75) { }
        public override void DoService()
        {
            Console.WriteLine("Сделан видео звонок");
        }
    }
    // класс SMS
    public class SMS : Service
    {

        public SMS() : base(30) { }
        public override void DoService()
        {
            Console.WriteLine("Отправлено смс");
        }
    }
}