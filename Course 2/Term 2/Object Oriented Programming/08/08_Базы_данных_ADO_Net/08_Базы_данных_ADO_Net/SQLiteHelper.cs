using System;
using System.Collections.Generic;
using System.Data.SQLite;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace _08_Базы_данных_ADO_Net_
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
        public static void DeleteGroup(int id)
        {
            using (var connection = new SQLiteConnection(@"Data Source=TaskifyDB.db"))
            {
                connection.Open();
                SQLiteCommand command = new SQLiteCommand();
                command.Connection = connection;

                command.CommandText = $"DELETE FROM Groups WHERE id = '{id}'";

                MessageBox.Show(command.CommandText);

                int number = command.ExecuteNonQuery();

                command.Connection = connection;
                MessageBox.Show(number.ToString());
            }
        }

    }
}
