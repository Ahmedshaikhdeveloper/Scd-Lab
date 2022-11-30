using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace CricBuzz
{ 
    public partial class Form4 : Form
    {
        Enderuser user = new Enderuser();

        public Form4()
        {
            InitializeComponent();
        }

        private void upuser2_Click(object sender, EventArgs e)
        {
            FileInfo file = new FileInfo(@"C:\Users\muham\OneDrive\Desktop\CricBuzz OOP\regg.txt");
            StreamWriter writer = file.CreateText();
            writer.WriteLine(textBox1.Text);
            writer.WriteLine(textBox2.Text);
            writer.WriteLine(textBox3.Text);
            writer.Close();

            Form6 newForm = new Form6();
            newForm.Show();
            this.Hide();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            //FileInfo file = new FileInfo(@"C:\Users\muham\OneDrive\Desktop\CricBuzz OOP\reg.txt");
            user.name1 = "";
            user.name1 = textBox1.Text;
            //StreamWriter writer = file.CreateText();
            //writer.WriteLine(textBox1.Text);


        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            user.email = "";
            user.email = textBox2.Text;
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            user.pass = "";
            user.pass = textBox3.Text;
        }
    }
}
