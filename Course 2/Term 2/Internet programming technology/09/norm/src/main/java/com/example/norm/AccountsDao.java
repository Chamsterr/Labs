package com.example.norm;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;

public interface AccountsDao {
    void insert(String username, String password) throws SQLException;

    ResultSet getLoginsWithPasswords() throws SQLException;
    String getAccountRoleByLogin(String login) throws SQLException;
    boolean getUserByCredentials(String username, String HashPassword) throws SQLException;

    boolean checkIfUsernameExist(String username) throws SQLException;
}
