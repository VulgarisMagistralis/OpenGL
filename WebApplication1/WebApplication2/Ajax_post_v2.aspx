<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Ajax_post_v2.aspx.cs" Inherits="WebApplication2.Ajax_post_v2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Ajax_post</title>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>
   
</head>
<body>
       <form id="formoid" action="studentFormInsert.php" title="" method="post">
        <div>
            <label class="title">First Name</label>
            <input type="text" id="name" name="name" />
        </div>
        <div>
            <label class="title">Name</label>
            <input type="text" id="name2" name="name2"  />
        </div>
        <div>
            <input type="submit" id="submitButton"  name="submitButton" value="Submit"/>
        </div>
 </form>
<script type='text/javascript'>
    /* attach a submit handler to the form */
    $("#formoid").submit(function (event) {

        /* stop form from submitting normally */
        event.preventDefault();

        /* get some values from elements on the page: */
        var $form = $(this),
            url = $form.attr('action');

        /* Send the data using post */
        var posting = $.post(url, { name: $('#name').val(), name2: $('#name2').val() });

        /* Alerts the results */
        posting.done(function (data) {
            alert('success');
        });
    });
</script>
</body>
</html>
