using System.Text.Json;
using System;
using Newtonsoft.Json;
using System.Text;

namespace WinFormsApp2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
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
            label6.Text = "������������ ����� - " + trackBar1.Value.ToString(); // ��������� ����� Label ���������� ��������

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void trackBar2_Scroll(object sender, EventArgs e)
        {
            label7.Text = "���������������� - " + trackBar2.Value.ToString(); // ��������� ����� Label ���������� ��������

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Plane pl = new Plane(textBox1.Text, comboBox1.Text, comboBox2.Text, listBox1.Text, trackBar1.Value, trackBar2.Value, dateTimePicker1.Value);
            string json = JsonConvert.SerializeObject(pl, Formatting.Indented);
            byte[] bytes = Encoding.UTF8.GetBytes(json);
            using (FileStream stream = new FileStream("plane.json", FileMode.Create))
            {
                stream.Write(bytes, 0, bytes.Length);
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
            string filePath = "plane.json";

            // ������ ����������� �����
            string json = File.ReadAllText(filePath);

            // �������������� �������
            Plane pl = JsonConvert.DeserializeObject<Plane>(json);
        
            MessageBox.Show(json);
        }

        private void textBox2_TextChanged_1(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label11_Click(object sender, EventArgs e)
        {
            MessageBox.Show("������� ������ ����������, version 1.01");
        }
    }
}