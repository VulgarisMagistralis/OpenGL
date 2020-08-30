using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.Globalization;
using System.Globalization;
using System.Diagnostics;
using System.Timers;



namespace WebApplication2
{

    public partial class WebForm2 : System.Web.UI.Page
    {
        protected void Timer1_Tick(object sender, EventArgs e)
        {
            lbltime.Text = "TIME:" +
              DateTime.Now.ToLongTimeString();
        }
        protected void Page_Load(object sender, EventArgs e)
        {
            //klimanin veri aldigina dair bir resim ?
            Refresh();
                             
           
        }
        protected void Timer2(object sender, EventArgs e)
        {
            TimeSpan add = new TimeSpan(0, 30 * int.Parse(hdnTime.Value), 0);
            TimeSpan time = TimeSpan.Parse(hdnSettime.Value);
            lblTimereq.Text = time.Add(add).Subtract(TimeSpan.Parse(DateTime.Now.ToShortTimeString())).ToString();
            if (time.Add(add).ToString() == DateTime.Now.ToShortTimeString())
            {
                if (btnSlp.Enabled == true)

                    OffClick();
                else

                    OnClick();
            }                      
        }
        protected void btnOn_Click(object sender, EventArgs e)
        {
            OnClick();
        }
        protected void btnOff_Click(object sender, EventArgs e){
            OffClick();    
        }  
        protected void btnMode_Click(object sender, EventArgs e)
        {
            int i = int.Parse(hdnMode.Value);        
            switch (i)
            {
                case 1:
                    lblMode.Text = "MODE 1";
                    break;
                case 2:
                    lblMode.Text = "MODE 2";
                    break;
                case 3:
                    lblMode.Text = "MODE 3";
                    break;
                case 4:
                    lblMode.Text = "MODE 4";
                    break;
                default:
                    lblMode.Text = "MODE 5";
                    break;

            }
            i++;
            hdnMode.Value = i.ToString();
            if (i == 6)
            {
                i = 1;
                hdnMode.Value = i.ToString();
            }
        }
        protected void btnFan_Click(object sender, EventArgs e)
        {

            int i = int.Parse(hdnFan.Value);

            switch (i)
            {
                case 1:
                    lblFan.Text = "LOW";
                    break;
                case 2:
                    lblFan.Text = "MED";
                    break;
                case 3:
                    lblFan.Text = "HIGH";
                    break;
                default:
                    lblFan.Text = "AUTO";
                    break;

            }
            i++;
            hdnFan.Value = i.ToString();
            if (i == 5)
            {
                i = 1;
                hdnFan.Value = i.ToString();
            }
        }
        protected void turbo_Click(object sender, EventArgs e)
        {

        }
        protected void btnInc_Click(object sender, EventArgs e)
        {
            int i = int.Parse(hdnTime.Value);
            if (int.Parse(hdnSwitch.Value) == 1)
            {
                i++;
                hdnTime.Value = i.ToString();
            }
            else
            {
                int T = Convert.ToInt32(hdnTemp.Value);
                T++;
                hdnTemp.Value = T.ToString();
                Refresh();
               
            }
        }                                                  
        protected void btnDec_Click(object sender, EventArgs e)
        {
            int d = int.Parse(hdnTime.Value);
            if (int.Parse(hdnSwitch.Value) == 1)
            {
                d++;
                hdnTime.Value = d.ToString();
            }
            else
            {
                int T = Convert.ToInt32(hdnTemp.Value);
                T--;
                hdnTemp.Value = T.ToString();
                Refresh();
                
            }
        }
        protected void btnTmp_Click(object sender, EventArgs e)
        {
          //TEMP butonu icin resimleri ayarla.    
        }
        protected void btnXfan_Click(object sender, EventArgs e)
        {
               
                string y = hdnXfan.Value;  

                if (y == "XFAN")
                {
                    lblXfan.Text = "XFAN";
                    hdnXfan.Value = " ";
                }
                else 
                {
                    lblXfan.Text = " ";
                    hdnXfan.Value = "XFAN";
                }
            
        }
        protected void btnHor_Click(object sender, EventArgs e)
        {
            //resim eklencek veya kaldirilacak 
            Page_Load(null,new EventArgs());
        }
        protected void btnVer_Click(object sender, EventArgs e)
        {
            //resim eklencek veya kaldirilacak 
            Page_Load(null,new EventArgs());    
        }
        protected void btnLit_Click(object sender, EventArgs e)
        {
            //resim eklencek veya kaldirilacak 
            Page_Load(null,new EventArgs());
        }
        protected void btnHel_Click(object sender, EventArgs e)
        {
            string y = hdnHel.Value;

            if (y == "HEALTH")
            {
                lblHel.Text = "HEALTH";
                hdnHel.Value = " ";
            }
            else
            {
                lblHel.Text = " ";
                hdnHel.Value = "HEALTH";
            }
        }
        protected void btnSlp_Click(object sender, EventArgs e)
        {
            //resim eklencek veya kaldirilacak 
            Page_Load(null, new EventArgs());
        }
        protected void btnTimer_Click(object sender, EventArgs e)
        {
            int k =int.Parse(hdnSwitch.Value);
            k++;
            hdnSwitch.Value = k.ToString();
            if (k > 2)
            {
                k = 0;
                hdnSwitch.Value = k.ToString();
            }
            if (k == 2)
            {
                hdnSettime.Value = DateTime.Now.ToShortTimeString();
            }
        }
        private void OnClick()
        {
            btnMode.Enabled = true;
            btnFan.Enabled = true;
            turbo.Enabled = true;
            btnInc.Enabled = true;
            btnDec.Enabled = true;
            btnTmp.Enabled = true;
            btnXfan.Enabled = true;
            btnHor.Enabled = true;
            btnVer.Enabled = true;
            btnLit.Enabled = true;
            btnHel.Enabled = true;
            btnSlp.Enabled = true;
            btnTime.Enabled = true;
        }
        private void OffClick()
        {
            btnMode.Enabled = false;
            btnFan.Enabled = false;
            turbo.Enabled = false;
            btnInc.Enabled = false;
            btnDec.Enabled = false;
            btnTmp.Enabled = false;
            btnXfan.Enabled = false;
            btnHor.Enabled = false;
            btnVer.Enabled = false;
            btnLit.Enabled = false;
            btnHel.Enabled = false;
            btnSlp.Enabled = false;
            btnTime.Enabled = false;
        }
        public string Time { get; set;}

        private void Refresh()
        {
            curTemp.Text = hdnTemp.Value;
        }
    }
}