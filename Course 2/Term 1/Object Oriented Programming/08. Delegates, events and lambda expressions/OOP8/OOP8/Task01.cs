delegate void BossUpgrade(string str);
delegate void BossAtack(int bossPower);
class Boss 
{
    public event BossUpgrade Upgraded;
    public event BossAtack Atacked;

    int _power = 1;

    public void Upgrade()
    {
        _power++;
        Upgraded?.Invoke(_power.ToString());
    }

    public void TurnOn()
    {
        Atacked?.Invoke(_power);
    }
}

class Worker
{
    int _voltage;
    string _name;
    bool _isLive = true;
    public Worker(string name, int voltage)
    {
        this._voltage = voltage;
        this._name = name;
    }

    public void TakeVoltage(int _bossPower)
    {
        if (_isLive && _voltage < _bossPower)
        {
            Console.WriteLine($"{_name} Смерть");
            _isLive = false;
        }
        else if (_isLive)
        {
            Console.WriteLine($"{_name} норм");
        }
    }
}

class Task01
{
    public static void Main()
    {
        Boss boss = new Boss();
        Worker worker = new Worker("Дима", 1);
        Worker worker2 = new Worker("Никита", 2);
        boss.Atacked += worker.TakeVoltage;
        boss.Atacked += worker2.TakeVoltage;
        boss.Upgraded += DisplayMessage;

        boss.TurnOn();

        boss.Upgrade();
        boss.TurnOn();

        boss.Upgrade();
        boss.TurnOn();

        void DisplayMessage(string message) => Console.WriteLine($"Теперь босс имеет напряжение {message}");

        string str1 = "Hello world!";

        void DelE(string st1, int ind, Action<string, int> op) => op(st1, ind);
        Predicate<string> IsFirstH = (string s1) => s1.IndexOf('H') == 0;
        Func<string, string, int, string> Insert = (string s1, string s2, int i) => InsEl(s1, s2, i);

        DelE(str1, 10, DelElems);
        Console.WriteLine(str1);

        Console.WriteLine(IsFirstH(str1));
        Console.WriteLine(Insert(str1, "How", 4));


        void DelElems(string st1, int ind) => str1 = st1.Remove(ind);
        string InsEl(string st1, string st2, int ind) => str1.Insert(ind, st2);
        void ReplaceS(string st1, char c1, char c2) => str1.Replace(c1, c2);
        void Substr(string str1, int ind) => str1.Substring(ind);
        void IndexOfC(string str1, char c1) => str1.IndexOf(c1);
    }
}
