using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Services;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Deneme
{
    public partial class ajax_post_2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
          
        }
        [WebMethod]
        public static string GetDate()
        {
            return DateTime.Now.ToString();
        }
        [WebMethod]
        public static string GetName()
        {
            var ad = HttpContext.Current.Request.QueryString["ad"];
            string message = "merhaba" + " " + ad;
            return message;
        }
    }
}