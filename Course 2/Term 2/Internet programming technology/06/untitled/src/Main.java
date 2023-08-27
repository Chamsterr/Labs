import java.sql.*;

public class Main {
    public static void main(String[] args) throws SQLException {
        ScheduleDaoImpl studentDao = new ScheduleDaoImpl<>();

        ResultSet rs = studentDao.getAllSubject();
        while (rs.next()){
            System.out.println(rs.getString("SubjectName"));
        }

        ResultSet rs2 = studentDao.getProfessorInfoByDayAndAuditorium("ВТ", 111);
        while (rs2.next()){
            System.out.println(rs2.getString("ProfessorsName"));
        }
        System.out.println("-----------");
        ResultSet rs3 = studentDao.getProfessorsWithoutClassesOnDayOfWeek("ВТ");
        while (rs3.next()){
            System.out.println(rs3.getString("ProfessorsName"));
        }

        ResultSet rs4 = studentDao.getWeekDaysWithLessonsCount(5);
        while (rs4.next()){
            System.out.println(rs4.getString("Date"));
        }

        ResultSet rs5 = studentDao.getWeekDaysWithNumAuditoriums(1);
        while (rs5.next()){
            System.out.println(rs5.getString("Date"));
        }

        studentDao.rescheduleSubject("ОАиП", "ВТ");
    }
}