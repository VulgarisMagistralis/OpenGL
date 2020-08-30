<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="deneme2.aspx.cs" Inherits="Deneme.deneme2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
   
    <title>post</title>
    <script type="text/javascript" src="deneme2.aspx"></script>
    <script type="text/javascript" src="/Deneme/scripts/jquery-1.11.3.min"></script>
    <script type="text/javascript">
        $(document).ready(function () {
            function  ShowCurrentTime() {
                $.ajax({
                    type: "POST",
                    url: "CS.aspx/GetCurrentTime",
                    data: '{name: "' + $("#<%=txtUserName.ClientID%>")[0].value + '" }',
                    contentType: "application/json; charset=utf-8",
                    dataType: "json",
                    success: OnSuccess,
                    failure: function(response) {
                        alert(response.d);
                    }
                });
            }
        });
      
    </script>
</head>
<body>
 
  <div>
Your Name :
<asp:TextBox ID="txtUserName" runat="server"></asp:TextBox>
<input id="btnGetTime" type="button" value="Show Current Time"
    onclick = "ShowCurrentTime()" />
</div>


</body>
</html>                                                                          
