using static System.Runtime.InteropServices.JavaScript.JSType;

namespace _01._WinForm
{
    public partial class Form1 : Form
    {
        TextBox lastUsedTextBox;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Calculator.ChangeOperation(Operation.Add);
            textBox2.Text = "+";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Calculator.ChangeOperation(Operation.Divide);
            textBox2.Text = "/";
        }

        private void button5_Click_1(object sender, EventArgs e)
        {
            try
            {
                textBox1.BackColor = Color.White;
                textBox3.BackColor = Color.White;
                textBox4.Text = double.IsNaN(Calculator.equal(textBox1, textBox3)) ? "": Calculator.equal(textBox1, textBox3).ToString();
            }
            catch
            {
                MessageBox.Show("Проверьте правильность введенной информации");
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Calculator.ChangeOperation(Operation.Subtract);
            textBox2.Text = "-";
        }

        private void button8_Click_1(object sender, EventArgs e)
        {
            Calculator.ChangeOperation(Operation.Reminder);
            textBox2.Text = "%";
        }

        private void button7_Click_1(object sender, EventArgs e)
        {
            Calculator.ChangeOperation(Operation.Celochislenoe);
            textBox2.Text = "//";
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Calculator.ChangeOperation(Operation.Multiply);
            textBox2.Text = "*";
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            textBox4.Text = "";
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            textBox4.Text = "";
        }

        private void button6_Click_1(object sender, EventArgs e)
        {
            textBox1.BackColor = Color.White;
            textBox3.BackColor = Color.White;
            textBox4.Text = "";
            textBox3.Text = "";
            textBox1.Text = "";
        }

        private void button10_Click(object sender, EventArgs e)
        {
            lastUsedTextBox.Text = Calculator.GetMemory().ToString();
        }

        private void button9_Click(object sender, EventArgs e)
        {
            try
            {
                Calculator.ChangeMemory(Convert.ToDouble(textBox4.Text));
            }
            catch(System.FormatException ex)
            {
                MessageBox.Show("Нечего сохранять в память");
                return;
            }
            MessageBox.Show($"{textBox4.Text} сохранено в память");
        }

        private void Change(object sender, EventArgs e)
        {
            lastUsedTextBox = sender as TextBox;
        }

        private void button11_Click(object sender, EventArgs e)
        {
            lastUsedTextBox.Text = (-Calculator.GetMemory()).ToString();
        }
        private void Check(object sender, EventArgs e)
        {
            double value1, value2;
            textBox1.BackColor = Color.White;
            textBox3.BackColor = Color.White;
            bool valid1 = double.TryParse(textBox1.Text, out value1);
            bool valid2 = double.TryParse(textBox3.Text, out value2);

            if (!valid1 || !valid2 || value1 % 1 != 0 || value2 % 1 != 0)
            {
                if (!valid1 && textBox1.Text != "") textBox1.BackColor = Color.Red;
                if (!valid2 && textBox3.Text != "") textBox3.BackColor = Color.Red;
                if (value1 % 1 != 0) textBox1.BackColor = Color.Red;
                if (value2 % 1 != 0) textBox3.BackColor = Color.Red;
            }
        }

        private void button12_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Ира");
        }
    }
}