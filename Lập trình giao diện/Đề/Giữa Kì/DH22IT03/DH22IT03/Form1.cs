using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DH22IT03
{
    public partial class Form1 : System.Windows.Forms.Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void tsmi_exit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Form_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (MessageBox.Show("Xác nhận đóng app?","Cảnh báo",MessageBoxButtons.YesNo,MessageBoxIcon.Warning) 
                == DialogResult.No)
            {
                e.Cancel = true;
            }
        }

        private void Form_Resize(object sender, EventArgs e)
        {
            Invalidate();
        }

        private void tsmi_trochoi_Click(object sender, EventArgs e)
        {
            Game f = new Game();
            f.MdiParent = this;
            f.Show();
        }

        private void tsmi_ve_Click(object sender, EventArgs e)
        {
            Ve f = new Ve();
            f.MdiParent = this;
            f.Show();
        }
    }
}
