package Company.Workers;

import Company.Workers.Enums.Grades;
import org.json.JSONObject;

import java.io.Serializable;

public class Programmer extends Employee implements Serializable {
    public Programmer(String name, int age, int salary, Grades grade) {
        super(name, age, salary, grade);
    }
    public String toJson() {
        JSONObject json = new JSONObject();
        json.put("name", _name);
        json.put("age", _age);
        json.put("salary", _salary);
        json.put("grade", _grade);
        return json.toString();
    }

    public static Programmer fromJson(String jsonStr) {
        JSONObject json = new JSONObject(jsonStr);
        String name = json.getString("name");
        int age = json.getInt("age");
        int salary = json.getInt("salary");
        Grades grade = Grades.valueOf(json.getString("grade"));
        return new Programmer(name, age, salary, grade);
    }
    @Override
    public void work() {
        System.out.println("Я программирую");
    }
}
