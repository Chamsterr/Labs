using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Taskify0._5
{
    internal class ToDoManager : ICommand
    {
        private readonly List<ToDo> _tasks;
        private readonly ToDo _task;

        public ToDoManager(List<ToDo> tasks, ToDo task)
        {
            _tasks = tasks;
            _task = task;
        }
        public void Execute()
        {
            _tasks.Add(_task);
        }

        public void Undo()
        {
            _tasks.Remove(_task);
        }
    }
}
