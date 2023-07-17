using System.Text.Json;
using System;
using Newtonsoft.Json;
using System.Text;
using System.ComponentModel.DataAnnotations;
using System.Numerics;

namespace WinFormsApp2
{
    public partial class Form1 : Form
    {
        string filePath = "plane.json";
        Flights flights;
        public Form1()
        {
            flights = new Flights();
            InitializeComponent();
        }
        
        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!Char.IsDigit(e.KeyChar) && e.KeyChar != '\b')
            {
                e.Handled = true;
            }
        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            label6.Text = "Пассажирские места - " + trackBar1.Value.ToString(); // обновляем текст Label значениями трекбара

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void trackBar2_Scroll(object sender, EventArgs e)
        {
            label7.Text = "Грузоподъемность - " + trackBar2.Value.ToString(); // обновляем текст Label значениями трекбара

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Plane pl = new Plane(textBox1.Text, comboBox1.Text, comboBox2.Text, listBox1.Text, trackBar1.Value, trackBar2.Value, dateTimePicker2.Value, dateTimePicker1.Value);
            // Выполняем валидацию данных с помощью атрибутов
            var validationContext = new ValidationContext(pl, null, null);
            var validationResults = new List<ValidationResult>();
            bool isValid = Validator.TryValidateObject(pl, validationContext, validationResults, true);

            // Если данные не прошли валидацию, выводим сообщения об ошибках
            if (!isValid)
            {
                string errorMessage = "";
                foreach (var result in validationResults)
                {
                    errorMessage += result.ErrorMessage + "\n";
                }
                MessageBox.Show(errorMessage, "Ошибка валидации данных", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                flights.AddFlight(pl);
                Flights.JsonSerelization(flights.GetFlights());
            }
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
        
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form2 form2 = new Form2();
            form2.Owner = this;
            form2.Show();
        }

        private void textBox2_TextChanged_1(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label11_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Ковкель Никита Викторович, version 1.01");
        }

        private void label11_Click_1(object sender, EventArgs e)
        {
            MessageBox.Show("Ковкель Никита Викторович version 1.01");
        }

        private void оПрограммеToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Ковкель Никита Викторович Version 1.01");
        }

        private void модельToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void грузоподъесностьToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void dateTimePicker2_ValueChanged(object sender, EventArgs e)
        {

        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {

        }

        private void поискToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 form2 = new Form2();
            form2.Show();
        }
    }
}