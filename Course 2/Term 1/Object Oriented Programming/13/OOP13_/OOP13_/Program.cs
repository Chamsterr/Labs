using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.Serialization.Json;
using System.Xml.Linq;

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

            //------------------------------JSON------------------------------------
            using (FileStream fs = new FileStream("question.json", FileMode.OpenOrCreate))
            {
                DataContractJsonSerializer jsonForm = new DataContractJsonSerializer(typeof(Question));
                jsonForm.WriteObject(fs, question);
                Console.WriteLine("Объект сериализован");
            }

            using (FileStream fs = new FileStream("user.json", FileMode.OpenOrCreate))
            {
                DataContractJsonSerializer jsonForm = new DataContractJsonSerializer(typeof(Question));
                using (FileStream fr = new FileStream("question.json", FileMode.OpenOrCreate))
                {
                    Question? newPl = (Question?)jsonForm.ReadObject(fr);
                    Console.WriteLine("Объект десериализован");
                }
            }
            //----------------------------------------------------------------------

            Console.ReadLine();
        }
    }
}
