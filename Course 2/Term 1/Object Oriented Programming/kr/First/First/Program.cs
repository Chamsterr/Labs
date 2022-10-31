using System;
using System.Text;
using System.Globalization;
using System.Linq;
using System.Reflection.Metadata.Ecma335;

namespace First
{
    interface IPossible
    {
        bool Check();
    }
    partial class Student:IPossible
    {
        private string nameBase = "";
        private int courseBase = 0;
        private int groupBase = 0;
 
        public Student()
        {
            name = "Ivan";
            grupa = 1;
            course = 1;
        }
        public Student(string name, int course, int grupa)
        {
            this.name = name;
            this.course = course;
            this.grupa = grupa;
        }
        public bool Check() 
        {
            if (this.name.Length > 50)
            {
                Console.WriteLine("Имя больше 50");
                return false;
            }
            Console.WriteLine("Имя не больше 50");
            return true;
        }
        public string name
        {
            set
            {
                if (value[0] != value.ToUpper()[0])
                    Console.WriteLine("Имя должно начинаться с большой буквы");
                else
                {
                    Console.WriteLine("Все норм");
                    nameBase = value;
                }
            }

            get
            {
                return nameBase;
            }
        }
        public int course
        {
            set
            {
                if (value > 4 || value < 1)
                    Console.WriteLine("Неверно выбран курс");
                else
                {
                    Console.WriteLine("Все норм");
                    courseBase = value;
                }
            }

            get
            {
                return courseBase;
            }
        }
        public int grupa
        {
            set
            {
                if (value < 1 || value > 10)
                    Console.WriteLine("Выберите группу от 1-10");
                else
                {
                    Console.WriteLine("Все норм");
                    groupBase = value;
                }
            }

            get
            {
                return groupBase;
            }
        }

    }
    class Program
    {
        static void Taks1()
        {
            Console.WriteLine(2_147_483_647);
            Console.WriteLine(-3.4E+38);

            string[,] arr1 = new string[2, 3] { { "1", "2", "3" }, { "4", "5", "6" } };
            for (int i = 0; i < arr1.GetLength(0); i++)
            {
                for (int j = 0; j < arr1.GetLength(1); j++)
                {
                    Console.Write($"{arr1[i, j]} \t");
                }
                Console.WriteLine();
            }

        }
        static void Main(string[] args)
        {
            Taks1();

            Student stud1 = new Student("Bana", 1, 11);

            Student stud2 = new Student("Ban", 1, 11);

            Console.WriteLine(stud2 == stud1);
            Console.WriteLine(stud2.Equals(stud1));

            stud1.Check();

            Student stud3 = new Student("Bandddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddda", 1, 11);

            stud3.Check();

            Student[] students = new Student[] { stud1, stud3, stud2, new Student("Kola", 2, 5), new Student("Kata", 3, 5)};
        }

    }
}