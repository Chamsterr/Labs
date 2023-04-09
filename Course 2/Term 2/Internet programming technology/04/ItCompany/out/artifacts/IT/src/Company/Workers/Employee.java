
package Company.Workers;
import Company.Workers.Enums.Grades;
public abstract class Employee implements Worker {
    protected String _name;
    protected int _age;
    protected int _salary;
    protected Company.Workers.Enums.Grades _grade;
    public Employee(String name, int age, int salary, Grades grade){
        _name = name;
        _age = age;
        _salary = salary;
        _grade = grade;
    }

    public String get_name() {
        return _name;
    }

    public void set_name(String _name) {
        this._name = _name;
    }

    public int get_age() {
        return _age;
    }

    public void set_age(int _age) {
        this._age = _age;
    }

    public Grades get_grade() {
        return _grade;
    }

    public void set_grade(Grades _grade) {
        this._grade = _grade;
    }

    public int get_salary() {
        return _salary;
    }

    public void set_salary(int _salary) {
        this._salary = _salary;
    }

    @Override
    public String toString() {
        return this.getClass().getSimpleName() + "{" +
                "Имя='" + _name + '\'' +
                ", Возраст=" + _age +
                ", Зарплата=" + _salary +
                ", Грейд=" + _grade +
                '}';
    }
}