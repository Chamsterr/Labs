using ModernWpf;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Input;
using System.Windows.Media;

namespace Taskify0._5
{
    public partial class MainWindow : Window
    {
        private LastButtonManager lastButtonManager = new LastButtonManager();
        private Button _lastButton;
        public Button LastButton
        {
            get { return _lastButton; }
            set
            {
                _lastButton = value;
                if (_lastButton != null)
                {
                    lastButtonManager.button = value;
                    lastButtonManager.Execute();
/*                    _lastButton.Background = (Brush)this.Resources["AccentColor"];
*/              }
            }
        }

        List<ToDo> toDos = new List<ToDo>()
        {
            new ToDo("Первая задача", "Home", true),
            new ToDo("Вторая задача", "Home", false)
        };
        public MainWindow()
        {
            InitializeComponent();
            ThemeManager.Current.ApplicationTheme = ApplicationTheme.Light;
            ThemeManager.Current.AccentColor = SystemParameters.WindowGlassColor;
            this.Resources["buttonBrush"] = new SolidColorBrush(SystemParameters.WindowGlassColor);
            lastButtonManager = new LastButtonManager();
            LastButton = Input;
        }

        private void OpenNavDrawerButton_Click(object sender, RoutedEventArgs e)
        {
            // Если Navigation Drawer скрыт, показываем его с помощью анимации
            if (NavDrawer.Width == 0)
            {
                NavDrawer.BeginAnimation(Grid.WidthProperty, new System.Windows.Media.Animation.DoubleAnimation(NavDrawer.ActualWidth, 325, new Duration(TimeSpan.FromSeconds(0.2))));
            }
            // Если Navigation Drawer открыт, скрываем его с помощью анимации
            else
            {
                NavDrawer.BeginAnimation(Grid.WidthProperty, new System.Windows.Media.Animation.DoubleAnimation(NavDrawer.ActualWidth, 0, new Duration(TimeSpan.FromSeconds(0.2))));
            }
        }

        private void GridSplitter_DragDelta(object sender, System.Windows.Controls.Primitives.DragDeltaEventArgs e)
        {

        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }
        private void DeleteMenuItem_Click(object sender, RoutedEventArgs e)
        {
            var item = sender as ListBoxItem;
            var task = item.DataContext as ToDo;

            ToDoManager toDoM = new ToDoManager(toDos, task);
            toDoM.Undo();
            toDosXaml.ItemsSource = toDos;
            toDosXaml.Items.Refresh();
        }

        private void ListBoxItem_MouseDoubleClick(object sender, MouseButtonEventArgs e)
        {
            var item = sender as ListBoxItem;
            var task = item.DataContext as ToDo;

            ToDoManager toDoM = new ToDoManager(toDos, task);
            toDoM.Undo();
            if (Header.Text != "Все")
            {
                toDosXaml.ItemsSource = toDos.Where(item => item.category == Header.Text).ToList();
            }
            toDosXaml.Items.Refresh();

        }

        private void TextBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Enter)
            {
                TextBox textBox = sender as TextBox;
                if (textBox.Text != "")
                {
                    ToDo toDo = new ToDo(textBox.Text, Header.Text.ToString(), false);
                    // Обработка ввода пользователя
                    ToDoManager toDoM = new ToDoManager(toDos, toDo);
                    toDoM.Execute();
                    if (Header.Text.ToString() != "Все")
                    {
                        toDosXaml.ItemsSource = toDos.Where(item => item.category == Header.Text).ToList();
                    }
                    else
                    {
                        toDosXaml.ItemsSource = toDos;
                    }
                    toDosXaml.Items.Refresh();
                    textBox.Text = "";
                }
            }
        }

        private void All_Click(object sender, RoutedEventArgs e)
        {
            Button senderButton = sender as Button;
            LastButton = senderButton;
            Header.Text = "Все";
            toDosXaml.ItemsSource = toDos;
            toDosXaml.Items.Refresh();

        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Button senderButton = sender as Button;
            LastButton = senderButton;
            Header.Text = "Входящие";
            toDosXaml.ItemsSource = toDos.Where(item => item.category == Header.Text).ToList();
            toDosXaml.Items.Refresh();

        }

        private void Home_Click(object sender, RoutedEventArgs e)
        {
            Button senderButton = sender as Button;
            LastButton = senderButton;
            Header.Text = Home.Content.ToString();
            toDosXaml.ItemsSource = toDos.Where(item => item.category == Home.Content.ToString()).ToList();
            toDosXaml.Items.Refresh();

        }

        private void ThemeChanger_Checked(object sender, RoutedEventArgs e)
        {
            ThemeManager.Current.ApplicationTheme = ApplicationTheme.Dark;
            ThemeManager.Current.AccentColor = SystemParameters.WindowGlassColor;

            var uri = new Uri("Dictionary2.xaml", UriKind.Relative);
            ResourceDictionary resourceDict = Application.LoadComponent(uri) as ResourceDictionary;
            Application.Current.Resources.Clear();
            Application.Current.Resources.MergedDictionaries.Add(resourceDict);
        }

        private void ToggleButton_Unchecked(object sender, RoutedEventArgs e)
        {
            ThemeManager.Current.ApplicationTheme = ApplicationTheme.Light;
            ThemeManager.Current.AccentColor = SystemParameters.WindowGlassColor;

            var uri = new Uri("Dictionary1.xaml", UriKind.Relative);
            ResourceDictionary resourceDict = Application.LoadComponent(uri) as ResourceDictionary;
            // очищаем коллекцию ресурсов приложения
            Application.Current.Resources.Clear();
            // добавляем загруженный словарь ресурсов
            Application.Current.Resources.MergedDictionaries.Add(resourceDict);
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            lastButtonManager.Redo();
            /*MessageBox.Show(lastButtonManager.button.Content.ToString());*/
            lastButtonManager.button.RaiseEvent(new RoutedEventArgs(Button.ClickEvent));
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            lastButtonManager.Undo();
            /*MessageBox.Show(lastButtonManager.button.Content.ToString());*/
            lastButtonManager.button.RaiseEvent(new RoutedEventArgs(Button.ClickEvent));
        }
    }
}