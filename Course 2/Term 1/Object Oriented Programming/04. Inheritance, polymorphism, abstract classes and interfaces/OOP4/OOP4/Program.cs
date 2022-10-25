using System;
using System.Diagnostics.Metrics;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using static System.Net.Mime.MediaTypeNames;

interface ICheckable
{
    StringBuilder PrintAllChallenge();
    void Check();
}
interface ICloneable
{
    object DoClone();
}
abstract class Challenge: ICloneable
{
    public bool passOrNo;
    public abstract bool tryToPass();
    public abstract object DoClone();

}

class Printer
{
    public virtual void iIAmPrinting(Challenge obj)
    {
        Console.WriteLine(obj.GetType());
        Console.WriteLine(obj.ToString());
    }
}
class Question : Challenge
{
    public string? question { get; set; }
    public string? questionAnswer { get; set; }
    public string? guess { get; set; }

    public Question()
    {
        question = questionAnswer = guess = null;
    }
    public Question(string question, string questionAnswer)
    {
        this.question = question;
        this.questionAnswer = questionAnswer;
    }
    
    public override bool tryToPass()
    {
        if (questionAnswer == guess)
        {
            passOrNo = true;
            return passOrNo;
        }
        passOrNo = false;
        return passOrNo;
    }

    public override object DoClone()
    {
        return new Question(question, questionAnswer);
    }

    public override string ToString()
    {
        return question;
    }
}

class Task : Challenge
{
    public string? task { get; set; }
    public string? taskAnswer { get; set; }
    public string? guess { get; set; }

    public Task()
    {
        task = taskAnswer = guess = null;
    }
    public Task(string question, string questionAnswer)
    {
        this.task = question;
        this.taskAnswer = questionAnswer;
    }

    public override bool tryToPass()
    {
        if (taskAnswer == guess)
        {
            passOrNo = true;
            return passOrNo;
        }
        passOrNo = false;
        return passOrNo;
    }

    public override Task DoClone()
    {
        return new Task(task, taskAnswer);
    }

    public override string ToString()
    {
        return task;
    }
}

class Test : Challenge, ICheckable
{
    static Test()
    {
        Console.WriteLine();
        Console.WriteLine("Для того чтобы сдать тест надо ответить правильно как минимум на половину вопросов");
    }
    public int? numberOfQuestions { get; set; }
    private int? numberOfCorrectQuestions;

    public List<Question> questions = new List<Question>();

    public Test()
    {
        numberOfQuestions = 0;
        numberOfCorrectQuestions = 0;
    }
    public Test(List<Question> questions)
    {
        this.questions = questions;
    }
    public void Check()
    {
        Console.WriteLine("Проверка результатов...");
        for (int i = 0; i < numberOfQuestions; i++)
        {
            if (questions[i].questionAnswer == questions[i].guess)
            {
                numberOfCorrectQuestions++;
            }
        }
    }
    public void addQuestion(string question, string questionAnswer)
    {
        questions.Add(new Question(question, questionAnswer.ToLower()));
        numberOfQuestions += 1;
    }
    public StringBuilder PrintAllChallenge()
    {
        var text = new StringBuilder(32);
        for (int i = 0; i < questions.Count; i++)
        {
            text.Append($"{i + 1}." + questions[i].question + '\n');
        }
        return text;
    }
    public override bool tryToPass()
    {
        if (numberOfQuestions - numberOfCorrectQuestions <= numberOfCorrectQuestions)
        {
            Console.WriteLine("Вы сдали");
            passOrNo = true;
            return passOrNo;
        }
        Console.WriteLine("Вы не сдали");
        passOrNo = false;
        return passOrNo;
    }
 

    public override Test DoClone()
    {
        return new Test(this.questions);
    }

    public override string ToString()
    {
        StringBuilder sb = new StringBuilder();
        sb.Append(GetType() + "\n");
        sb.Append(PrintAllChallenge());
        string? text = sb.ToString();
        return text;
    }
}

class Exam : Challenge, ICheckable
{
    static Exam()
    {
        Console.WriteLine();
        Console.WriteLine("Для того чтобы сдать экзамен надо сдать два любых испытания из трех");
    }
    public Question question1;
    public Question question2;
    public Task task;
    public int result = 0;

    public Exam()
    {
        question1 = new Question();
        question2 = new Question();
        task = new Task();
    }
    public Exam(Question question1, Question question2, Task task)
    {
        this.question1 = question1;
        this.question2 = question2;
        this.task = task;
    }

    public StringBuilder PrintAllChallenge()
    {
        var text = new StringBuilder("", 32);
        text.Append($"1." + question1.question + '\n');
        text.Append($"2." + question2.question + '\n');
        text.Append($"3." + task.task + '\n');
        return text;
    }
    public void Check()
    {
        Console.WriteLine("Проверка результатов...");
        if (question1.guess == question1.questionAnswer && question2.guess == question2.questionAnswer && task.guess == task.taskAnswer)
        {
            result = 9;
        }
        else if ((question1.guess == question1.questionAnswer && question2.guess == question2.questionAnswer) || (task.guess == task.taskAnswer && question2.guess == question2.questionAnswer) || (task.guess == task.taskAnswer && question1.guess == question1.questionAnswer))
        {
            result = 6;
        }
        else if (question1.guess == question1.questionAnswer || question2.guess == question2.questionAnswer || task.guess == task.taskAnswer)
        {
            result = 3;
        }
    }
    public override bool tryToPass()
    {
        if (result >= 6)
        {
            Console.WriteLine("Вы сдали");
            passOrNo = true;
            return passOrNo;
        }
        Console.WriteLine("Вы не сдали");
        passOrNo = false;
        return passOrNo;
    }

    public override Exam DoClone()
    {
        return new Exam(question1, question2, task);
    }
    public override string ToString()
    {
        StringBuilder sb = new StringBuilder();
        sb.Append(PrintAllChallenge() + "\n");
        string? text = sb.ToString();
        return text;
    }
}

sealed class FinalExam : Exam
{
    public new int id = 0;
    public FinalExam(Question question1, Question question2, Task task)
    {
        id++;
        this.question1 = question1;
        this.question2 = question2;
        this.task = task;
    }

    static FinalExam()
    {
        Console.WriteLine();
        Console.WriteLine("Для того чтобы сдать финальный экзамен надо сдать все три испытания");
    }

    public override bool tryToPass()
    {
        if (result == 9)
        {
            Console.WriteLine("Вы сдали");
            passOrNo = true;
            return passOrNo;
        }
        Console.WriteLine("Вы не сдали");
        passOrNo = false;
        return passOrNo;
    }

    public override FinalExam DoClone()
    {
        return new FinalExam(question1, question2, task);
    }
}

public class HelloWorld
{
    public static void Main(string[] args)
    {
        Test test = new Test();
        test.addQuestion("Микрофон?", "Да");
        test.addQuestion("10 премуществ цикла for", "Нет");
        Console.WriteLine(test.ToString());

        test.questions[0].guess = Console.ReadLine().ToLower();
        test.questions[1].guess = Console.ReadLine().ToLower();


        test.Check();
        test.tryToPass();


        Exam exam = new Exam(new Question("10 премуществ цикла for", "нет"), new Question("В каком учебном заведении вы учитесь", "бгту"), new Task("5+5", "10"));
        Console.WriteLine("\t Экзамен вариант 1");
        Console.WriteLine(exam.PrintAllChallenge());
        exam.question1.guess = Console.ReadLine().ToLower();
        exam.question2.guess = Console.ReadLine().ToLower();
        exam.task.guess = Console.ReadLine().ToLower();

        exam.Check();
        exam.tryToPass();

        FinalExam finalExam = new FinalExam(new Question("летела стая совсем небольшая. Сколько было птиц и какого вида (через запятую пример: голубь, 1)", "сова, 7"), new Question("Какая фамилия у Белодеда", "белодед"), new Task("2+2*2", "6"));
        Console.WriteLine("\t Финальный экзамен вариант 1");
        Console.WriteLine(finalExam.PrintAllChallenge());
        finalExam.question1.guess = Console.ReadLine().ToLower();
        finalExam.question2.guess = Console.ReadLine().ToLower();
        finalExam.task.guess = Console.ReadLine().ToLower();

        finalExam.Check();
        finalExam.tryToPass();

        Test test2 = test.DoClone();
        Exam exam2 = finalExam.DoClone();
        FinalExam finalExam2 = finalExam.DoClone();

        Console.WriteLine(test2 is Exam);
        FinalExam? finalExam3 = exam2 as FinalExam;

        Console.WriteLine();

        Printer printer = new Printer();
        Challenge[] allChallenges = { test, exam, finalExam2 };


        for (int i = 0; i < allChallenges.Length; i++)
        {
            printer.iIAmPrinting(allChallenges[i]);
        }
    }
}