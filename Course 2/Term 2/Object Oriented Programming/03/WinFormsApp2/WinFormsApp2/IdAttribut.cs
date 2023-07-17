using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WinFormsApp2
{
    using System.ComponentModel.DataAnnotations;

    public class IDAttribute : ValidationAttribute
    {
        private readonly string _pattern = @"^\d+$"; // регулярное выражение, разрешающее только цифры

        public IDAttribute()
        {
            ErrorMessage = "ID should only contain digits."; // сообщение об ошибке
        }

        protected override ValidationResult IsValid(object value, ValidationContext validationContext)
        {
            if (value == null)
            {
                return ValidationResult.Success; // проверка не требуется, если значение пустое
            }

            string input = value.ToString(); // преобразование значения в строку

            if (System.Text.RegularExpressions.Regex.IsMatch(input, _pattern))
            {
                return ValidationResult.Success; // значение прошло проверку
            }

            return new ValidationResult(ErrorMessage); // значение не прошло проверку, возвращаем ошибку
        }
    }
}
