<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm2.aspx.cs" Inherits="WebApplication2.WebForm2" %>

<!DOCTYPE html PUBLIC>
 
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    
</head>
<body>
    <form id="form1" runat="server">
           <!--ekleme-->
        <asp:ScriptManager ID="ScriptManager2" runat="server"></asp:ScriptManager>
        <asp:UpdatePanel ID="UpdatePanel1" runat="server">
        <ContentTemplate>
                <asp:Timer ID="Timer_2" runat="server" Interval="1000" OnTick="Timer1_Tick">
                </asp:Timer>
                <asp:Label ID="lbltime" runat="server" Text="lbltime" Height="35" Width="150px"   Font-Names="Verdana" Font-Size="X-Large"></asp:Label>
        </ContentTemplate>
        </asp:UpdatePanel>      
        
        
        <asp:Label ID="curTemp" runat="server" Height="35" Width="150px"   Font-Names="Verdana" Font-Size="X-Large">
        
        </asp:Label> 
        <!--ekleme-->
        
        <!-- KLIMadan gelen DEGER yazdirilicak-->  
        <!-- mode tusu-->
        <asp:Button ID="btnMode" runat="server"  Height="30" Width="100" Text="MODE" OnClick="btnMode_Click" ForeColor="White" BorderStyle="Solid" BackColor="#00ffff" BorderColor="#0066ff" /><br/>
        <asp:Label ID="lblMode" runat="server"></asp:Label>
        <asp:HiddenField ID="hdnMode" runat="server" Value="1"/>
        <!-- fan tusu-->
        <asp:Button ID="btnFan" runat="server" Text="FAN"  Height="30" Width="100" OnClick="btnFan_Click"  ForeColor="White" BorderStyle="Solid" BackColor="#00ffff" BorderColor="#0066ff"  /><br/>
        <asp:Label ID="lblFan" runat="server"></asp:Label>
        <asp:HiddenField ID="hdnFan" runat="server" Value="1"/>
        <!-- turbo tusu-->
        <asp:Button ID="turbo" runat="server" Text="TURBO"  Height="30" Width="100" OnClick="turbo_Click"  ForeColor="White" BorderStyle="Solid" BackColor="#00ffff" BorderColor="#0066ff" /><br/>
        <!-- turbo basiliyken renkli olsun-->
        <!-- (+) ve (-) tuslari-->
        <asp:Button ID="btnInc" runat="server" Text="+" OnClick="btnInc_Click"  Height="30" Width="100" ForeColor="White" BorderStyle="Solid" BackColor="#00ffff" BorderColor="#0066ff" /><br/>
        <asp:Button ID="btnDec" runat="server" Text="-" OnClick="btnDec_Click"  Height="30" Width="100" ForeColor="White" BorderStyle="Solid" BackColor="#00ffff" BorderColor="#0066ff" /><br/>
        <asp:Label ID="lblTemp" runat="server" ></asp:Label>
        <asp:HiddenField ID="hdnTemp" runat="server" Value="23" />
        <asp:HiddenField ID="hdnTime" runat="server" Value= "1" />
        <!--temp tusu -->
        <asp:Button ID ="btnTmp" runat="server" Text="TEMP" OnClick="btnTmp_Click"  Height="30" Width="100" ForeColor="White" BorderStyle="Solid" BackColor="#00ffff" BorderColor="#0066ff"  /><br/>
        <asp:Label ID="lblTmp"  runat="server" ></asp:Label>
        <asp:HiddenField ID="hdnTmp" runat="server" Value="1" />
        <!-- xfan tusu-->
        <asp:Button ID="btnXfan" runat="server" Text="XFAN" OnClick="btnXfan_Click"  Height="30" Width="100" ForeColor="White" BorderStyle="Solid" BackColor="#00ffff" BorderColor="#0066ff" /><br/>
        <asp:Label ID="lblXfan" runat="server" ></asp:Label>
        <asp:HiddenField ID="hdnXfan" runat="server" Value="XFAN"/>
        <!--yatay ve dikey hareket tusu-->
        <asp:Button ID="btnHor" runat="server" Text="HORZ" OnClick="btnHor_Click"  Height="30" Width="100" ForeColor="White" BorderStyle="Solid" BackColor="#00ffff" BorderColor="#0066ff" /><br/>
        <asp:Button ID="btnVer" runat="server" Text="VERT" OnClick="btnVer_Click"  Height="30" Width="100" ForeColor="White" BorderStyle="Solid" BackColor="#00ffff" BorderColor="#0066ff" /><br/>
        <!--isik tusu -->
        <asp:Button ID="btnLit" runat="server" Text="LIGHT" OnClick="btnLit_Click"  Height="30" Width="100" ForeColor="White" BorderStyle="Solid" BackColor="#00ffff" BorderColor="#0066ff" /> <br/>
        <!-- health tusu-->
        <asp:Button ID="btnHel" runat="server" Text="HEALTH" OnClick="btnHel_Click"  Height="30" Width="100"  ForeColor="White" BorderStyle="Solid" BackColor="#00ffff" BorderColor="#0066ff" /><br />
        <asp:Label ID="lblHel" runat="server" ></asp:Label>
        <asp:HiddenField ID="hdnHel" runat="server" Value="HEALTH" />
        <!-- sleep tusu-->
        <asp:Button ID="btnSlp" runat="server" Text="SLEEP" OnClick="btnSlp_Click"  Height="30" Width="100" ForeColor="White" BorderStyle="Solid" BackColor="#00ffff" BorderColor="#0066ff" /><br />
        <!-- timer tusu -->
        <asp:Button ID="btnTime" runat="server" Text="TIMER" OnClick="btnTimer_Click"  Height="30" Width="100" ForeColor="White" BorderStyle="Solid" BackColor="#00ffff" BorderColor="#0066ff"  /><br />
        <asp:Label ID="timelbl" runat="server"></asp:Label>
        <asp:HiddenField ID="hdnSwitch" runat="server" Value="0" />
        <asp:HiddenField ID="hdnSettime" runat="server" Value="0" />
        <!-- on off tusu-->
        <asp:Button ID="btnOn" runat="server" Text="ON" OnClick="btnOn_Click"  Height="30" Width="100" ForeColor="White" BorderStyle="Solid" BackColor="#00ffff" BorderColor="#0066ff" /><br />
        <asp:Button ID="btnOff" runat="server" Text="OFF" OnClick="btnOff_Click"  Height="30" Width="100" ForeColor="White" BorderStyle="Solid" BackColor="#00ffff" BorderColor="#0066ff" /><br />
         <!-- -->
        <asp:Timer ID="Timer1" runat="server" Interval="5000" />
        <asp:Label ID="lblTimereq" runat="server" ></asp:Label>
        


    </form>
</body>
</html>
                                                        