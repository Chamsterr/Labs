using Lab_19_20_OOP;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_19_20_OOP
{
    public class Administrator
    {
        private static Administrator instance;

        public string Name { get; private set; }
        protected Administrator(string name)
        {
            this.Name = name;
        }

        public static Administrator getInstance(string name)
        {
            if (instance == null)
                instance = new Administrator(name);
            return instance;
        }
        public bool CheckSub(Subsriber subsriber)
        {
            if (subsriber.GetBill() > 200)
                return false;
            else
                return true;
        }
    }
}