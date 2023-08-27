using System;
using System.Windows.Markup;

namespace EventTriggerTest
{
    public class FontAwesomeExtension : MarkupExtension
    {
        public FontAwesomeExtension()
        {
        }

        public FontAwesomeExtension(string icon)
        {
            Icon = icon;
        }

        public string Icon { get; set; }

        public override object ProvideValue(IServiceProvider serviceProvider)
        {
            if (string.IsNullOrEmpty(Icon))
                return null;

            // здесь вы можете реализовать логику поиска нужной иконки Font Awesome по имени и возврата ее в качестве значения
            // для примера я просто возвращаю строку с именем иконки
            return "FontAwesome " + Icon;
        }
    }
}
