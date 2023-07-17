using System.Collections.Concurrent;
using System.Diagnostics;
using System.IO;
using System.Text;
using System.Threading.Tasks;
using static System.Net.Mime.MediaTypeNames;

namespace LW15
{
    class Product
    {
        public string Name { get; set; }
        public uint Price { get; set; }

        public Product(string name,
                       uint price)
        {
            Name = name;
            Price = price;
        }

        public Product()
        {
            Name = String.Empty;
            Price = 0;
        }

        public override string ToString() => $"Имя: {Name}, Цена: {Price}";
    }
    public class Program
    {
        public static void quest_1()
        {
            void Function()
            {
                int numb_one = 0;
                int numb_two = 1;
                int numb_three = 1;

                for (int i = 0; i < 1000; i++)
                {
                    for (int j = 0; j < 10000; j++)
                    {
                        //Console.WriteLine(i + " " + j);
                    }

                }
            }
            //Задание 1
            Task task1 = new Task(Function);

            Console.WriteLine("Begin");

            Stopwatch sw = new Stopwatch();
            sw.Start();
            task1.Start();

            Console.WriteLine("\ntask1.IsCompleted: " + task1.IsCompleted);
            Console.WriteLine("task1.Status: " + task1.Status);

            task1.Wait();

            sw.Stop();
            Console.WriteLine("\nпроизводительность выполнения: " + sw.ElapsedMilliseconds);

        }

        public static void quest_2()
        {

            //Создание токена для отмены
            CancellationTokenSource cancelTokenSource = new CancellationTokenSource();
            CancellationToken token = cancelTokenSource.Token;

            void Function()
            {
                int numb_one = 0;
                int numb_two = 1;
                int numb_three = 1;

                for (int i = 0; i < 1000; i++)
                {
                    for (int j = 0; j < 10000; j++)
                    {
                        //Console.WriteLine(i + " " + j);
                        Thread.Sleep(200);// если убрать будут проблемы с вхождением в блок с "операция прервана"
                        if (token.IsCancellationRequested)
                            break;
                    }
                    if (token.IsCancellationRequested)
                    {
                        Thread.Sleep(200);// если убрать будут проблемы с вхождением в блок с "операция прервана"
                        Console.WriteLine("Операция прервана");
                        Thread.Sleep(200);// если убрать будут проблемы с вхождением в блок с "операция прервана"
                        break;
                    }
                }
            }

            Task task2 = new Task(Function, token);
            Console.WriteLine("Begin");
            task2.Start();

            Thread.Sleep(1000);// если убрать будут проблемы с вхождением в блок с "операция прервана"
            // после задержки по времени отменяем выполнение задачи
            cancelTokenSource.Cancel();
            Thread.Sleep(2000);// если убрать будут проблемы с вхождением в блок с "операция прервана"
            task2.Wait();
            Console.WriteLine($"Task Status: {task2.Status}");
        }
        public static void quest_3()
        {
            int Sum(int a, int b) { return a + b; }
            int Subtraction(int a, int b) => a - b;
            int Division(int a, int b) => a / b;
            int Multiplication(int a, int b, int c) => a * b * c;

            Task<int> task1 = new Task<int>(() => Sum(4, 5));
            Task<int> task2 = new Task<int>(() => Subtraction(6, 3));
            Task<int> task3 = new Task<int>(() => Division(8, 4));
            Task<int> task4 = new Task<int>(() => Multiplication(task1.Result,
                                                                task2.Result,
                                                                task3.Result));

            task1.Start();
            task2.Start();
            task3.Start();

            task4.Start();

            Console.WriteLine(task4.Result);
        }
        public static void quest_4_1()
        {
            int Sum(int a, int b) { return a + b; }

            Task<int> task1 = new Task<int>(() => Sum(4, 5));
            Task task2 = task1.ContinueWith(task => Console.WriteLine(task1.Result));

            task1.Start();

            task2.Wait();//если это убрать в большинстве случаев не будет происходить выполнение таск2

        }
        public static void quest_4_2()
        {
            int Sum(int a, int b) { return a + b; }

            Task<int> task1 = new Task<int>(() => Sum(4, 5));

            task1.Start();
            task1.Wait();
            Console.WriteLine(task1.GetAwaiter().GetResult());

        }
        public static void quest_5_1()
        {
            Parallel.For(1, 100, Square);

            // вычисляем квадрат числа
            void Square(int n)
            {
                Console.WriteLine($"Выполняется задача {Task.CurrentId}");
                Console.WriteLine($"Квадрат числа {n} равен {n * n}");
                Thread.Sleep(2000);
            }
        }
        public static void quest_5_2()
        {
            ParallelLoopResult result = Parallel.ForEach<int>(
               new List<int>() { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 },
               Square
             );

            // вычисляем квадрат числа
            void Square(int n)
            {
                Console.WriteLine($"Выполняется задача {Task.CurrentId}");
                Console.WriteLine($"Квадрат числа {n} равен {n * n}");
                Thread.Sleep(2000);
            }
        }
        public static void quest_6()
        {
            int Sum(int a, int b) { Console.WriteLine(a + b); return a + b; }
            int Subtraction(int a, int b) { Console.WriteLine(a - b); return a - b; }
            int Division(int a, int b) { Console.WriteLine(a / b); return a / b; }
            Parallel.Invoke(() => Sum(1, 2), () => Subtraction(4, 2), () => Division(6, 3));
        }
        public static void quest_7()
        {
            BlockingCollection<Product> products = new();
            Task provider1 = new(() =>
            {
                int cnt = 0;
                while (cnt < 2 && products.TryAdd(new Product()))
                {
                    cnt++;
                    Console.WriteLine("Поставщик 1 добавил товар");
                    Thread.Sleep(170);
                }
            });
            Task provider2 = new(() =>
            {
                int cnt = 0;
                while (cnt < 2 && products.TryAdd(new Product()))
                {
                    cnt++;
                    Console.WriteLine("Поставщик 2 добавил товар");
                    Thread.Sleep(200);
                }
            });
            Task provider3 = new(() =>
            {
                int cnt = 0;
                while (cnt < 2 && products.TryAdd(new Product()))
                {
                    cnt++;
                    Console.WriteLine("Поставщик 3 добавил товар");
                    Thread.Sleep(600);
                }
            });
            Task provider4 = new(() =>
            {
                int cnt = 0;
                while (cnt < 2 && products.TryAdd(new Product()))
                {
                    cnt++;
                    Console.WriteLine("Поставщик 4 добавил товар");
                    Thread.Sleep(300);
                }
            });
            Task provider5 = new(() =>
            {
                int cnt = 0;
                while (cnt < 2 && products.TryAdd(new Product()))
                {
                    cnt++;
                    Console.WriteLine("Поставщик 5 добавил товар");
                    Thread.Sleep(250);
                }
            });

            Task client1 = new(() =>
            {
                Product prod = new();
                while (true)
                {
                    if (products.TryTake(out prod) && prod is not null)
                    {
                        Console.WriteLine("Клиент 1 забрал продукт");
                    }
                }
            });
            Task client2 = new(() =>
            {
                Product prod = new();
                while (true)
                {
                    if (products.TryTake(out prod) && prod is not null)
                    {
                        Console.WriteLine("Клиент 2 забрал продукт");
                    }
                }
            });
            Task client3 = new(() =>
            {
                Product prod = new();
                while (true)
                {
                    if (products.TryTake(out prod) && prod is not null)
                    {
                        Console.WriteLine("Клиент 3 забрал продукт");
                    }
                }
            });
            Task client4 = new(() =>
            {
                Product prod = new();
                while (true)
                {
                    if (products.TryTake(out prod) && prod is not null)
                    {
                        Console.WriteLine("Клиент 4 забрал продукт");
                    }
                }
            });
            Task client5 = new(() =>
            {
                Product prod = new();
                while (true)
                {
                    if (products.TryTake(out prod) && prod is not null)
                    {
                        Console.WriteLine("Клиент 5 забрал продукт");
                    }
                }
            });
            Task client6 = new(() =>
            {
                Product prod = new();
                while (true)
                {
                    if (products.TryTake(out prod) && prod is not null)
                    {
                        Console.WriteLine("Клиент 6 забрал продукт");
                    }
                }
            });
            Task client7 = new(() =>
            {
                Product prod = new();
                while (true)
                {
                    if (products.TryTake(out prod) && prod is not null)
                    {
                        Console.WriteLine("Клиент 7 забрал продукт");
                    }
                }
            });
            Task client8 = new(() =>
            {
                Product prod = new();
                while (true)
                {
                    if (products.TryTake(out prod) && prod is not null)
                    {
                        Console.WriteLine("Клиент 8 забрал продукт");
                    }
                }
            });
            Task client9 = new(() =>
            {
                Product prod = new();
                while (true)
                {
                    if (products.TryTake(out prod) && prod is not null)
                    {
                        Console.WriteLine("Клиент 9 забрал продукт");
                    }
                }
            });
            Task client10 = new(() =>
            {
                Product prod = new();
                while (true)
                {
                    if (products.TryTake(out prod) && prod is not null)
                    {
                        Console.WriteLine("Клиент 10 забрал продукт");
                    }
                }
            });

            provider1.Start();
            provider2.Start();
            provider3.Start();
            provider4.Start();
            provider5.Start();

            client1.Start();
            client2.Start();
            client3.Start();
            client4.Start();
            client5.Start();
            client6.Start();
            client7.Start();
            client8.Start();
            client9.Start();
            client10.Start();

            provider5.Wait();
        }
        public async static void quest_8()
        {
            using (FileStream fstream = new FileStream("file.txt", FileMode.OpenOrCreate))
            {
                // преобразуем строку в байты
                byte[] buffer = Encoding.Default.GetBytes("SomeText");
                // запись массива байтов в файл
                await fstream.WriteAsync(buffer, 0, buffer.Length);
            }
        }
        public static void Main()
        {
/*            quest_1();
            quest_2();
            quest_3();
            quest_4_1();
            quest_4_2();*/
            quest_5_1();
            quest_5_2();
/*            quest_6();
            quest_7();
            quest_8();*/
        }
    }
}
