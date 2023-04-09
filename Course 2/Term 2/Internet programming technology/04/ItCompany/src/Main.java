import Company.Workers.*;
import Company.Workers.Enums.Grades;
import javax.xml.stream.XMLInputFactory;
import javax.xml.stream.XMLStreamConstants;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws FileNotFoundException, XMLStreamException {
        Director dir = new Director("Elon", 19, 2_557_211);
        XMLInputFactory factory = XMLInputFactory.newInstance();
        System.out.println("Working Directory = " + System.getProperty("user.dir"));
        InputStream inputStream = new FileInputStream("files\\plan.xml");

        XMLStreamReader reader = factory.createXMLStreamReader(inputStream);
        List<Employee> employees = new ArrayList<>();

        while (reader.hasNext()) {
            int eventType = reader.next();

            if (eventType == XMLStreamConstants.START_ELEMENT && "first,second,third,forth".contains(reader.getLocalName())) {
                String name = null;
                int age = 0;
                int salary = 0;
                String grade = null;

                while (reader.hasNext()) {
                    eventType = reader.next();

                    if (eventType == XMLStreamConstants.END_ELEMENT && "first,second,third,forth".contains(reader.getLocalName())) {
                        Employee employee = new Programmer(name, age, salary, Grades.valueOf(grade));
                        employees.add(employee);
                        break;
                    }

                    if (eventType == XMLStreamConstants.START_ELEMENT && "name".equals(reader.getLocalName())) {
                        name = reader.getElementText();
                    }

                    if (eventType == XMLStreamConstants.START_ELEMENT && "age".equals(reader.getLocalName())) {
                        age = Integer.parseInt(reader.getElementText());
                    }

                    if (eventType == XMLStreamConstants.START_ELEMENT && "salary".equals(reader.getLocalName())) {
                        salary = Integer.parseInt(reader.getElementText());
                    }

                    if (eventType == XMLStreamConstants.START_ELEMENT && "grade".equals(reader.getLocalName())) {
                        grade = reader.getElementText();
                    }
                }
            }
        }
        Director.Plan plan = dir.new Plan(employees);
        dir.getTeamByPlan(plan);

        System.out.println(dir.getTeamLength());
        System.out.println(dir.getTeam());
        System.out.println(dir.getTeamSortedBySalary());
        System.out.println(dir.getWorkersByGrade(Grades.Senior));

        System.out.println(dir.get_grade());

        Collections.sort(employees, new SalaryComparator());

        for (Employee employee : employees) {
            System.out.println(employee);
        }

        Programmer programmer = new Programmer("Иванов Иван", 30, 50000, Grades.Middle);
        String json = programmer.toJson();

        System.out.println(json);
        System.out.println(Programmer.fromJson(json));

        List<Employee> yongEmployees = employees.stream().filter(e -> e.get_age() < 20).collect(Collectors.toList());
        for (Employee employee : yongEmployees) {
            System.out.println("Молодой " + employee);
        }

        List<String> employeeNames = employees.stream()
        .map(Employee::get_name) // или e -> e.getName()
        .collect(Collectors.toList());

        for (String employeeName : employeeNames) {
            System.out.println(employeeName);
        }
    }
}