using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace WinFormsApp2
{
    internal class SearchMemento
    {

        private string textBox1Text;
        private string textBox2Text;
        private string textBox3Text;
        private string textBox4Text;

        public string getTextBox1()
        {
            return textBox1Text;
        }

        public string getTextBox2()
        {
            return textBox2Text;
        }

        public string getTextBox3()
        {
            return textBox3Text;
        }

        public string getTextBox4()
        {
            return textBox4Text;
        }
        public SearchMemento(string text1, string text2, string text3, string text4)
        {
            this.textBox1Text = text1;
            this.textBox2Text = text2;
            this.textBox3Text = text3;
            this.textBox4Text = text4;
        }
    }

    internal class SearchOgregator
    {
        private string textBox1Text;
        private string textBox2Text;
        private string textBox3Text;
        private string textBox4Text;

        public void setTextBox1(string text)
        {
            textBox1Text = text;
        }

        public void setTextBox2(string text)
        {
            textBox2Text = text;
        }

        public void setTextBox3(string text)
        {   
            textBox3Text = text;
        }

        public void setTextBox4(string text)
        {
            textBox4Text = text;
        }
        public string getTextBox1()
        {
            return textBox1Text;
        }

        public string getTextBox2()
        {
            return textBox2Text;
        }

        public string getTextBox3()
        {
            return textBox3Text;
        }

        public string getTextBox4()
        {
            return textBox4Text;
        }

        public SearchMemento Save()
        {
            return new SearchMemento(textBox1Text, textBox2Text, textBox3Text, textBox4Text);
        }
        public void Restore(SearchMemento memento)
        {
            this.textBox1Text = memento.getTextBox1();
            this.textBox2Text = memento.getTextBox2();
            this.textBox3Text = memento.getTextBox3();
            this.textBox4Text = memento.getTextBox4();
        }

    }

    class SearchCaretaker
    {
        private SearchOgregator searchOgregator;
        private List<SearchMemento> history = new List<SearchMemento>();
        private int currentIndex = -1;

        public SearchCaretaker(SearchOgregator searchOgregator)
        {
            this.searchOgregator = searchOgregator;
        }

        public void Save()
        {
            var memento = searchOgregator.Save();
            history.Add(memento);
            currentIndex++;
        }

        public void RestorePrevious()
        {
            if (currentIndex > 0)
            {
                currentIndex--;
                var memento = history[currentIndex];
                searchOgregator.Restore(memento);
            }
        }

        public void RestoreNext()
        {
            if (currentIndex < history.Count - 1)
            {
                currentIndex++;
                var memento = history[currentIndex];
                searchOgregator.Restore(memento);
            }
        }
    }
}
