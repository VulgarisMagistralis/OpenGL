using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Deneme.Handler
{
    /// <summary>
    /// Summary description for Post
    /// </summary>
    public class Post : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            var ad = context.Request["ad"];
            var soyad = context.Request["soyad"];
            var dus = context.Request["dus"];
            context.Response.Write(ad + " " + soyad + " " + dus);
        }

        public bool IsReusable
        {
            get
            {
                return false;
            }
        }
    }
}