<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="jquery.aspx.cs" Inherits="WebApplication2.jquery" %>


<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml" lang="en">
<head runat="server">
    <meta charset="utf-8" />
    <title>RC</title>
    <script src="/Scripts/jquery-1.11.3.min.js"></script>
    
 

</head>
<body>
    <form id="form1">
        <h1><b>AIRFEL AIR CONDITIONER REMOTE </b></h1>
        <h2 id="date"></h2>
        <h3 id="time"></h3>
        <style>
            #a {
                margin:10px;
                border:2px;
                max-height:100px;
                max-width:100px;
                p

            }
            #slppic{
                margin:10px;
                border:2px;
            }
        </style>
        <script>
            $(document).ready(function () {
                $("#onbtn").click(function () {
                    $('#fanbtn').show();
                    $('#turbtn').show();
                    $('#xfnbtn').show();
                    $('#incbtn').show();
                    $('#decbtn').show();
                    $('#slpbtn').show();
                    $('#tmpbtn').show();
                    $('#horbtn').show();
                    $('#verbtn').show();
                    $('#lgtbtn').show();
                    $('#hltbtn').show();
                    $('#modebtn').show();
                    $('#offbtn').show();
          
                });
                $('#offbtn').click(function () {
                    $('#fanbtn').hide();
                    $('#turbtn').hide();
                    $('#xfnbtn').hide();
                    $('#incbtn').hide();
                    $('#decbtn').hide();
                    $('#slpbtn').hide();
                    $('#tmpbtn').hide();
                    $('#horbtn').hide();
                    $('#verbtn').hide();
                    $('#lgtbtn').hide();
                    $('#hltbtn').hide();
                    $('#modebtn').hide();
                    $('#offbtn').hide();
             
                });
                $("img").mousedown(function () {

                    $(".imgclick").mousedown(function () {


                        var mrgtb = parseInt($(this).css("margin-top"));

                        var mrglf = parseInt($(this).css("margin-left"));

                        mrgtb = mrgtb + 3;

                        mrglf = mrglf + 3;

                        $(this).css("margin-top", mrgtb + "px").css("margin-left", mrglf + "px");


                    }).mouseup(function () {

                        var mrgtb = parseInt($(this).css("margin-top"));

                        var mrglf = parseInt($(this).css("margin-left"));

                        mrgtb = mrgtb - 3;

                        mrglf = mrglf - 3;

                        $(this).css("margin-top", mrgtb + "px").css("margin-left", mrglf + "px");

                    });                                 
                });
                $("img").mousedown(function () {

                    $(".imgclick").mousedown(function () {


                        var mrgtb = parseInt($(this).css("margin-top"));

                        var mrglf = parseInt($(this).css("margin-left"));

                        mrgtb = mrgtb + 3;

                        mrglf = mrglf + 3;

                        $(this).css("margin-top", mrgtb + "px").css("margin-left", mrglf + "px");


                    }).mouseup(function () {

                        var mrgtb = parseInt($(this).css("margin-top"));

                        var mrglf = parseInt($(this).css("margin-left"));

                        mrgtb = mrgtb - 3;

                        mrglf = mrglf - 3;

                        $(this).css("margin-top", mrgtb + "px").css("margin-left", mrglf + "px");

                    });
                });
                $("img").mousedown(function () {

                    $(".imgclick").mousedown(function () {


                        var mrgtb = parseInt($(this).css("margin-top"));

                        var mrglf = parseInt($(this).css("margin-left"));

                        mrgtb = mrgtb + 3;

                        mrglf = mrglf + 3;

                        $(this).css("margin-top", mrgtb + "px").css("margin-left", mrglf + "px");


                    }).mouseup(function () {

                        var mrgtb = parseInt($(this).css("margin-top"));

                        var mrglf = parseInt($(this).css("margin-left"));

                        mrgtb = mrgtb - 3;

                        mrglf = mrglf - 3;

                        $(this).css("margin-top", mrgtb + "px").css("margin-left", mrglf + "px");

                    });
                });
                $("img").mousedown(function () {

                    $(".imgclick").mousedown(function () {


                        var mrgtb = parseInt($(this).css("margin-top"));

                        var mrglf = parseInt($(this).css("margin-left"));

                        mrgtb = mrgtb + 3;

                        mrglf = mrglf + 3;

                        $(this).css("margin-top", mrgtb + "px").css("margin-left", mrglf + "px");


                    }).mouseup(function () {

                        var mrgtb = parseInt($(this).css("margin-top"));

                        var mrglf = parseInt($(this).css("margin-left"));

                        mrgtb = mrgtb - 3;

                        mrglf = mrglf - 3;

                        $(this).css("margin-top", mrgtb + "px").css("margin-left", mrglf + "px");

                    });
                });
                $("img").mousedown(function () {

                    $(".imgclick").mousedown(function () {


                        var mrgtb = parseInt($(this).css("margin-top"));

                        var mrglf = parseInt($(this).css("margin-left"));

                        mrgtb = mrgtb + 3;

                        mrglf = mrglf + 3;

                        $(this).css("margin-top", mrgtb + "px").css("margin-left", mrglf + "px");


                    }).mouseup(function () {

                        var mrgtb = parseInt($(this).css("margin-top"));

                        var mrglf = parseInt($(this).css("margin-left"));

                        mrgtb = mrgtb - 3;

                        mrglf = mrglf - 3;

                        $(this).css("margin-top", mrgtb + "px").css("margin-left", mrglf + "px");

                    });
                });
                $("img").mousedown(function () {

                    $(".imgclick").mousedown(function () {


                        var mrgtb = parseInt($(this).css("margin-top"));

                        var mrglf = parseInt($(this).css("margin-left"));

                        mrgtb = mrgtb + 3;

                        mrglf = mrglf + 3;

                        $(this).css("margin-top", mrgtb + "px").css("margin-left", mrglf + "px");


                    }).mouseup(function () {

                        var mrgtb = parseInt($(this).css("margin-top"));

                        var mrglf = parseInt($(this).css("margin-left"));

                        mrgtb = mrgtb - 3;

                        mrglf = mrglf - 3;

                        $(this).css("margin-top", mrgtb + "px").css("margin-left", mrglf + "px");

                    });
                });
                $("img").mousedown(function () {

                    $(".imgclick").mousedown(function () {


                        var mrgtb = parseInt($(this).css("margin-top"));

                        var mrglf = parseInt($(this).css("margin-left"));

                        mrgtb = mrgtb + 3;

                        mrglf = mrglf + 3;

                        $(this).css("margin-top", mrgtb + "px").css("margin-left", mrglf + "px");


                    }).mouseup(function () {

                        var mrgtb = parseInt($(this).css("margin-top"));

                        var mrglf = parseInt($(this).css("margin-left"));

                        mrgtb = mrgtb - 3;

                        mrglf = mrglf - 3;

                        $(this).css("margin-top", mrgtb + "px").css("margin-left", mrglf + "px");

                    });
                });
                $("img").mousedown(function () {

                    $(".imgclick").mousedown(function () {


                        var mrgtb = parseInt($(this).css("margin-top"));

                        var mrglf = parseInt($(this).css("margin-left"));

                        mrgtb = mrgtb + 3;

                        mrglf = mrglf + 3;

                        $(this).css("margin-top", mrgtb + "px").css("margin-left", mrglf + "px");


                    }).mouseup(function () {

                        var mrgtb = parseInt($(this).css("margin-top"));

                        var mrglf = parseInt($(this).css("margin-left"));

                        mrgtb = mrgtb - 3;

                        mrglf = mrglf - 3;

                        $(this).css("margin-top", mrgtb + "px").css("margin-left", mrglf + "px");

                    });
                });
                $("img").mousedown(function () {

                    $(".imgclick").mousedown(function () {


                        var mrgtb = parseInt($(this).css("margin-top"));

                        var mrglf = parseInt($(this).css("margin-left"));

                        mrgtb = mrgtb + 3;

                        mrglf = mrglf + 3;

                        $(this).css("margin-top", mrgtb + "px").css("margin-left", mrglf + "px");


                    }).mouseup(function () {

                        var mrgtb = parseInt($(this).css("margin-top"));

                        var mrglf = parseInt($(this).css("margin-left"));

                        mrgtb = mrgtb - 3;

                        mrglf = mrglf - 3;

                        $(this).css("margin-top", mrgtb + "px").css("margin-left", mrglf + "px");

                    });
                });
                $("img").mousedown(function () {

                    $(".imgclick").mousedown(function () {


                        var mrgtb = parseInt($(this).css("margin-top"));

                        var mrglf = parseInt($(this).css("margin-left"));

                        mrgtb = mrgtb + 3;

                        mrglf = mrglf + 3;

                        $(this).css("margin-top", mrgtb + "px").css("margin-left", mrglf + "px");


                    }).mouseup(function () {

                        var mrgtb = parseInt($(this).css("margin-top"));

                        var mrglf = parseInt($(this).css("margin-left"));

                        mrgtb = mrgtb - 3;

                        mrglf = mrglf - 3;

                        $(this).css("margin-top", mrgtb + "px").css("margin-left", mrglf + "px");

                    });
                });
                        
            });

    </script>   
        <input id="a" class="imgclick"  type="image" top='10px' width='100' height='100' src="/img/turbo.gif.png" />
        <input id="slppic"class="imgclick" type="image" width='100' height='100' src="/img/sleep.jpg" />     
        <input id="power" class="imgclick" type="image" width='100' height='100' src="/img/power.png" />
        <input id="horz" class="imgclick" type="image" width='100' height='100'  src="img/horizontal.png" /> 
        <input id="dec" class="imgclick" type="image" width='100' height='100' src="img/dec.png" />
        <input id="hlt" class="imgclick" type="image" width='100' height='100' src="img/hlt.png" />
        <input id="inc" class="imgclick" type="image" width='100' height='100' src="img/inc.png" />
        <input id="lgt" class="imgclick" type="image" width='100' height='100' src="img/lgt.jpg" />
        <input id="tmr" class="imgclick" type="image" width='100' height='100' src="img/tmr.png" />
        <input id="verz" class="imgclick" type="image" width='100' height='100' src="img/verz.png" />

        <label id="lblTemp">23</label>
        <input type="hidden" id="hdnTemp" value="23"  />

        <!-- tum butonlar
        <button id="onbtn" type="button">ON</button>
        <button id="offbtn" type="button">OFF</button>           -->

        <select id="modebtn" name="modes">
            <option value="1">MODE 1</option>
            <option value="2">MODE 2</option>
            <option value="3">MODE 3</option>
            <option value="4">MODE 4</option>
            <option value="5">MODE 5</option>
        </select>
        <!--
        <button id="fanbtn" type="button">FAN</button>
        <button  id="turbtn" type="button">TURBO</button>
        <button id="xfnbtn" type="button">XFAN</button>
        <button id="incbtn" type="button">+</button>
        <br />
        <button id="decbtn" type="button">-</button>
        <button id="horbtn" type="button">HOR</button>
        <button id="verbtn" type="button">VER</button>
        <button id="tmpbtn" type="button">TEMP</button>
        <br />
        <button id="timebtn" type="button">TIMER</button>
        <button id="slpbtn" type="button">SLEEP</button>
        <button id="hltbtn" type="button">HEALTH</button>
        <button id="lgtbtn" type="button">LIGHT</button>
         -->

    </form>
        </body>
</html>
