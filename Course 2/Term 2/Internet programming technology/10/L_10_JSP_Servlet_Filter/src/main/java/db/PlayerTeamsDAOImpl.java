package db;

import java.sql.*;

public class PlayerTeamsDAOImpl implements PlayerTeamDAO{
    private final Connection connection;

    public PlayerTeamsDAOImpl(Connection connection) {
        this.connection = connection;
    }
    @Override
    public ResultSet getAllTeams() throws SQLException {
        Statement statement = connection.createStatement();
        return statement.executeQuery("SELECT * FROM \"Player_teams\" ");
    }

    @Override
    public void UpdateTeams(String name, String mail) throws SQLException {
        String sql = "INSERT INTO \"Player_teams\"(team_name, contact_email) VALUES (?, ?)";
        PreparedStatement statement = connection.prepareStatement(sql);
        statement.setString(1, name);
        statement.setString(2, mail);
        statement.executeUpdate();
    }
    @Override
    public void DeleteTeamByName(String name) throws SQLException {
        String sql = "DELETE FROM \"Player_teams\" WHERE team_name = ?";
        PreparedStatement preparedStatement = connection.prepareStatement(sql);
        preparedStatement.setString(1, name);
        preparedStatement.executeUpdate();
    }
}
