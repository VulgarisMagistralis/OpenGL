using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.Handlers;


namespace Deneme
{
    public partial class deneme2 : System.Web.UI.Page
    {    [System.Web.Services.WebMethod]
        protected void Page_Load(object sender, EventArgs e)
        {

        }


    [System.Web.Services.WebMethod]
    public static string GetCurrentTime(string name)
    {
        return "Hello " + name + Environment.NewLine + "The Current Time is: "
            + DateTime.Now.ToString();
    }
       
    }
}