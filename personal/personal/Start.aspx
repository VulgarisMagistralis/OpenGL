<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Start.aspx.cs" Inherits="personal.per" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">

<head runat="server">
    <title>Start</title>
    <script src="/scripts/jquery-1.11.3.min.js"></script>
    <script src="/scripts/bootstrap.min.js"></script>
    <script src="/scripts/bootstrap.js"></script>
    <script src="/scripts/npm.js"></script>
    <link href="/Css/bootstrap-theme.css" rel="stylesheet" />
    <link href="/Css/bootstrap-theme.min.css" rel="stylesheet" />
    <link href="/Css/bootstrap.css" rel="stylesheet" />
    <link href="/Css/font-awesome.css" rel="stylesheet" />
    <link href="/Css/font-awesome.min.css" rel="stylesheet" />
    <link href="Scss/_animated.scss" rel="stylesheet" />
    <link href="Less/icons.less" rel="stylesheet" />
    <script>
        $(document).ready(function () {
            $('.dropdown-toggle').dropdown();
            $('#tabs').tab();
            $("#btnTime").on(function () {
                $: ajax({
                    type: "POST",
                    url: "per.aspx/GetTime",
                    data: "{}",
                    contentType: "application; charset=utf-8",
                    success: function (msg) {
                        $("#TIME").text(msg.d);
                    }
                })

            });
            $("#btnDate").hover(function () {
                $: ajax({
                    type: "POST",
                    url: "per.aspx/GetDate",
                    data: "{}",
                    contentType: "application; charset=utf-8",
                    success: function (msg) {
                        $("#DATE").text(msg.d);
                    }
                })

            });
        });
    </script>
    <style>
        div.fixed{
            position:fixed;
            border:4px thick;
            right:0px;
            top:72px;
            width:290px;
            float:inherit;
            overflow:hidden ;
        }
    </style>
</head>
<body style="background:url(/foto/space.jpg)  center fixed   no-repeat ">
    

        <nav class="navbar navbar-default navbar-fixed-top navbar-inverse">
            <div class="container-fluid" style="color: blueviolet">
                <div class="navbar-header">
                    <a style="text-decoration: underline; font-family: Gungsuh; color: blueviolet" class="navbar-brand" href="#">Home</a>
                </div>
                <div>
                    <ul style="color: blueviolet" class="nav navbar-nav ">
                        <li style="text-decoration: underline; font-family: Gungsuh"><a href="#" style="color: blueviolet">TEAMS</a></li>
                        <li style="text-decoration: underline; font-family: Gungsuh"><a href="#" style="color: blueviolet">HEROS</a></li>
                        <li style="text-decoration: underline; font-family: Gungsuh"><a href="#" style="color: blueviolet">ITEMS</a></li>
                        <li style="text-decoration: underline; font-family: Gungsuh"><a href="#" style="color: blueviolet">STUFF</a></li>
                        <li style="text-decoration: underline; font-family: Gungsuh"><a href="#" style="color: blueviolet">INFO</a></li>

                    </ul>
                </div>
            </div>
        </nav>

        <br />
        <br />
        <br />
        <br />
        <!--
            <a id="btnTime">TIME </a>
            <p id="TIME"></p>
            <br />
            <button type="button" id="btnDate">DATE</button>
            <p id="DATE"></p>
            <br />
               -->
        <div class="container">
            <div style="background-color: blueviolet" class="jumbotron">
                <h1 class="text-center" style="background-color: blueviolet">YAY</h1>
                <p style="background-color: aqua;">&nbsp </p>
            </div>
            <div id="tabs">
                <ul class="nav nav-tabs navbar-inverse">
                    <li class="dropdown">
                        <a class="dropdown-toggle" data-toggle="dropdown" href="m">MENU
                <span class="caret"></span></a>
                        <ul class="dropdown-menu">
                            <li style="background-color: black;"><a href="m">qwe</a></li>
                            <li style="background-color: black; color: blueviolet"><a href="m">qwem</a></li>
                            <li style="background-color: black; color: blueviolet"><a href="m">err</a></li>
                        </ul>
                    </li>
                    <li><a href="tab1">Menu 1</a></li>
                    <li><a href="tab2">Menu 2</a></li>
                    <li><a href="tab3">Menu 3</a></li>

                </ul>

            </div>
            <h2 style="color:lightpink">List </h2>
            <ul class="list-group">
                <li class="list-group-item list-group-item-success">First item</li>
                <li class="list-group-item list-group-item-info">Second item</li>
                <li class="list-group-item list-group-item-warning">Third item</li>
                <li class="list-group-item list-group-item-danger">Fourth item</li>
            </ul>
            <div  class="fixed">
              
                    <div class="form-group">
                        <label for="inputEmail">Email</label>
                        <input type="email" class="form-control" id="inputEmail" placeholder="Email" style="color:darkgreen"/>
                    </div>
                    <div class="form-group">
                        <label for="inputPassword">Password</label>
                        <input type="password" class="form-control" id="inputPassword" placeholder="Password"  style="color:darkgreen"/>
                    </div>
                    <div class="checkbox">
                        <label style="color:lightpink">
                            <input type="checkbox"/>   
                            Remember me</label>
                    </div>
                    <button type="submit" class="btn-success" style="color:lightpink">Login</button>
                    <p style="color:lightpink">No account?</p>
                <form action="Application.html" >
                <input class="btn-info" type="submit" value="sign up"  /> 

                </form>
            </div>
            <div class="row">
                <div class="col-sm-4">
                    <h3 style="color:aqua">Column 1</h3>
                    <p style="color:greenyellow">
                        Lorem ipsum dolor sit amet, consectetur adipisicing elit...                     
                    </p>
                </div>
                <div class="col-sm-4">
                    <h3 style="color:aqua">Column 2</h3>
                    <p  style="color:greenyellow">
                        Lorem ipsum dolor sit amet, consectetur adipisicing elit...                      
                    </p>
                </div>
                <div class="col-sm-4">
                    <h3 style="color:aqua">Column 3</h3>
                    <p style="color:greenyellow">
                        Lorem ipsum dolor sit amet, consectetur adipisicing elit...                  
                    </p>
                </div>
            </div>
        </div>
        <div class="container">
            <h2 style="color:lightpink">Table</h2>
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
            <h2 style="color:lightpink">Some Text</h2>
            <div class="well well-lg " >More Text</div>
              <div class="panel panel-info" >
            <div class="panel-heading">Panel </div>
            <div class="panel-body">......</div>
        </div>
            
             </div>
      

        <div class="container">

            <h2 style="color:lightpink">Linked With "The List"</h2>
            <div class="list-group">
                <a href="#" class="list-group-item list-group-item-success">First item</a>
                <a href="#" class="list-group-item list-group-item-info">Second item</a>
                <a href="#" class="list-group-item list-group-item-warning">Third item</a>
                <a href="#" class="list-group-item list-group-item-danger">Fourth item</a>
            </div>
        </div>
        <a style="color:lightpink" class="btn btn-block btn-social btn-twitter">
            <i class="fa fa-twitter"></i >Sign in with Twitter
        </a>
</body>
</html>
