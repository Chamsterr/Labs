using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;

namespace _07_UserControl
{
    public static class CustomCommands
    {
        public static readonly RoutedUICommand SayHello = new RoutedUICommand(
            "Say Hello",
            "SayHello",
            typeof(CustomCommands),
            new InputGestureCollection()
            {
            new KeyGesture(Key.H, ModifierKeys.Control)
            }
        );
    }
}
