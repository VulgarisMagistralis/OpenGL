<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="jquey_Ajax_Post.aspx.cs" Inherits="WebApplication2.jquey_Ajax_Post" %>

<!DOCTYPE html>

<html >
<head runat="server">
    <script src="/Scripts/jquery-1.11.3.min"></script>
    <title>Ajax Post Ex</title>
    <script>
        $(document).ready(function () {
            
            $("input").keyup(function () {
                var txt = $("input").val();
                $.post("demo_ajax_gethint.asp", { suggest: txt }, function (result) {
                    $("span").html(result);
                });
            });
   });

    </script>
</head>
<body>


    <form action="/" id="searchForm">
        <input type="text" name="s" placeholder="Search..."/>
        <input type="submit" value="Search"/>
    </form>
    <div id="result"></div>

   

</body>
</html>
