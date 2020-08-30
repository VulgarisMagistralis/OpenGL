using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
namespace Deneme
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        public static string GetDate()
        {
            return DateTime.Now.ToString();
        }
        public class Person
        {
            public string FirstName;
            public string LastName;
        }
        public static Person getPerson()

        {
            Person p = new Person();
            p.FirstName = "cenk";
            p.LastName = "tuncbilek";
            return p;
        }
    }
}