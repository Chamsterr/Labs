using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.Serialization.Formatters.Soap;
using System.Text.Json;

namespace OOP13
{
    [Serializable]
    class Question
    {
        [NonSerialized]
        public int id = 1;
        public string question { get; set; }
        public string questionAnswer { get; set; }

        public Question()
        {
            question = questionAnswer = null;
        }
        public Question(string question, string questionAnswer)
        {
            this.question = question;
            this.questionAnswer = questionAnswer;
        }

        public override string ToString()
        {
            return question;
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            Question question = new Question("Как дела?", "Норм");

            //------------------------------Binary----------------------------------
            BinaryFormatter formatter = new BinaryFormatter();
            using (FileStream fs = new FileStream("question.dat", FileMode.OpenOrCreate))
            {
                formatter.Serialize(fs, question);
                Console.WriteLine("Объект сериализован");
            }

            using (FileStream fs = new FileStream("question.dat", FileMode.OpenOrCreate))
            {
                Question newQuestion = (Question)formatter.Deserialize(fs);

                Console.WriteLine("Объект десериализован");
                Console.WriteLine($"Вопрос: {newQuestion.question} Ответ: {newQuestion.questionAnswer}");
            }
            //----------------------------------------------------------------------

            //------------------------------Soap------------------------------------
            SoapFormatter formatterSoap = new SoapFormatter();
            using (FileStream fs = new FileStream("question.soap", FileMode.OpenOrCreate))
            {
                formatter.Serialize(fs, question);

                Console.WriteLine("Объект сериализован");
            }

            using (FileStream fs = new FileStream("question.soap", FileMode.OpenOrCreate))
            {
                Question newQuestion = (Question)formatter.Deserialize(fs);

                Console.WriteLine("Объект десериализован");
                Console.WriteLine($"Вопрос: {newQuestion.question} Ответ: {newQuestion.questionAnswer}");
            }
            //----------------------------------------------------------------------

            //------------------------------JSON------------------------------------
            using (FileStream fs = new FileStream("question.json", FileMode.OpenOrCreate))
            {
                JsonSerializer.SerializeAsync<Question>(fs, question);
                Console.WriteLine("Объект сериализован");
            }

            using (FileStream fs = new FileStream("question.json", FileMode.OpenOrCreate))
            {
                Question? newQuestion = JsonSerializer.DeserializeAsync<Question?>(fs);

                Console.WriteLine("Объект десериализован");
                Console.WriteLine($"Вопрос: {newQuestion.question} Ответ: {newQuestion.questionAnswer}");
            }
            //----------------------------------------------------------------------

            Console.ReadLine();
        }
    }
}
