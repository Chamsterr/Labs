using System.Threading;


namespace Lab_19_20_OOP
{
    public abstract class Sandwich
    {
        public Bread bread { get; protected set; }
        public string compound { get; protected set; }
        public Sandwich(Bread bread)
        {
            this.bread = bread;
            compound = bread.ToString();
        }
        public Sandwich(string comp)
        {
            compound += comp;
        }
    }

    public class RyeBreadSandwich : Sandwich
    {
        public RyeBreadSandwich(Bread bread) : base(bread)
        { }
    }
    public class WheatBreadSandwich : Sandwich
    {
        public WheatBreadSandwich(Bread bread) : base(bread)
        { }
    }

    public abstract class SandwichDecorator : Sandwich
    {
        protected Sandwich sandwich;
        public SandwichDecorator(string n, Sandwich sandwich) : base(n)
        {
            this.sandwich = sandwich;
        }
    }

    public class CheeseSandwich : SandwichDecorator
    {
        public CheeseSandwich(Sandwich p)
            : base(p.compound + ", с сыром", p)
        { }
    }

    public class MeatSandwich : SandwichDecorator
    {
        public MeatSandwich(Sandwich p)
            : base(p.compound + ", с мясом", p)
        { }
    }
}