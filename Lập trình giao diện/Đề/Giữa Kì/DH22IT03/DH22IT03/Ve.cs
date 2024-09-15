using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DH22IT03
{
    public partial class Ve : Form
    {
        public Ve()
        {
            InitializeComponent();
        }

        private void Ve_Resize(object sender, EventArgs e)
        {
            Invalidate();
        }

        private void Ve_Paint(object sender, PaintEventArgs e)
        {
            int hetght = ClientRectangle.Height;
            int width = ClientRectangle.Width;
            Image img = Image.FromFile("img.png");
            e.Graphics.DrawImage(img, 0, 0, width / 2, hetght / 2);
            img.RotateFlip(RotateFlipType.RotateNoneFlipX);
            e.Graphics.DrawImage(img, width / 2, 0, width / 2, hetght / 2);
            //Vẽ chữ nhật hologram
            Point[] a =
            {
                new Point(0,hetght/2),
                new Point(width,hetght/2),
                new Point(width,hetght),
                new Point(0,hetght)
            };
            Color[] c =
            {
                Color.Orange,
                Color.Orange,
                Color.Orange,
                Color.Orange
            };
            PathGradientBrush pb = new PathGradientBrush(a);
            pb.CenterColor = Color.White;
            pb.SurroundColors = c;
            e.Graphics.FillPolygon(pb, a);
            //Vẽ chữ
            Rectangle reg = new Rectangle(0, hetght / 2, width, hetght / 2);
            Font f = new Font("Arial", 36, FontStyle.Bold);
            StringFormat sf = new StringFormat();
            sf.Alignment = StringAlignment.Center;
            sf.LineAlignment = StringAlignment.Center;
            HatchBrush hb = new HatchBrush(HatchStyle.DiagonalCross, Color.Green, Color.Red);
            e.Graphics.DrawString("Konnn Dep Zai",f,hb,reg,sf);
        }
    }
}
