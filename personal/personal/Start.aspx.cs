using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace personal
{
    public partial class per : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected static string GetTime()
        {
            return DateTime.Now.ToLongTimeString();
        }
        protected static string GetDate()
        {
            return DateTime.Now.ToLongDateString();
        }
    }
}