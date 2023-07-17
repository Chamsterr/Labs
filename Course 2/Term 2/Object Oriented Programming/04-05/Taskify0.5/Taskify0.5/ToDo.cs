using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Taskify0._5
{
    internal class ToDo
    {
        private string title;
        public string description { get; set; }
        public string category { get; set; }
        public bool isComplete { get; set; }
        public ToDo(string title, string category, bool isComplete)
        {
            this.title = title;
            /*description = "я десприктион к задачe";*/
            this.category = category;
            this.isComplete = isComplete;
        }

        public override string ToString()
        {
            return this.title;
        }
    }
}
