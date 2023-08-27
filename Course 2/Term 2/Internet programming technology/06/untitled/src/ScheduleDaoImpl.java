import java.sql.*;

public class ScheduleDaoImpl<T> implements ScheduleDao<T> {
    private final Connection conn;

    @Override
    public void rescheduleSubject(String SubjectName, String Day) throws SQLException {
        conn.setAutoCommit(false);
        String updateSql = "UPDATE \"Subjects\" " +
                     "SET \"Date\"=? " +
                     "WHERE \"SubjectName\" = ?";

        PreparedStatement updateSubject = conn.prepareStatement(updateSql);
        updateSubject.setString(1, Day);
        updateSubject.setString(2, SubjectName);
        updateSubject.executeUpdate();


        String countSql = "SELECT count(\"SubjectName\") \"Count\", \"Date\" " +
                          "FROM \"Subjects\" " +
                          "WHERE \"Date\" = ?" +
                          "GROUP BY (\"Date\")";
        PreparedStatement getCountOfClasses = conn.prepareStatement(countSql);
        getCountOfClasses.setString(1, Day);


        ResultSet rs = getCountOfClasses.executeQuery();
        if (rs.next()){
            if (Integer.parseInt(rs.getString("Count")) > 2){
                conn.rollback();
            }
            else {
                conn.commit();
            }
        }
    }

    @Override
    public ResultSet getWeekDaysWithNumAuditoriums(Integer numAuditoriums) throws SQLException {
        String sql = "SELECT * " +
                     "FROM (SELECT COUNT(*) as count, S.\"Date\"\n" +
                        "   FROM \"Subjects\" S\n" +
                        "   GROUP BY S.\"Date\") S " +
                        "WHERE S.count = ?";
        PreparedStatement preparedStatement = conn.prepareStatement(sql);
        preparedStatement.setInt(1, numAuditoriums);

        return preparedStatement.executeQuery();
    }

    @Override
    public ResultSet getWeekDaysWithLessonsCount(Integer LessonsCount) throws SQLException {
        String sql = "SELECT * " +
                     "FROM \"Professors\" " +
                     "    INNER JOIN \"Subjects\" S on S.\"SubjectName\" = \"Professors\".\"SubjectName\" " +
                     "WHERE \"Professors\".\"ClassesNumber\" = ?";
        PreparedStatement preparedStatement = conn.prepareStatement(sql);
        preparedStatement.setInt(1, LessonsCount);

        return preparedStatement.executeQuery();
    }
    @Override
    public ResultSet getProfessorInfoByDayAndAuditorium(String day, Integer auditorium) throws SQLException {
        String sql = "SELECT * " +
                     "FROM \"Professors\" " +
                     "    INNER JOIN \"Subjects\" S on S.\"SubjectName\" = \"Professors\".\"SubjectName\" " +
                     "WHERE S.\"Date\" = ? AND \"Auditorium\" = ?";
        PreparedStatement preparedStatement = conn.prepareStatement(sql);
        preparedStatement.setString(1, day);
        preparedStatement.setInt(2, auditorium);

        return preparedStatement.executeQuery();
    }
    @Override
    public ResultSet getProfessorsWithoutClassesOnDayOfWeek(String day) throws SQLException{
        String sql = "SELECT * " +
                     "FROM \"Professors\" " +
                     "    INNER JOIN \"Subjects\" S on S.\"SubjectName\" = \"Professors\".\"SubjectName\" " +
                     "WHERE S.\"Date\" != ?";
        PreparedStatement preparedStatement = conn.prepareStatement(sql);
        preparedStatement.setString(1, day);
        return preparedStatement.executeQuery();
    }

    public ScheduleDaoImpl() throws SQLException {
        this.conn = DatabaseConnectorManager.getConnection();
    }
    @Override
    public ResultSet getAllSubject() throws SQLException {
        Statement st = conn.createStatement();
        return st.executeQuery("SELECT * FROM \"Professors\"");
    }
}
