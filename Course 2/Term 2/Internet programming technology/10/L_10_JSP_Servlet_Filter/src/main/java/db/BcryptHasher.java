package db;
import org.mindrot.jbcrypt.BCrypt;

import java.sql.ResultSet;
import java.sql.SQLException;

public class BcryptHasher {
    public static boolean isPasswordCorrect(String HashPassword, String password) throws SQLException {
        return BCrypt.checkpw(HashPassword, password);
    }

    public static String getPasswordHash(String password) throws SQLException {
        return BCrypt.hashpw(password, BCrypt.gensalt());
    }
}
