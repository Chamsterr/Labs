namespace win_forms
{
    partial class Form1
    {
        private System.ComponentModel.IContainer components = null;
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.S1 = new System.Windows.Forms.TextBox();
            this.K1 = new System.Windows.Forms.TextBox();
            this.F1 = new System.Windows.Forms.TextBox();
            this.S2 = new System.Windows.Forms.TextBox();
            this.K2 = new System.Windows.Forms.TextBox();
            this.F2 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.F3 = new System.Windows.Forms.TextBox();
            this.K3 = new System.Windows.Forms.TextBox();
            this.S3 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // S1
            // 
            this.S1.Location = new System.Drawing.Point(99, 62);
            this.S1.Margin = new System.Windows.Forms.Padding(4);
            this.S1.Name = "S1";
            this.S1.Size = new System.Drawing.Size(132, 22);
            this.S1.TabIndex = 0;
            // 
            // K1
            // 
            this.K1.Location = new System.Drawing.Point(99, 92);
            this.K1.Margin = new System.Windows.Forms.Padding(4);
            this.K1.Name = "K1";
            this.K1.Size = new System.Drawing.Size(132, 22);
            this.K1.TabIndex = 1;
            // 
            // F1
            // 
            this.F1.Location = new System.Drawing.Point(99, 125);
            this.F1.Margin = new System.Windows.Forms.Padding(4);
            this.F1.Name = "F1";
            this.F1.Size = new System.Drawing.Size(132, 22);
            this.F1.TabIndex = 2;
            // 
            // S2
            // 
            this.S2.Location = new System.Drawing.Point(324, 65);
            this.S2.Margin = new System.Windows.Forms.Padding(4);
            this.S2.Name = "S2";
            this.S2.Size = new System.Drawing.Size(132, 22);
            this.S2.TabIndex = 3;
            this.S2.TextChanged += new System.EventHandler(this.S2_TextChanged);
            // 
            // K2
            // 
            this.K2.Location = new System.Drawing.Point(324, 98);
            this.K2.Margin = new System.Windows.Forms.Padding(4);
            this.K2.Name = "K2";
            this.K2.Size = new System.Drawing.Size(132, 22);
            this.K2.TabIndex = 4;
            this.K2.TextChanged += new System.EventHandler(this.K2_TextChanged);
            // 
            // F2
            // 
            this.F2.Location = new System.Drawing.Point(324, 130);
            this.F2.Margin = new System.Windows.Forms.Padding(4);
            this.F2.Name = "F2";
            this.F2.Size = new System.Drawing.Size(132, 22);
            this.F2.TabIndex = 5;
            this.F2.TextChanged += new System.EventHandler(this.F2_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(32, 59);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(49, 16);
            this.label1.TabIndex = 6;
            this.label1.Text = "string s";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(257, 68);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(14, 16);
            this.label2.TabIndex = 7;
            this.label2.Text = "+";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(257, 101);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(14, 16);
            this.label3.TabIndex = 8;
            this.label3.Text = "+";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(32, 92);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(30, 16);
            this.label4.TabIndex = 9;
            this.label4.Text = "int k";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(257, 130);
            this.label5.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(14, 16);
            this.label5.TabIndex = 10;
            this.label5.Text = "+";
            this.label5.Click += new System.EventHandler(this.label5_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(32, 124);
            this.label6.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(38, 16);
            this.label6.TabIndex = 11;
            this.label6.Text = "float f";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(501, 133);
            this.label7.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(14, 16);
            this.label7.TabIndex = 17;
            this.label7.Text = "=";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(501, 105);
            this.label8.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(14, 16);
            this.label8.TabIndex = 16;
            this.label8.Text = "=";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(501, 71);
            this.label9.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(14, 16);
            this.label9.TabIndex = 15;
            this.label9.Text = "=";
            // 
            // F3
            // 
            this.F3.Location = new System.Drawing.Point(568, 133);
            this.F3.Margin = new System.Windows.Forms.Padding(4);
            this.F3.Name = "F3";
            this.F3.Size = new System.Drawing.Size(132, 22);
            this.F3.TabIndex = 14;
            // 
            // K3
            // 
            this.K3.Location = new System.Drawing.Point(568, 101);
            this.K3.Margin = new System.Windows.Forms.Padding(4);
            this.K3.Name = "K3";
            this.K3.Size = new System.Drawing.Size(132, 22);
            this.K3.TabIndex = 13;
            // 
            // S3
            // 
            this.S3.Location = new System.Drawing.Point(568, 68);
            this.S3.Margin = new System.Windows.Forms.Padding(4);
            this.S3.Name = "S3";
            this.S3.Size = new System.Drawing.Size(132, 22);
            this.S3.TabIndex = 12;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(260, 216);
            this.button1.Margin = new System.Windows.Forms.Padding(4);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(227, 28);
            this.button1.TabIndex = 18;
            this.button1.Text = "Send";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.Button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(783, 287);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.F3);
            this.Controls.Add(this.K3);
            this.Controls.Add(this.S3);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.F2);
            this.Controls.Add(this.K2);
            this.Controls.Add(this.S2);
            this.Controls.Add(this.F1);
            this.Controls.Add(this.K1);
            this.Controls.Add(this.S1);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox S1;
        private System.Windows.Forms.TextBox K1;
        private System.Windows.Forms.TextBox F1;
        private System.Windows.Forms.TextBox S2;
        private System.Windows.Forms.TextBox K2;
        private System.Windows.Forms.TextBox F2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox F3;
        private System.Windows.Forms.TextBox K3;
        private System.Windows.Forms.TextBox S3;
        private System.Windows.Forms.Button button1;
    }
}

