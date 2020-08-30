<%@ Page Language="C#" AutoEventWireup="true" CodeFile="WebForm1.aspx.cs" Inherits="Deneme" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>post</title>
    <script src="Default.aspx"></script>
    <script src="scripts/jquery-1.11.3.min"></script>
    <script>
        $(document).ready(function() {
            $('#but').click(function () {
                $.ajax({
                                             
                    type: 'POST',
                    url: 'WebForm1.aspx',
                    data: '{} ',
                    datatype: 'json',
                    success: function (msg) {
                        $('#time').text(msg.d);
                    }
                });
            });
               
            $.ajax({
                type: "POST",
                url: "WebForm1.aspx",
                data: "{}",
                datatype: "json",
                success: function (msg) {
                   
                }


            });
        });
    </script>
</head>
<body>
    <button type="button" id="but">Time</button>
    <label style="background:center;background-color:lawngreen" class="text" id="time"></label>

</body>
</html>
