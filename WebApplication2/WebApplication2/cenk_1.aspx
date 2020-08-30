<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="cenk_1.aspx.cs" Inherits="WebApplication2.cenk_1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">

<head runat="server">
    <title>####</title>
    <script src="/Scripts/jquery-1.11.3.min.js"></script>
    <script></script>
    <script src="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js"></script>
    <link rel="stylesheet" href="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css" />

    <script>
        $(document).ready(function () {
            $('.dropdown-toggle').dropdown();




        });

    </script>
</head>
<body>
    <form id="form1" runat="server">

        <nav class="navbar navbar-default navbar-fixed-top navbar-inverse">
            <div class="container-fluid">
                <div class="navbar-header">
                    <a style="text-decoration:underline; color: blueviolet" class="navbar-brand" href="#">Home</a>
                </div>
                <div>
                    <ul style="color: blueviolet" class="nav navbar-nav ">
                        <li style="text-decoration:underline;"><a href="#" style="color: blueviolet">TEAMS</a></li>
                        <li style="text-decoration:underline;"><a href="#" style="color: blueviolet">HEROS</a></li>
                        <li style="text-decoration:underline;"><a href="#" style="color: blueviolet">ITEMS</a></li>
                        <li style="text-decoration:underline;"><a href="#" style="color: blueviolet">STUFF</a></li>
                        <li style="text-decoration:underline"><a href="#" style="color: blueviolet">INFO</a></li>
                    </ul>
                </div>
            </div>
        </nav>

        <div class="container">
            <div style="background-color: blueviolet" class="jumbotron">
                <h1 class="text-center" style="background-color: blueviolet">DOTA 2</h1>
                <p style="background-color: aqua;">///////// </p>
            </div>
            <ul class="nav nav-tabs navbar-inverse">
                <li class="dropdown">
                    <a class="dropdown-toggle" data-toggle="dropdown" href="m">MENU
                <span class="caret"></span></a>
                    <ul class="dropdown-menu">
                        <li><a href="m">qwe</a></li>
                        <li><a href="m">qwem/a></li>
                        <li><a href="m">err</a></li>
                    </ul>
                </li>
                <li><a href="#">Menu 1</a></li>
                <li><a href="#">Menu 2</a></li>
                <li><a href="#">Menu 3</a></li>

            </ul>
              <h2>List </h2>
            <ul class="list-group">
                <li class="list-group-item list-group-item-success">First item</li>
                <li class="list-group-item list-group-item-info">Second item</li>
                <li class="list-group-item list-group-item-warning">Third item</li>
                <li class="list-group-item list-group-item-danger">Fourth item</li>
            </ul>
            <div class="row">
                <div class="col-sm-4">
                    <h3 style="background-color: lawngreen">Column 1</h3>
                    <p style="background-color: burlywood">
                        Lorem ipsum dolor sit amet, consectetur adipisicing elit...                     
                    </p>
                </div>
                <div class="col-sm-4">
                    <h3 style="background-color: lawngreen">Column 2</h3>
                    <p style="background-color: burlywood">
                        Lorem ipsum dolor sit amet, consectetur adipisicing elit...                      
                    </p>
                </div>
                <div class="col-sm-4">
                    <h3 style="background-color: lawngreen">Column 3</h3>
                    <p style="background-color: burlywood">
                        Lorem ipsum dolor sit amet, consectetur adipisicing elit...                  
                    </p>
                </div>
            </div>
        </div>
        <div class="container-fluid">
            <h2>Table</h2>
            <table class="table">
                <thead>
                    <tr class="info">
                        <th>Firstname</th>
                        <th>Lastname</th>
                        <th>Email</th>
                    </tr>
                </thead>
                <tbody>
                    <tr class="success">
                        <td>John</td>
                        <td>Doe</td>
                        <td>john@example.com</td>
                    </tr>
                    <tr class="success">
                        <td>Mary</td>
                        <td>Moe</td>
                        <td>mary@example.com</td>
                    </tr>
                    <tr class="success">
                        <td>July</td>
                        <td>Dooley</td>
                        <td>july@example.com</td>
                    </tr>
                </tbody>
            </table>
        </div>
        <div class="container">
            <h2>Some Text</h2>
            <div class="well well-lg " style="background-color: chocolate">More Text</div>
        </div>
        <div class="panel panel-info">
            <div class="panel-heading">Panel </div>
            <div class="panel-body">......</div>
        </div>

        <div class="container">
          
            <h2>Linked With "The List"</h2>
            <div class="list-group">
                <a href="#" class="list-group-item list-group-item-success">First item</a>
                <a href="#" class="list-group-item list-group-item-info">Second item</a>
                <a href="#" class="list-group-item list-group-item-warning">Third item</a>
                <a href="#" class="list-group-item list-group-item-danger">Fourth item</a>
            </div>
        </div>

    </form>
</body>
</html>
