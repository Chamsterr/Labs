// example for an article on www.codeproject.com
// by Yury.Vetyukov@tuwien.ac.at

using ModernWpf;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
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
using System.Windows.Shapes;

namespace Themes
{
    /// <summary>
    /// Interaction logic for WpfTreeViewInPlaceEditControl.xaml
    /// </summary>
    public partial class WpfTreeViewInPlaceEditControl : UserControl, INotifyPropertyChanged
    {
        // INotifyPropertyChanged
        public event PropertyChangedEventHandler PropertyChanged;

        // This flag indicates whether the tree view items shall (if possible) open in edit mode
        bool isInEditMode = false;
        public bool IsInEditMode
        {
            get { return isInEditMode; }
            set
            {
                isInEditMode = value;
                PropertyChangedEventHandler handler = PropertyChanged;
                if(handler != null)
                    handler(this, new PropertyChangedEventArgs("IsInEditMode"));
            }
        }
        private void EditNameMenuItem_Click(object sender, RoutedEventArgs e)
        {
            IsInEditMode = true;
        }
        private void DeleteNameMenuItem_Click(object sender, RoutedEventArgs e)
        {
            treeView.Items.Remove(this);
        }

        public WpfTreeViewInPlaceEditControl()
        {
            InitializeComponent();
        }

        // text in a text box before editing - to enable cancelling changes
        string oldText;

        // if a text box has just become visible, we give it the keyboard input focus and select contents
        private void editableTextBoxHeader_IsVisibleChanged(object sender, DependencyPropertyChangedEventArgs e)
        {
            var tb = sender as TextBox;
            if(tb.IsVisible)
            {
                tb.Focus();
                tb.SelectAll();


                tb.Background = new SolidColorBrush(ThemeManager.Current.ActualAccentColor);
                oldText = tb.Text;      // back up - for possible cancelling
            }
        }

        // stop editing on Enter or Escape (then with cancel)
        private void editableTextBoxHeader_KeyDown(object sender, KeyEventArgs e)
        {

            if(e.Key == Key.Enter)
            {
                var tb = sender as TextBox;
                if (tb.Text != "")
                {
                    IsInEditMode = false;
                }
            }
            if(e.Key == Key.Escape)
            {
                var tb = sender as TextBox;
                tb.Text = oldText;
                IsInEditMode = false;
            }
        }

        // stop editing on lost focus
        private void editableTextBoxHeader_LostFocus(object sender, RoutedEventArgs e)
        {
            var tb = sender as TextBox;
            if (tb.Text != "")
            {
                IsInEditMode = false;
            }
            // if tb is blank 
            else
            {
                tb.Focus();
                tb.Text = oldText;
                IsInEditMode = false;
            }
        }

        // it might happen, that the user pressed F2 while a non-editable item was selected
        private void treeView_SelectedItemChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            IsInEditMode = false;
        }

        // we (possibly) switch to edit mode when the user presses F2
        private void treeView_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.Key == Key.F2)
                IsInEditMode = true;
        }

        // the user has clicked a header - proceed with editing if it was selected
        private void textBlockHeader_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            if(FindTreeItem(e.OriginalSource as DependencyObject).IsSelected)
            {
                IsInEditMode = true;
                e.Handled = true;       // otherwise the newly activated control will immediately loose focus
            }
        }

        // searches for the corresponding TreeViewItem,
        // based on http://stackoverflow.com/questions/592373/select-treeview-node-on-right-click-before-displaying-contextmenu
        static TreeViewItem FindTreeItem(DependencyObject source)
        {
            while(source != null && !(source is TreeViewItem))
                source = VisualTreeHelper.GetParent(source);
            return source as TreeViewItem;
        }
    }
}
