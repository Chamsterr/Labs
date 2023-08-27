import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

interface ScheduleDao<T> {
    ResultSet getProfessorsWithoutClassesOnDayOfWeek(String day) throws SQLException;
    ResultSet getAllSubject() throws SQLException;
    ResultSet getProfessorInfoByDayAndAuditorium(String day, Integer Auditorium) throws  SQLException;
    ResultSet getWeekDaysWithLessonsCount(Integer LessonsCount) throws  SQLException;
    ResultSet getWeekDaysWithNumAuditoriums(Integer numAuditoriums) throws SQLException;

    void rescheduleSubject(String SubjectName, String Day) throws SQLException;
}

