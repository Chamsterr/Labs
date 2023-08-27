package com.example.exam_06_dislike_like;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBManager {
    private static final String DB_URL = "jdbc:postgresql://localhost:8888/exam_06_like_dislike";
    private static final String DB_USERNAME = "postgres";
    private static final String DB_PASSWORD = "1";

    public static Connection getConnection() throws SQLException {
        return DriverManager.getConnection(DB_URL, DB_USERNAME, DB_PASSWORD);
    }
    public static void closeConnection(Connection conn) throws SQLException {
        conn.close();
    }
}