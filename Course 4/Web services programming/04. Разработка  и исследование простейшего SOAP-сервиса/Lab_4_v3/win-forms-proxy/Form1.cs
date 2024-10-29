using System;
using System.Windows.Forms;

namespace win_forms_proxy
{
    public partial class Form1 : Form
    {
        private readonly Simplex _client;

        public Form1()
        {
            _client = new Simplex();
            InitializeComponent();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            var a1 = new A { s = S1.Text, k = Convert.ToInt32(K1.Text), f = float.Parse(F1.Text) };
            var a2 = new A { s = S2.Text, k = Convert.ToInt32(K2.Text), f = float.Parse(F2.Text) };
            var res = _client.Sum(a1, a2);

            S3.Text = res.s;
            K3.Text = res.k.ToString();
            F3.Text = res.f.ToString();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click_1(object sender, EventArgs e)
        {

        }

        private void label5_Click_1(object sender, EventArgs e)
        {

        }

        private void F2_TextChanged(object sender, EventArgs e)
        {

        }

        private void K2_TextChanged(object sender, EventArgs e)
        {

        }

        private void label3_Click_1(object sender, EventArgs e)
        {

        }

        private void S2_TextChanged(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
