using System;
using System.Xml.Serialization;



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
            XmlSerializer xmlSerializer = new XmlSerializer(typeof(Question));

            using (FileStream fs = new FileStream("person.xml", FileMode.OpenOrCreate))
            {
                xmlSerializer.Serialize(fs, question);
                Console.WriteLine("Объект сериализован");
            }

            using (FileStream fs = new FileStream("person.xml", FileMode.OpenOrCreate))
            {
                Question? person = xmlSerializer.Deserialize(fs) as Question;
                Console.WriteLine("Объект десериализован");
            }

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
                    Question newPl = (Question)jsonForm.ReadObject(fr);
                    Console.WriteLine("Объект десериализован");
                }
            }
            //----------------------------------------------------------------------

            Console.ReadLine();
        }
    }
}
