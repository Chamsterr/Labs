import Company.Workers.*;
import Company.Workers.Enums.Grades;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Director dir = new Director("Elon", 19, 2_557_211);
        Director.Plan plan = dir.new Plan(new ArrayList<Employee>(){{
            add(new Programmer("Maxim", 25, 2500, Grades.Middle));
            add(new Programmer("Mikita", 19, 700, Grades.Junior));
            add(new Engineer("Lee", 27, 7089, Grades.Senior));
            add(new Sysadmin("Roman", 47, 1812, Grades.Senior));
        }});
        dir.getTeamByPlan(plan);

        System.out.println(dir.getTeamLength());
        System.out.println(dir.getTeam());
        System.out.println(dir.getTeamSortedBySalary());
        System.out.println(dir.getWorkersByGrade(Grades.Senior));

        System.out.println(dir.get_grade());
    }
}