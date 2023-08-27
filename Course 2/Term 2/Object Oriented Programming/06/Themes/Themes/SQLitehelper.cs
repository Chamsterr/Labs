using System;
using System.Collections.Generic;
using System.Data.SQLite;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace Themes
{
    internal class SQLiteHelper
    {
        public static void AddGroup(String name)
        {
            using (var connection = new SQLiteConnection(@"Data Source=TaskifyDB.db"))
            {
                connection.Open();
                SQLiteCommand command = new SQLiteCommand();
                command.Connection = connection;

                command.CommandText = $"INSERT INTO Groups (name) VALUES ('{name}')";

                MessageBox.Show(command.CommandText);

                int number = command.ExecuteNonQuery();

                command.Connection = connection;
                MessageBox.Show(number.ToString());
            }
        }
    }
}
