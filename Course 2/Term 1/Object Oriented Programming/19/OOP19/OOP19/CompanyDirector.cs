using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_19_20_OOP
{


    public interface ILanguage
    {
        void Talk();
    }

    public class EnglishLanguage : ILanguage
    {
        public void Talk()
        {
            Console.WriteLine("Поговорил на английском");
        }
    }

    public class RussianLanguage : ILanguage
    {
        public void Talk()
        {
            Console.WriteLine("Поговорил на русском");
        }

    }

    public abstract class CompanyDirector
    {
        protected ILanguage language;
        public ILanguage Language
        {
            set { language = value; }
        }
        public CompanyDirector(ILanguage lang)
        {
            language = lang;
        }
        public virtual void DoWork()
        {
            language.Talk();
        }
        public abstract void GiveMoney();
    }

    public class GoodCompanyDirector : CompanyDirector
    {
        public GoodCompanyDirector(ILanguage lang) : base(lang)
        {
        }
        public override void GiveMoney()
        {
            Console.WriteLine("Директор выдает зарплату сразу");
        }
    }
    public class BadCompanyDirector : CompanyDirector
    {
        public BadCompanyDirector(ILanguage lang)
            : base(lang)
        {
        }
        public override void GiveMoney()
        {
            Console.WriteLine("Директор говорит, что зарплата задерживается на 10 лет");
        }
    }
}