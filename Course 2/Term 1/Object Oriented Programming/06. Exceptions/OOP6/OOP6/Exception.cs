using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
public class ChallengeException: Exception
{
    public string Value { get; }
    public ChallengeException(string message, string val)
    : base(message)
    {
        Value = val;
    }
}

public class TestException : Exception
{
    public int Value { get; }
    public TestException(string message, int val)
    : base(message)
    {
        Value = val;
    }
}

public class StudentException : Exception
{
    public int Value { get; }
    public StudentException(string message, int val)
    : base(message)
    {
        Value = val;
    }
}

