package db;

import java.sql.ResultSet;
import java.sql.SQLException;

public interface PlayerTeamDAO {
    ResultSet getAllTeams() throws SQLException;
    void UpdateTeams(String name, String mail) throws SQLException;
    void DeleteTeamByName(String name) throws SQLException;
}
