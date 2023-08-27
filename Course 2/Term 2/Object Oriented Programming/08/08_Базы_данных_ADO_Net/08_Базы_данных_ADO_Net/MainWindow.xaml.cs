using System;
using System.Collections.Generic;
using System.Data.SQLite;
using System.Data;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace _08_Базы_данных_ADO_Net_
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            refreshForRender();
        }

        private System.Collections.IEnumerable refreshForRender()
        {

            string connectionString = @"Data Source=TaskifyDB.db";
            string query = "SELECT * FROM Groups";

            using (SQLiteConnection connection = new SQLiteConnection(connectionString))
            {
                SQLiteDataAdapter adapter = new SQLiteDataAdapter(query, connection);
                DataSet dataSet = new DataSet();
                adapter.Fill(dataSet, "Groups");
                return myDataGrid.ItemsSource = dataSet.Tables["Groups"].DefaultView;
            }

        }

        private void TextBox_PreviewKeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Enter)
            {
                TextBox textBox = (TextBox)sender;
                SQLiteHelper.AddGroup(textBox.Text);
            }
        }

        private void dataGridGroups_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

        }
        private void AddGroup_Click(object sender, RoutedEventArgs e)
        {
            SQLiteHelper.AddGroup(GroupName.Text);
            refreshForRender();

        }

        private void DeleteGroup_Click(object sender, RoutedEventArgs e)
        {
            SQLiteHelper.DeleteGroup(Int16.Parse(GroupName.Text));
            refreshForRender();
        }

    }
}
