using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WinFormsApp2
{
    public class TechnicalServiceDateAttribute : ValidationAttribute
    {
        private readonly string _datePropertyName;

        private readonly string _creationDatePropertyName;

        public TechnicalServiceDateAttribute(string creationDatePropertyName)
        {
            _creationDatePropertyName = creationDatePropertyName;
        }
        public TechnicalServiceDateAttribute(string creationDatePropertyName, string datePropertyName)
        {
            _creationDatePropertyName = creationDatePropertyName;
            _datePropertyName = datePropertyName;
        }
        protected override ValidationResult IsValid(object value, ValidationContext validationContext)
        {
            if (value is DateTime date)
            {
                if (date < DateTime.Now.AddYears(-10))
                {
                    return new ValidationResult("The technical service date is more than 10 years ago.");
                }

                var creationDateProperty = validationContext.ObjectType.GetProperty(_creationDatePropertyName);
                if (creationDateProperty == null)
                {
                    throw new ArgumentException("Property with this name not found", _creationDatePropertyName);
                }

                var creationDate = (DateTime)creationDateProperty.GetValue(validationContext.ObjectInstance, null);
                if (date < creationDate)
                {
                    return new ValidationResult("The technical service date is before the creation date.");
                }

                return ValidationResult.Success;
            }

            return new ValidationResult("Invalid date format.");
        }
        
    }
}