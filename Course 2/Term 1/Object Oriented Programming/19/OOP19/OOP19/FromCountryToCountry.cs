using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_19_20_OOP
{

    public enum Country
    {
        Belarus, France, Germany, Poland
    }
    public class FromCountryToCountry
    {
        public static void FromBelarusToCountry(Country country)
        {
            PostOfficeHandler belarus = new BelarusPostOfficeHandler();
            PostOfficeHandler france = new FrancePostOfficeHandler();
            PostOfficeHandler germany = new GermanyPostOfficeHandler();
            PostOfficeHandler poland = new PolandPostOfficeHandler();

            belarus.Successor = france;
            france.Successor = germany;
            germany.Successor = poland;

            belarus.Handle(country);
        }
    }
    public abstract class PostOfficeHandler
    {
        public PostOfficeHandler? Successor { get; set; }
        public abstract void Handle(Country country);
    }
    public class BelarusPostOfficeHandler : PostOfficeHandler
    {
        public override void Handle(Country country)
        {
            if (country == Country.Belarus)
                Console.WriteLine("Сообщение прибыло в Беларусь");
            else if (Successor is not null)
            {
                Console.WriteLine("Пролетаем Беларусь");
                Successor.Handle(country);
            }
        }
    }
    public class FrancePostOfficeHandler : PostOfficeHandler
    {
        public override void Handle(Country country)
        {
            if (country == Country.France)
                Console.WriteLine("Сообщение прибыло в Францию");
            else if (Successor is not null)
            {
                Console.WriteLine("Пролетаем Францию");
                Successor.Handle(country);
            }
        }
    }
    public class GermanyPostOfficeHandler : PostOfficeHandler
    {
        public override void Handle(Country country)
        {
            if (country == Country.Germany)
                Console.WriteLine("Сообщение прибыло в Германию");
            else if (Successor is not null)
            {
                Console.WriteLine("Пролетаем Германию");
                Successor.Handle(country);
            }
        }
    }
    public class PolandPostOfficeHandler : PostOfficeHandler
    {
        public override void Handle(Country country)
        {
            if (country == Country.Poland)
                Console.WriteLine("Сообщение прибыло в Польшу");
            else if (Successor is not null)
            {
                Console.WriteLine("Пролетаем Польшу");
                Successor.Handle(country);
            }
        }
    }
}