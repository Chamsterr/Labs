package Company.Workers;
import Company.Workers.Enums.Grades;
public class Sysadmin extends Employee{
    public Sysadmin(String name, int age, int salary, Grades grade) {
        super(name, age, salary, grade);
    }
    @Override
    public void work() {
        System.out.println("Я сисадминю");
    }
}
