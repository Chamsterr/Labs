// example for an article on www.codeproject.com
// by Yury.Vetyukov@tuwien.ac.at

using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Data.SQLite;
using System.Diagnostics.Metrics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Xml.Linq;

namespace Themes
{
    class TreeViewDocument : ObservableCollection<TreeViewParentItem>
    {
        int counter = 1;
        public TreeViewDocument()
        {
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
                        TreeViewParentItem parentItem = new TreeViewParentItem(name, id);
                        Add(parentItem);
                        counter++;
                    }
                }
            }
        }

        public void AddGroup(string text)
        {
            SQLiteHelper.AddGroup(text);
            TreeViewParentItem parentItem = new TreeViewParentItem(text, counter);
            Add(parentItem);
        }
    }

    class TreeViewParentItem : NotifyPropertyChanged
    {
        // this is a name for the parent item - shall be displayed as a header and be editable
        string name;
        public string Name
        {
            get { return name; }
            set { SetField(ref name, value); }
        }

        // child items are just strings
        public ObservableCollection<TreeViewChildItem> TreeViewChildrenItems { get; set; }

        public TreeViewParentItem(string name, int id)
        {
            Name = name;
            TreeViewChildrenItems = new ObservableCollection<TreeViewChildItem>();
            using (var connection = new SQLiteConnection(@"Data Source=TaskifyDB.db"))
            {
                connection.Open();
                var command2 = new SQLiteCommand($"SELECT * FROM Projects INNER JOIN Groups ON Projects.group_id = Groups.id WHERE Groups.id = {id}", connection);
                var reader2 = command2.ExecuteReader();
                while (reader2.Read())
                {
                    var id2 = reader2.GetInt32(0);
                    var name2 = (string)reader2.GetString(1);

                    TreeViewChildrenItems.Add(new TreeViewChildItem(name2));

                }
            }
        }
    }

    class TreeViewChildItem : NotifyPropertyChanged
    {
        string name;
        int id;

        public int Id
        {
            get { return id; }
            set { SetField(ref id, value); }
        }
        public string Name
        {
            get { return name; }
            set { SetField(ref name, value); }
        }
        public TreeViewChildItem(string name)
        {
            this.name = name;
        }
        public override string ToString()
        {
            return name;
        }
    }
}
