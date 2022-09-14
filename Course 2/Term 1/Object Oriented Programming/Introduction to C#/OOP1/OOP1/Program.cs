using System;
using System.Text;
using System.Globalization;

namespace OOP1
{
    class Program
    {
        static void Task1()
        {
            bool flag = true;
            byte byte_var = 35;
            sbyte signed_byte_var = -128;
            char letter = 'c';
            decimal demical_var = 1.5E6m;
            double double_var = 11.3D;
            float float_var = 3_000.5F;
            int int_var = 151;
            uint unsigned_int_var = 4_294_967_295;
            long long_var = 9_223_372_036_854_775_807;
            ulong unsigned_long_var = 18_446_744_073_709_551_615;
            short short_var = -32_768;
            ushort unsigned_short_var = 65_535;


            Console.Write("Enter boolean expression: ");
            flag = bool.Parse(Console.ReadLine());
            Console.WriteLine(flag);

            Console.Write("Enter byte variable: ");
            byte_var = byte.Parse(Console.ReadLine());
            Console.WriteLine(byte_var);

            Console.Write("Enter sbyte variable: ");
            signed_byte_var = sbyte.Parse(Console.ReadLine());
            Console.WriteLine(signed_byte_var);

            Console.Write("Enter char variable: ");
            letter = char.Parse(Console.ReadLine());
            Console.WriteLine(letter);

            Console.Write("Enter demical variable: ");
            demical_var = decimal.Parse(Console.ReadLine());
            Console.WriteLine(demical_var);

            Console.Write("Enter double variable: ");
            double_var = double.Parse(Console.ReadLine());
            Console.WriteLine(double_var);

            Console.Write("Enter float variable: ");
            float_var = float.Parse(Console.ReadLine());
            Console.WriteLine(float_var);

            Console.Write("Enter int variable: ");
            int_var = int.Parse(Console.ReadLine());
            Console.WriteLine(int_var);

            Console.Write("Enter unit variable: ");
            unsigned_int_var = uint.Parse(Console.ReadLine());
            Console.WriteLine(unsigned_int_var);

            Console.Write("Enter long variable: ");
            long_var = long.Parse(Console.ReadLine());
            Console.WriteLine(long_var);


            Console.Write("Enter ulong variable: ");
            unsigned_long_var = ulong.Parse(Console.ReadLine());
            Console.WriteLine(unsigned_long_var);

            Console.Write("Enter short variable: ");
            short_var = short.Parse(Console.ReadLine());
            Console.WriteLine(short_var);

            Console.Write("Enter ushort variable: ");
            unsigned_short_var = ushort.Parse(Console.ReadLine());
            Console.WriteLine(unsigned_short_var);

            byte a = 1;
            sbyte q = -1;

            ushort b = a;
            short w = q;
            int e = q;
            float r = q;
            double t = q;

            int y = 107;
            int u = 6;
            double g = 4.0;
            float j = 5.0F;

            byte i = (byte)(y + u);
            char o = (char)(y);
            decimal h = (decimal)g;
            decimal k = (decimal)j;
            int l = Convert.ToInt16(flag);

            // boxing
            int price = 39;
            Object obj = price;

            // unboxing
            int price2 = (int)obj;

            var z = 5;
            var x = "Hello";

            Console.WriteLine($"{z}, {x}");

            int? NullVariable = null;
            Console.WriteLine($"Null variable: {NullVariable}");

            // var test = 1;
            // test = 'test';
        }
        static void Task2()
        {
            string str1 = "I";
            string str2 = "L";
            string str3 = "OOP";

            int result = string.Compare(str1, str2);

            string str4 = str1 + " " + str2 + " " + str3;
            str4 = string.Concat(str4, "!!!");

            string str5 = string.Copy(str4);
            string str6 = str5.Substring(4, 3);
            Console.WriteLine(str6);
            Console.WriteLine($"{str1} {str2} {str3}");

            string str7 = null;
            string str8 = "";

            Console.WriteLine($"str7 = {string.IsNullOrEmpty(str7)} \nstr8 = {string.IsNullOrEmpty(str8)} \nstr7 == str8 = {str7 == str8}");
            StringBuilder strbl = new StringBuilder("123", 50);
            strbl.Append(new char[] { '4', '5', '6', '7' });
            strbl.AppendFormat("{0}{1}", '8', '9');

            char test = '0';
            strbl.AppendFormat($"{test}");

            Console.WriteLine($"Строка с помощью билдера: {strbl}");
            Console.WriteLine($"Удаляем 4, 5, 6: {strbl.Remove(3, 3)}");
            Console.WriteLine($"Вставляем '-' в начало строки: {strbl.Insert(0, '-')}");


        }
        static void Main(string[] args)
        {
            /*Task1();*/
            Task2();
            Console.ReadLine();
        }
    }
}