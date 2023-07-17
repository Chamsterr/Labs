using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace OOP14
{
    class Program
    {
        static void T1()
        {
            Process[] procList = Process.GetProcesses();
            foreach (Process proc in procList)
            {
                try
                {
                    Console.WriteLine(new string('-', 40));
                    Console.WriteLine($"Id: {proc.Id} \n" +
                                  $"Name: {proc.ProcessName}\n" +
                                  $"Priority: {proc.PriorityClass}\n" +
                                  $"Start time: {proc.StartTime}\n" +
                                  $"Responding: {proc.Responding}\n" +
                                  $"Process time: {proc.TotalProcessorTime}\n" +
                                  $"User Processor Time: {proc.UserProcessorTime}");
                }
                catch
                {
                }
            }
        }
        static void T2()
        {
            AppDomain domain = AppDomain.CurrentDomain;
            Console.WriteLine($"Имя домена: {domain.FriendlyName} \n" +
                              $"Базовый котолог: {domain.BaseDirectory} \n" +
                              $"Детали конфигурации: {domain.SetupInformation} \n");
            Assembly[] assemblies = domain.GetAssemblies();
            foreach (Assembly asm in assemblies)
                Console.WriteLine(asm.GetName().Name);

            //https://learn.microsoft.com/ru-ru/dotnet/fundamentals/syslib-diagnostics/syslib0024
/*            AppDomain newD = AppDomain.CreateDomain("SecondDomain");
            foreach (Assembly asm in assemblies)
                newD.Load(asm.GetName());*/
        }
        static void T3()
        {
            async void Task3_1(object? n)
            {
                using (FileStream fr = new FileStream("Task3.txt", FileMode.OpenOrCreate))
                {
                    for (int i = 0; i < (int)n; i++)
                    {
                        Console.WriteLine(i.ToString());
                        byte[] buffer = Encoding.Default.GetBytes(i.ToString() + " ");
                        await fr.WriteAsync(buffer, 0, buffer.Length);
                        Thread.Sleep(10);
                    }
                }
            }
            Thread Thread1 = new Thread(new ParameterizedThreadStart(Task3_1));

            Thread1.Start(100);
            Console.WriteLine("Thread Name: " + Thread1.Name);
            Console.WriteLine("Thread Priority: " + Thread1.Priority);
            Console.WriteLine("Thread ThreadState: " + Thread1.ThreadState);

        }
        static void T4()
        {
            var mutex = new Mutex();
            object Locker = new();

            async void Task4_1(object? obj)
            {
                if (obj != null)
                    lock (Locker) ;
                for (int i = 0; i < 30; i += 2)
                {
                    Console.WriteLine("Thread1: " + i.ToString());
                    if (obj == null)
                        mutex.WaitOne();
                    File.AppendAllText("Task4.txt", "Thread2: " + i.ToString() + "\n");
                    Thread.Sleep(10);
                    if (obj == null)
                        mutex.ReleaseMutex();
                }
            }
            async void Task4_2(object? obj)
            {
                for (int i = 1; i < 30; i += 2)
                {
                    if (obj == null)
                        mutex.WaitOne();
                    Console.WriteLine("Thread2: " + i.ToString());
                    File.AppendAllText("Task4.txt", "Thread2: " + i.ToString() + "\n");
                    Thread.Sleep(10);
                    if (obj == null)
                        mutex.ReleaseMutex();
                }
            }

            Thread Thread1_ii = new Thread(new ParameterizedThreadStart(Task4_1));
            Thread Thread2_ii = new Thread(new ParameterizedThreadStart(Task4_2));
            Thread1_ii.Start();
            Thread2_ii.Start();
            Thread1_ii.Join();
            Thread2_ii.Join();

/*          Thread1_ii.Start(100);
            Thread2_ii.Start(100);*/
            Thread2_ii.Priority = ThreadPriority.AboveNormal;
        }
        static void T5()
        {
            int num = 100;
            TimerCallback tm = new TimerCallback(GetPrice);
            Timer timer = new Timer(tm, num, 5000, 200);

        }
        public static void GetPrice(object obj)
        {
            Random rnd = new Random();
            int value = rnd.Next(-10, 10);
            Console.WriteLine((int)obj - value);
        }
        static void Main()
        {
            /*            T1();*/
            /*            T2();*/
            /*T3();*/
            /*            T4();*/
            T5();
            Console.ReadLine();
        }
    }
}
