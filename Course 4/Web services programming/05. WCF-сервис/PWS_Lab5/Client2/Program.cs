using Client2.ServiceReference1;
using System;
using WCF;

namespace Client2
{
    class Program
    {
        static void Main(string[] args)
        {
            ServiceClient serviceClient = new ServiceClient();

            var sumResult = serviceClient.Sum(
                new A { s = "str", k = 12312, f = 1.112f },
                new A { s = "ing", k = 12132, f = 1.11f }
            );

            Console.WriteLine($"Result A:\ns = {sumResult.s}\nf = {sumResult.f}\nk = {sumResult.k}\n");
            Console.WriteLine($"Add: {sumResult.k} + 10 = " + serviceClient.Add(sumResult.k, 10) + "\n");
            Console.WriteLine($"Concat: {sumResult.s} + {sumResult.f} = " + serviceClient.Concat(sumResult.s, sumResult.f) + "\n");

            serviceClient.Close();
            
            Console.ReadKey();
        }
    }
}
