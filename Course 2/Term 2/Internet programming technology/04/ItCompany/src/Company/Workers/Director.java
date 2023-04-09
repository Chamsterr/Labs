package Company.Workers;
import Company.Workers.Enums.Grades;

import java.util.List;
import java.util.Collections;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.logging.*;

public class Director extends Employee {
    private static final Logger LOGGER = Logger.getLogger(Director.class.getName());
    private List<Employee> team;
    public Director(String name, int age, int salary) {
        super(name, age, salary, null);
    }
    public class Plan {
        private List<Employee> requiredPositions;
        public Plan(List<Employee> requiredPositions) {
            this.requiredPositions = requiredPositions;
        }
    }
    public void getTeamByPlan(final Plan pl){
        String methodName = new Exception().getStackTrace()[0].getMethodName();
        LOGGER.info("Вызван метод " + methodName);
        team = pl.requiredPositions;
    }
    public int getTeamLength(){
        return team.size();
    }

    public List<Employee> getTeam() {
        return team;
    }

    public void setTeam(List<Employee> team) {
        this.team = team;
    }

    public List<Employee> getTeamSortedBySalary(){
        List<Employee> sortedTeam = new ArrayList<Employee>(team);
        Collections.sort(sortedTeam, Comparator.comparingInt(Employee::get_salary));
        return sortedTeam;
    }

    public List<Employee> getWorkersByGrade(Grades grade){
        List<Employee> workersByGrade = new ArrayList<Employee>();
        for (int i = 0; i < team.size(); i++){
            if (team.get(i)._grade == grade){
                workersByGrade.add(team.get(i));
            }
        }
        return workersByGrade;
    }

    @Override
    public Grades get_grade() {
        try
        {
            throw new DirectorException("У директора нет грейда");
        }
        catch (DirectorException ex)
        {
            System.out.println(ex.getMessage());
        }
        return null;
    }

    @Override
    public void set_grade(Grades _grade) {
        try
        {
            throw new DirectorException("У директора нельзя уcтановить грейд");
        }
        catch (DirectorException ex)
        {
            System.out.println(ex.getMessage());
        }
    }

    @Override
    public void work() {
        System.out.println("Я смотрю как работают другие работяги");
    }
}
