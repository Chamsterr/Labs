using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Taskify0._5
{
    internal interface ICommand
    {
        void Execute();
        void Undo();
    }
}
