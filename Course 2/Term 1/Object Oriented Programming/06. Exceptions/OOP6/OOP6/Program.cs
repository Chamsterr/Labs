using System;
using System.ComponentModel;
using System.Diagnostics.Metrics;
using System.Globalization;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using static System.Collections.Specialized.BitVector32;
using static System.Net.Mime.MediaTypeNames;


enum grades
{
    one = 1,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten
}

struct Student
{
    public string firstName;
    public string lastName;
    public int course;
    public grades grade;

    public void PrintNameAndCourse()
    {
        if (course < 1 || course > 4)
        {
            throw new StudentException("Неправильно выбран курс", course);
        }
        Console.WriteLine($"{firstName} {lastName} - {course} course \ngrade - {grade}");
    }
};
interface ICheckable
{
    StringBuilder PrintAllChallenge();
    void Check();
}
interface ICloneable
{
    object DoClone();
}
public abstract class Challenge : ICloneable
{
    string name;
    public string subjectName 
    {
        set
        {
            if (value == null || value == "")
            {
                throw new ChallengeException("Должно присутствовать название предмета", value);
            }
            name = value;
        }
        get { return name; }
    }

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
public partial class Question : Challenge
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
}

public class Task : Challenge
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
    int numberofquestions;
    public int numberOfQuestions 
    {
        set
        {
            if (value == 0)
            {
                throw new TestException("Должен быть хотя бы один вопрос", value);
            }
            numberofquestions = value;
        }
        get { return numberofquestions; }
    }
    private int? numberOfCorrectQuestions;

    public List<Question> questions = new List<Question>();

    public Test()
    {
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
        numberOfQuestions++;
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

public class Exam : Challenge, ICheckable
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
    public int id = 0;
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

public class Container
{
    public List<object> containerList { get; set; }

    public Container()
    {
        containerList = new List<object>();
    }
    public void Add(object ob)
    {
        containerList.Add(ob);
    }
    public void Remove(object ob)
    {
        containerList.Remove(ob);
    }
    public string PrintList()
    {
        string text = "";
        for (int i = 0; i < containerList.Count; i++)
        {
            text = text + containerList[i].ToString();
        }
        return text;
    }

}


public class Control
{
    Container session { get; set; }

    public Control(Container session)
    {
        this.session = session;
    }

    public int GetQuantityBySubject(string name)
    {
        int counter = 0;
        for (int i = 0; i < session.containerList.Count; i++)
        {
            if (session.containerList[i] is Exam || session.containerList[i] is FinalExam)
            {
                Exam? obj1 = session.containerList[i] as Exam;
                if (obj1.subjectName == name)
                {
                    counter++;
                }
            }
        }
        return counter;
    }

    public int GetQuantitySpecificQuantity(int number)
    {
        int counter = 0;
        for (int i = 0; i < session.containerList.Count; i++)
        {
            if (session.containerList[i] is Test)
            {
                Test? obj1 = session.containerList[i] as Test;
                if (obj1.numberOfQuestions == number)
                {
                    counter++;
                }
            }
        }
        return counter;
    }
}

public class HelloWorld
{
    public static void Main(string[] args)
    {
        try
        {
            Student nikita;
            nikita.firstName = "Nikita";
            nikita.lastName = "Kovkel";
            nikita.course = 5;
            nikita.grade = grades.eight;
            nikita.PrintNameAndCourse();
        }
        catch(StudentException ex)
        {
            Console.WriteLine($"Ошибка: {ex.Message} ({ex.Value})");
        }   

        Exam exam = new Exam(new Question("10 премуществ цикла for", "нет"), new Question("В каком учебном заведении вы учитесь", "бгту"), new Task("5+5", "10"));
        exam.subjectName = "ОАиП";

        FinalExam finalExam = new FinalExam(new Question("летела стая совсем небольшая. Сколько было птиц и какого вида (через запятую пример: голубь, 1)", "сова, 7"), new Question("Какая фамилия у Белодеда", "белодед"), new Task("2+2*2", "6"));
        finalExam.subjectName = "ОАиП";

        Test test = new Test();
        test.numberOfQuestions = 2;
        test.addQuestion("Микрофон?", "Да");
        test.addQuestion("10 премуществ цикла for", "Нет");
        test.subjectName = "ООП";

        Container container = new Container();
        container.Add(exam);
        container.Add(finalExam);
        container.Add(test);
        Console.WriteLine(container.PrintList());

        Control session = new Control(container);
        Console.WriteLine(session.GetQuantityBySubject("ОАиП"));

        Console.WriteLine(session.GetQuantitySpecificQuantity(2));

        try
        {
            Test test2 = new Test();
            test2.addQuestion("Микрофон?", "Да");
            test2.addQuestion("10 премуществ цикла for", "Нет");
            test2.subjectName = "1";
            test2.numberOfQuestions = 0;
        }
        catch (ChallengeException ex)
        {
            Console.WriteLine($"Ошибка: {ex.Message}");
        }
        catch (TestException ex)
        {
            Console.WriteLine($"Ошибка: {ex.Message}");
            try
            {
                int l = Int16.Parse(Console.ReadLine());
                if(l == 0)
                {
                    throw;
                }

            }
            catch 
            {
                Console.WriteLine($"Ошибка");
            }
        }
        catch
        {
            Console.WriteLine("Возникло исключение!");
        }
        finally
        {
            Console.WriteLine("Проблем не существует!");
        }
    }
}