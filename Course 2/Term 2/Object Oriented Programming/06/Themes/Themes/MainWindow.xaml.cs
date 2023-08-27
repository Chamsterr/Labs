using ModernWpf;
using System;
using System.Collections.Generic;
using System.Data.SQLite;
using System.Linq;
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
using System.Xml.Linq;

namespace Themes
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            using (var connection = new SQLiteConnection(@"Data Source=TaskifyDB.db"))
            {
                connection.Open();
                var command = new SQLiteCommand("SELECT * FROM Groups", connection);
                using (var reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        var id = reader.GetInt32(0);
                        var name = reader.GetString(1);
                        TreeViewItem parentItem = new TreeViewItem { Header = name, Tag = id };
                        treeView.Items.Add(parentItem);
                        var command2 = new SQLiteCommand($"SELECT * FROM Projects INNER JOIN Groups ON Projects.group_id = Groups.id WHERE Groups.id = {id}", connection);
                        var reader2 = command2.ExecuteReader();
                        while (reader2.Read())
                        {
                            var id2 = reader2.GetInt32(0);
                            var name2 = (string)reader2.GetString(1);

                            parentItem.Items.Add(new TreeViewItem { Header = name2, Tag = id2 });
                        }
                    }
                }
            }
        }
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            TreeViewDocument td = new TreeViewDocument();
            td.AddGroup("Untiled group");
            var mainWindow = Application.Current.MainWindow;
            mainWindow.DataContext = td;
        }
    }
}
