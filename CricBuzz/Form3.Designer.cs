
namespace CricBuzz
{
    partial class Form3
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form3));
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.upuser = new System.Windows.Forms.Button();
            this.inuser = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox1.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("pictureBox1.BackgroundImage")));
            this.pictureBox1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pictureBox1.Location = new System.Drawing.Point(124, 24);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(527, 144);
            this.pictureBox1.TabIndex = 3;
            this.pictureBox1.TabStop = false;
            // 
            // upuser
            // 
            this.upuser.BackColor = System.Drawing.Color.SeaGreen;
            this.upuser.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.upuser.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.upuser.ForeColor = System.Drawing.Color.White;
            this.upuser.Location = new System.Drawing.Point(282, 275);
            this.upuser.Name = "upuser";
            this.upuser.Size = new System.Drawing.Size(208, 35);
            this.upuser.TabIndex = 7;
            this.upuser.Text = "Sign Up";
            this.upuser.UseVisualStyleBackColor = false;
            this.upuser.Click += new System.EventHandler(this.upuser_Click);
            // 
            // inuser
            // 
            this.inuser.BackColor = System.Drawing.Color.SeaGreen;
            this.inuser.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.inuser.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.inuser.ForeColor = System.Drawing.Color.White;
            this.inuser.Location = new System.Drawing.Point(282, 219);
            this.inuser.Name = "inuser";
            this.inuser.Size = new System.Drawing.Size(208, 35);
            this.inuser.TabIndex = 6;
            this.inuser.Text = "Sign In";
            this.inuser.UseVisualStyleBackColor = false;
            this.inuser.Click += new System.EventHandler(this.inuser_Click);
            // 
            // Form3
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(749, 426);
            this.Controls.Add(this.upuser);
            this.Controls.Add(this.inuser);
            this.Controls.Add(this.pictureBox1);
            this.Name = "Form3";
            this.Text = "Form3";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button upuser;
        private System.Windows.Forms.Button inuser;
    }
}