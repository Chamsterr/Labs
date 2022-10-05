using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

class Program
{
    struct Point
    {
        public int x, y;
        public override string ToString()
        {
            return x.ToString() + y.ToString();
        }
    }
    static void Main(string[] args)
    {
        Point obj = new Point(); //1
        System.Console.WriteLine(obj); //2
    }
}