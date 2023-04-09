package Company.Workers;
import Company.Workers.Enums.Grades;
public class Engineer extends Employee {
    public Engineer(String name, int age, int salary, Grades grade) {
        super(name, age, salary, grade);
    }
    @Override
    public void work() {
        System.out.println("Я инжинерю");
    }
}
