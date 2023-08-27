package com.example.norm;

import org.mindrot.jbcrypt.BCrypt;

import java.sql.*;

public class AccountsDaoImpl implements AccountsDao{
    private final Connection connection;

    @Override
    public boolean checkIfUsernameExist(String username) throws SQLException {
    String sql = "SELECT * FROM \"Accounts\" WHERE login = ?";
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
        String sql = "SELECT role FROM \"Accounts\" WHERE login = ?";
        PreparedStatement preparedStatement = connection.prepareStatement(sql);
        preparedStatement.setString(1, login);
        ResultSet resultSet = preparedStatement.executeQuery();
        if (resultSet.next()){
            return resultSet.getString("role");
        }
        return "non";
    }

    public AccountsDaoImpl(Connection connection) {
        this.connection = connection;
    }
    @Override
    public boolean getUserByCredentials(String login, String HashPassword) throws SQLException {
        String sql = "SELECT password FROM \"Accounts\" WHERE login = ?";
        PreparedStatement preparedStatement = connection.prepareStatement(sql);
        preparedStatement.setString(1, login);

        ResultSet resultSet = preparedStatement.executeQuery();
        if (resultSet.next()){
            return BCrypt.checkpw(HashPassword, resultSet.getString("password"));
        }
        return false;
    }

    @Override
    public void insert(String username, String password) throws SQLException {
        String sql = "INSERT INTO \"Accounts\"(login, password, role) VALUES(?, ?, 'User')";
        PreparedStatement preparedStatement = connection.prepareStatement(sql);
        preparedStatement.setString(1, username);
        preparedStatement.setString(2, password);
        preparedStatement.executeUpdate();
    }

    @Override
    public ResultSet getLoginsWithPasswords() throws SQLException {
        Statement statement = connection.createStatement();
        return statement.executeQuery("SELECT * FROM \"Accounts\"");
    }

}
