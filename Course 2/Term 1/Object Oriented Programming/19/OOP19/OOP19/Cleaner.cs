using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_19_20_OOP
{
    public enum Purity
    {
        Dirty, Purely
    }
    public class Cleaner
    {
        public EmotionState State { get; set; }
        public Cleaner() : this(new NeutralState()) { }
        public Cleaner(EmotionState state)
            => State = state;
        public void Cleaning(Purity pur)
            => State.ChangeState(this, pur);
    }

    public abstract class EmotionState
    {
        public abstract void ChangeState(Cleaner cleaner, Purity pur);
    }
    public class AngerState : EmotionState
    {
        public AngerState()
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("Думаю все убрать шваброй");
            Console.ResetColor();
        }
        public override void ChangeState(Cleaner cleaner, Purity pur)
            => cleaner.State = pur switch
            {
                Purity.Purely => new NeutralState(),
                Purity.Dirty => new AngerState(),
                _ => new NeutralState()
            };
    }
    public class NeutralState : EmotionState
    {
        public NeutralState()
        {
            Console.ForegroundColor = ConsoleColor.DarkYellow;
            Console.WriteLine("Потиху буду убирать");
            Console.ResetColor();
        }
        public override void ChangeState(Cleaner cleaner, Purity pur)
            => cleaner.State = pur switch
            {
                Purity.Purely => new JoyState(),
                Purity.Dirty => new AngerState(),
                _ => new NeutralState()
            };
    }
    public class JoyState : EmotionState
    {
        public JoyState()
        {
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("Как же хороша чистота");
            Console.ResetColor();
        }
        public override void ChangeState(Cleaner cleaner, Purity pur)
            => cleaner.State = pur switch
            {
                Purity.Purely => new AngerState(),
                Purity.Dirty => new NeutralState(),
                _ => new NeutralState()
            };
    }

}