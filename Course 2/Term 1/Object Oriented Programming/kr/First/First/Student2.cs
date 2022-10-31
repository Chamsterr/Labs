using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace First
{
    partial class Student
    {
        public override bool Equals(object obj)
        {
            Student? s = obj as Student;
            if (this.name == s.name && this.course == s.course && this.grupa == s.grupa)
            {
                return true;
            }
            return false;
        }

        public static bool operator !=(Student stud, Student stud2)
        {
            if (stud.grupa != stud2.grupa)
            {
                return true;
            }
            return false;
        }
        public static bool operator ==(Student stud, Student stud2) 
        {
            if (stud.grupa == stud2.grupa)
            {
                return true;
            }
            return false;
        }
    }
}
