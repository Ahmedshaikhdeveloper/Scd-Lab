using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CricBuzz
{
    public partial class Form6 : Form
    {
        public Form6()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 newForm = new Form2();
            newForm.Show();
            this.Hide();
        }

        private void button_WOC4_Click(object sender, EventArgs e)
        {

        }

        private void button_WOC5_Click(object sender, EventArgs e)
        {
            Form9 newForm = new Form9();
            newForm.Show();
            this.Hide();
        }

        private void players_Click(object sender, EventArgs e)
        {
            Form7 newForm = new Form7();
            newForm.Show();
            this.Hide();
        }

        private void teams_Click(object sender, EventArgs e)
        {
            Form8 newForm = new Form8();
            newForm.Show();
            this.Hide();
        }
    }
}
