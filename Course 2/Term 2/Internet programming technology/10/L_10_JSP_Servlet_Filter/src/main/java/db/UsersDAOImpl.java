package db;

import java.sql.*;


public class UsersDAOImpl implements UsersDAO{
    private final Connection connection;

    public UsersDAOImpl(Connection connection) {
        this.connection = connection;
    }

    @Override
    public boolean checkIfUsernameExist(String username) throws SQLException {
        String sql = "SELECT * FROM \"Users\" WHERE login = ?";
        try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
            preparedStatement.setString(1, username);
            try (ResultSet resultSet = preparedStatement.executeQuery()) {
                return resultSet.next();
            }
        } catch (SQLException e) {
            return false;
        }
    }

    @Override
    public String getAccountRoleByLogin(String login) throws SQLException {
        String sql = "SELECT role FROM \"Users\" WHERE login = ?";
        PreparedStatement preparedStatement = connection.prepareStatement(sql);
        preparedStatement.setString(1, login);
        ResultSet resultSet = preparedStatement.executeQuery();
        if (resultSet.next()){
            return resultSet.getString("role");
        }
        return "non";
    }

    @Override
    public boolean getUserByCredentials(String login, String HashPassword) throws SQLException {
        String sql = "SELECT password_hash FROM \"Users\" WHERE login = ?";
        PreparedStatement preparedStatement = connection.prepareStatement(sql);
        preparedStatement.setString(1, login);

        ResultSet resultSet = preparedStatement.executeQuery();
        if (resultSet.next()){
            return BcryptHasher.isPasswordCorrect(HashPassword, resultSet.getString("password_hash"));
        }
        return false;
    }
    @Override
    public void insert(String username, String password) throws SQLException {
        String sql = "INSERT INTO \"Users\"(login, password_hash, role) VALUES(?, ?, 'User')";
        PreparedStatement preparedStatement = connection.prepareStatement(sql);
        preparedStatement.setString(1, username);
        preparedStatement.setString(2, password);
        preparedStatement.executeUpdate();
    }
    @Override
    public ResultSet getLoginsWithPasswords() throws SQLException {
        Statement statement = connection.createStatement();
        return statement.executeQuery("SELECT * FROM \"Users\"");
    }
}
