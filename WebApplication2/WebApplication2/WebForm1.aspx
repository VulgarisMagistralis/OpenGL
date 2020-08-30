<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="WebApplication2.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml" lang="en">
<head runat="server">
    <script src="/Scripts/jquery-1.11.3.min.js"></script>
    <script src="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js"></script>
    <link rel="stylesheet" href="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css" />
    <title>RC [BOOTSTRAP]</title>
    <meta charset="utf-8" />
    <script>
        $(document).ready(function () {
            $('.dropdown-toggle').dropdown();
            $('#powbut').click(function () { });
            $('#decbut').click(function () { });
            $('#incbut').click(function () { });
            $('#selbut').click(function () { });
            $('#helbut').click(function () { });
            $('#horbut').click(function () { });
            $('#verbut').click(function () { });
            $('#timbut').click(function () { });
            $('#lgtbut').click(function () { });
        });
    </script>
</head>
<body>

    <form id="form1" runat="server">
        <div class="container-fluid">
            <div class="page-header">
                <h1>&nbsp &nbsp  &nbsp  &nbsp AIRFEL AIR CONDITIONER  </h1>
            </div>
            <div class="col-md-4">
                <img src="img/power.png" class="img-circle " />
                <br />
                <button id="powbut" type="button" class="btn btn-info btn-lg ">power</button><br />
                <img src="img/dec.png" class="img-responsive" style="width: 150px; height: 150px" /><br />
                <button id="decbut" type="button" class="btn btn-info btn-lg">-</button><br />
                <br />
                <img src="img/hlt.png" class="img-responsive" style="width: 150px; height: 150px" /><br />
                <button id="helbut" type="button" class="btn btn-info btn-lg">health</button>
                <br />
                <img src="img/horizontal.png" class="img-responsive" style="width: 150px; height: 150px" /><br />
                <button id="horbut" type="button" class="btn btn-info btn-lg">horz</button>
                <br />
                <img src="img/inc.png" class="img-responsive" style="width: 150px; height: 150px" /><br />
                <button id="incbut" type="button" class="btn btn-info btn-lg">+</button><br />
            </div>
            <div class="col-md-4">
                <div class="dropdown">
                    <button type="button" class="btn btn-info dropdown-toggle btn-lg " id="modebut" data-toggle="dropdown">
                        PICK MODE
                    <span class="caret"></span>
                    </button>
                    <ul class="dropdown-menu" role="menu" aria-labelledby="modebut">
                        <li role="presentation"><a role="menuitem" tabindex="-1" href="#">COOL</a></li>
                        <li role="presentation"><a role="menuitem" tabindex="-1" href="#">HEAT</a></li>
                        <li role="presentation"><a role="menuitem" tabindex="-1" href="#">DRY</a></li>
                        <li role="presentation"><a role="menuitem" tabindex="-1" href="#">FAN</a></li>
                        <li role="presentation"><a role="menuitem" tabindex="-1" href="#">????</a></li>
                    </ul>
                </div>
                <br />
                <img src="img/lgt.jpg" class="img-responsive" style="width: 150px; height: 150px" /><br />
                <button id="lgtbut" type="button" class="btn btn-info btn-lg">light</button><br />
                <img src="img/sleep.jpg" class="img-circle" style="width: 150px; height: 150px" />
                <br />
                <br />
                <button id="selbut" type="button" class="btn btn-info btn-lg">sleep</button><br />
                <img src="img/tmr.png" class="img-rounded" style="width: 150px; height: 150px" />
                <br />
                <button id="timbut" type="button" class="btn btn-info btn-lg">timer</button><br />
                <img src="img/verz.png" class="img-responsive" style="width: 150px; height: 150px" /><br />
                <button id="verbut" type="button" class="btn btn-info btn-lg">verz</button><br />
            </div>

        </div>
    </form>
</body>
</html>
