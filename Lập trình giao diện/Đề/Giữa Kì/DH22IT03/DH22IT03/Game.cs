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
    public partial class Game : Form
    {
        public Game()
        {
            InitializeComponent();
        }
        private Random rd = new Random();
        private void Game_Load(object sender, EventArgs e)
        {
            initGame();
        }

        private void initGame()
        {
            pic1.Image = Image.FromFile("xucxac/6.png");
            pic2.Image = Image.FromFile("xucxac/6.png");
            pic3.Image = Image.FromFile("xucxac/6.png");
            pic1.SizeMode = PictureBoxSizeMode.StretchImage;
            pic2.SizeMode = PictureBoxSizeMode.StretchImage;
            pic3.SizeMode = PictureBoxSizeMode.StretchImage;
            listView1.Items.Clear();
        }

        private void btn_quay_Click(object sender, EventArgs e)
        {
            int[] a = { 0, 0, 0, 0, 0, 0 };
            int r = rd.Next(1, 7);
            a[r - 1]++;
            pic1.Image = Image.FromFile(String.Format("xucxac/{0}.png",r));
            r = rd.Next(1, 7);
            a[r - 1]++;
            pic2.Image = Image.FromFile(String.Format("xucxac/{0}.png", r));
            r = rd.Next(1, 7);
            a[r - 1]++;
            pic3.Image = Image.FromFile(String.Format("xucxac/{0}.png", r));
            //Tạo list
            ListViewItem t = new ListViewItem(String.Format("{0:00}",listView1.Items.Count+1));
            foreach(int i in a)
            {
                t.SubItems.Add(i <= 0 ? "" : i.ToString());
            }
            listView1.Items.Add(t);
            listView1.Items[listView1.Items.Count - 1].EnsureVisible();
        }

        private void btn_xoa_Click(object sender, EventArgs e)
        {
            initGame();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            label1.Text = label1.Text.Substring(label1.Text.Length - 1) + label1.Text.Substring(0, label1.Text.Length-1);
        }
    }
}
