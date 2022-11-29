public abstract class Challenge
{
    public bool passOrNo;
    public abstract bool tryToPass();
    public abstract object DoClone();

}

public class Question : Challenge
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