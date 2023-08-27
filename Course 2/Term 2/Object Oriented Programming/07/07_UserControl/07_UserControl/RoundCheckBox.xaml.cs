using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;

namespace _07_UserControl
{
    /// <summary>
    /// Логика взаимодействия для RoundCheckBox.xaml
    /// </summary>
    public partial class RoundCheckBox : UserControl
    {
        // определение событие
        public static readonly RoutedEvent ClickEvent;

        static RoundCheckBox()
        {
            // регистрация маршрутизированного события
            RoundCheckBox.ClickEvent = EventManager.RegisterRoutedEvent("Click", RoutingStrategy.Bubble, typeof(RoutedEventHandler), typeof(RoundCheckBox));
            //................................
        }

        public event RoutedEventHandler Click
        {
            add
            {
                // добавление обработчика
                base.AddHandler(ButtonBase.ClickEvent, value);
            }
            remove
            {
                // удаление обработчика
                base.RemoveHandler(ButtonBase.ClickEvent, value);
            }
        }

        public RoundCheckBox()
        {
            InitializeComponent();
        }

        private static bool IsValidIsChecked(object value)
        {
            if (value is bool isChecked)
            {
                // Здесь можно добавить логику проверки
                return true;
            }
            else
            {
                return false;
            }
        }

        private static object CoerceIsChecked(DependencyObject d, object baseValue)
        {
            // Пример изменения значения свойства перед его установкой
            if ((bool)baseValue)
            {
                return false;
            }
            return baseValue;
        }

        private static void OnIsCheckedChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            RoundCheckBox roundCheckBox = (RoundCheckBox)d;
            bool isChecked = (bool)e.NewValue;

            // здесь можно добавить код, который должен выполняться при изменении свойства IsChecked
        }

        public static readonly DependencyProperty IsCheckedProperty =
        DependencyProperty.Register(
            "IsChecked",
            typeof(bool),
            typeof(RoundCheckBox),
            new FrameworkPropertyMetadata(
                false,
                FrameworkPropertyMetadataOptions.BindsTwoWayByDefault,
                new PropertyChangedCallback(OnIsCheckedChanged),
                new CoerceValueCallback(CoerceIsChecked),
                true,
                UpdateSourceTrigger.PropertyChanged),
            new ValidateValueCallback(IsValidIsChecked));

        public bool IsChecked
        {
            get { return (bool)GetValue(IsCheckedProperty); }
            set { SetValue(IsCheckedProperty, value); }
        }
    }
}
