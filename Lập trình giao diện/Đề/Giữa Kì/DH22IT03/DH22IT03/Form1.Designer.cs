namespace DH22IT03
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.tsmi_hethong = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmi_trochoi = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmi_ve = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmi_exit = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmi_hethong});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1067, 25);
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // tsmi_hethong
            // 
            this.tsmi_hethong.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmi_trochoi,
            this.tsmi_ve,
            this.toolStripSeparator1,
            this.tsmi_exit});
            this.tsmi_hethong.Name = "tsmi_hethong";
            this.tsmi_hethong.Size = new System.Drawing.Size(74, 21);
            this.tsmi_hethong.Text = "Hệ thống";
            // 
            // tsmi_trochoi
            // 
            this.tsmi_trochoi.Name = "tsmi_trochoi";
            this.tsmi_trochoi.Size = new System.Drawing.Size(180, 22);
            this.tsmi_trochoi.Text = "Trò chơi";
            this.tsmi_trochoi.Click += new System.EventHandler(this.tsmi_trochoi_Click);
            // 
            // tsmi_ve
            // 
            this.tsmi_ve.Name = "tsmi_ve";
            this.tsmi_ve.Size = new System.Drawing.Size(180, 22);
            this.tsmi_ve.Text = "Vẽ";
            this.tsmi_ve.Click += new System.EventHandler(this.tsmi_ve_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(177, 6);
            // 
            // tsmi_exit
            // 
            this.tsmi_exit.Name = "tsmi_exit";
            this.tsmi_exit.Size = new System.Drawing.Size(180, 22);
            this.tsmi_exit.Text = "Thoát";
            this.tsmi_exit.Click += new System.EventHandler(this.tsmi_exit_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1067, 554);
            this.Controls.Add(this.menuStrip1);
            this.DoubleBuffered = true;
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menuStrip1;
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "Form1";
            this.Text = "MSSV - HoVaTen";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form_FormClosing);
            this.Resize += new System.EventHandler(this.Form_Resize);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem tsmi_hethong;
        private System.Windows.Forms.ToolStripMenuItem tsmi_trochoi;
        private System.Windows.Forms.ToolStripMenuItem tsmi_ve;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem tsmi_exit;
    }
}

