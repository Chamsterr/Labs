package Company.Workers;

import java.util.Comparator;

public class SalaryComparator implements Comparator<Employee> {
    @Override
    public int compare(Employee p1, Employee p2) {
        return p1.get_salary() - p2.get_salary();
    }
}