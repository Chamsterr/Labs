using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace WinFormsApp2
{
    public partial class Form2 : Form
    {
        Flights flights = new Flights();
        IEnumerable<Plane> ordered;


        // создаем объект "Создатель"
        SearchOgregator searchOgregator = new SearchOgregator();

        // создаем объект "Опекун" и передаем ему ссылку на "Создателя"
        SearchCaretaker caretaker;

/*        // сохраняем текущее состояние объекта "Создатель" с помощью "Опекуна"
        caretaker.Save();

        // меняем состояние объекта "Создатель"
        searchOgregator.setTextBox1("new value");

        // сохраняем текущее состояние объекта "Создатель" с помощью "Опекуна"
        caretaker.Save();

        // восстанавливаем предыдущее состояние объекта "Создатель" с помощью "Опекуна"
        caretaker.RestorePrevious();*/

        public Form2()
        {
            InitializeComponent();
            DisplayPlanesInRichTextBox(flights.GetStringForPrintByFilters(textBox1, textBox2, textBox4, textBox5));
            ordered = flights.GetFlights();
            caretaker = new SearchCaretaker(searchOgregator);
            caretaker.Save();
            timer1.Start();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged_1(object sender, EventArgs e)
        {
            Search();
        }

        private void label1_Click_1(object sender, EventArgs e)
        {

        }

        private void Search()
        {
            ordered = flights.GetStringForPrintByFilters(textBox1, textBox2, textBox4, textBox5);
            DisplayPlanesInRichTextBox(ordered);
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            Search();
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            Search();
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            Search();
        }

        private void menuStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void годуВыпускаToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ordered = flights.GetStringForPrintByFilters(textBox1, textBox2, textBox4, textBox5).OrderBy(p => p.date);

            DisplayPlanesInRichTextBox(ordered);
        }

        private void датеПоследнегоТехОбслуживанияToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ordered = flights.GetStringForPrintByFilters(textBox1, textBox2, textBox4, textBox5).OrderBy(p => p.TechnicalInspection);

            DisplayPlanesInRichTextBox(ordered);
        }

        private void сохранитьВJSONToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Flights.JsonSerelization(ordered, DateTime.Now.ToString());
            DisplayPlanesInRichTextBox(ordered);

            searchOgregator.setTextBox1(textBox1.Text);
            searchOgregator.setTextBox2(textBox2.Text);
            searchOgregator.setTextBox3(textBox4.Text);
            searchOgregator.setTextBox4(textBox5.Text);

            caretaker.Save();
        }

        private void DisplayPlanesInRichTextBox(IEnumerable<Plane> planes)
        {
            StringBuilder sb = new StringBuilder();
            if (planes != null)
            {
                foreach (Plane plane in planes)
                {
                    sb.Append(plane.ToString());
                }
                richTextBox1.Text = sb.ToString();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (!menuStrip1.Visible)
                button1.Text = "+";
            else
            {
                button1.Text = "-";
            }
            menuStrip1.Visible = !menuStrip1.Visible;
        }

        private void очиститьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
            textBox2.Text = "";
            textBox5.Text = "";
            textBox4.Text = "";
        }

        private void удалитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            flights.Delete();
            ordered = flights.GetFlights();
            DisplayPlanesInRichTextBox(ordered);
            
        }

        private void назадToolStripMenuItem_Click(object sender, EventArgs e)
        {
            caretaker.RestorePrevious();
            textBox1.Text = searchOgregator.getTextBox1();
            textBox2.Text = searchOgregator.getTextBox2();
            textBox4.Text = searchOgregator.getTextBox3();
            textBox5.Text = searchOgregator.getTextBox4();
        }

        private void впередToolStripMenuItem_Click(object sender, EventArgs e)
        {
            caretaker.RestoreNext();
            textBox1.Text = searchOgregator.getTextBox1();
            textBox2.Text = searchOgregator.getTextBox2();
            textBox4.Text = searchOgregator.getTextBox3();
            textBox5.Text = searchOgregator.getTextBox4();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = $"Текущее время: {DateTime.Now}";
            toolStripStatusLabel2.Text = $"Текущее кол-во элементов {ordered.Count()}";
        }

        private void toolStripStatusLabel2_Click(object sender, EventArgs e)
        {

        }

        private void textBox4_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!Char.IsDigit(e.KeyChar) && e.KeyChar != '\b')
            {
                e.Handled = true;
            }
        }
        private void textBox5_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!Char.IsDigit(e.KeyChar) && e.KeyChar != '\b')
            {
                e.Handled = true;
            }
        }
    }
}
