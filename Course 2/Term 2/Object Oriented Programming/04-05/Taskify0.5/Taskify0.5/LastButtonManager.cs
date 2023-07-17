using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace Taskify0._5
{
    internal class LastButtonManager : ICommand
    {
        private Stack<Button> undoStack = new Stack<Button>();
        private Stack<Button> redoStack = new Stack<Button>();

        public Button button;

        public void Execute()
        {
            if(undoStack.Count != 0 && redoStack.Count != 0 && button.Content.ToString() != undoStack.Peek().Content.ToString())
            {
                redoStack.Push(button);
            }

            else if (button != null)
            {
                if (redoStack.Count == 0)
                {
                    redoStack.Push(button);
                }
                else if (redoStack.Peek().Content.ToString() != button.Content.ToString())
                {
                    redoStack.Push(button);
                }
            }

        }
        public void Undo()
        {
            if (undoStack.Count > 0)
            {
                button = undoStack.Pop();
                redoStack.Push(button);
            }
        }

        public void Redo()
        {
            if (redoStack.Count > 0)
            {
                button = redoStack.Pop();
                undoStack.Push(button);
                if (redoStack.Count > 0)
                {
                    button = redoStack.Pop();
                }
            }
            else
            {
                undoStack.Push(button);
            }
        }
    }
}
