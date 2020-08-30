<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="HandlerPost.aspx.cs" Inherits="Deneme.HandlerPost" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
        <script src="/scripts/jquery-1.11.3.min.js" type="text/javascript"></script>
    <script>
        $(document).ready(function () {
          
            $("#btnSub").click(function () {
                var formData = new FormData();
                formData.append("ad", $('#ad').val());
                formData.append("soyad", $('#soyad').val());
                formData.append("dus", $('#dus').val());
                $.ajax({
                    type: "POST",
                    url: '/Handler/Post.ashx',
                    data: formData,
                    contentType: false,
                    processData:false,
                    success: function (msg) {
                        alert(msg);
                        $("#mydiv").text(msg);
                    }
                });
            });
        });
    </script>
</head>
<body>
    <form id="form1" runat="server">
        <button id="btnTime" type="button">Click here for the time</button>
        <div id="Result"></div>
        <input type="text" id="ad" placeholder="adinizi giriniz" />
        <input type="text" id="soyad"  placeholder="soyadinzi giriniz" />
        <input type="text" id="dus"  placeholder="dusuncelerinizi giriniz" />
        <input id="btnSub" type="button" value="submit" />
        <div id="mydiv"></div>
    </form>
</body>
</html>
