using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

partial class Question : Challenge
{
    public override object DoClone()
    {
        return new Question(question, questionAnswer);
    }

    public override string ToString()
    {
        return question;
    }
}