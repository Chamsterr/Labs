using System.Text;
using System.Threading;

namespace Lab_19_20_OOP
{
    // абстрактный класс строителя

    //мука
    public class Flour
    {
        // какого сорта мука
        public string Sort { get; set; }
    }
    // соль
    public class Salt
    { }
    // пищевые добавки
    public class Additives
    {
        public string Name { get; set; }
    }

    public class Bread
    {
        // мука
        public Flour Flour { get; set; }
        // соль
        public Salt Salt { get; set; }
        // пищевые добавки
        public Additives Additives { get; set; }
        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();

            sb.Append("Хлеб(");
            if (Flour != null)
                sb.Append(Flour.Sort + "; ");
            if (Salt != null)
                sb.Append("Соль; ");
            if (Additives != null)
                sb.Append("Добавки: " + Additives.Name + "; ");
            sb.Append(")");
            return sb.ToString();
        }
    }
    public abstract class BreadBuilder
    {
        public Bread Bread { get; private set; }
        public void CreateBread()
        {
            Bread = new Bread();
        }
        public abstract void SetFlour();
        public abstract void SetSalt();
        public abstract void SetAdditives();
    }
    // пекарь
    public class Baker
    {
        public Bread Bake(BreadBuilder breadBuilder)
        {
            breadBuilder.CreateBread();
            breadBuilder.SetFlour();
            breadBuilder.SetSalt();
            breadBuilder.SetAdditives();
            return breadBuilder.Bread;
        }
    }
    // строитель для ржаного хлеба
    public class RyeBreadBuilder : BreadBuilder
    {
        public override void SetFlour()
        {
            this.Bread.Flour = new Flour { Sort = "Ржаная мука 1 сорт" };
        }

        public override void SetSalt()
        {
            this.Bread.Salt = new Salt();
        }

        public override void SetAdditives()
        {
            // не используется
        }
    }
    // строитель для пшеничного хлеба
    public class WheatBreadBuilder : BreadBuilder
    {
        public override void SetFlour()
        {
            this.Bread.Flour = new Flour { Sort = "Пшеничная мука высший сорт" };
        }

        public override void SetSalt()
        {
            this.Bread.Salt = new Salt();
        }

        public override void SetAdditives()
        {
            this.Bread.Additives = new Additives { Name = "улучшитель хлебопекарный" };
        }
    }
}