<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="Default" %>

<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>AJAX Demo</title>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script type="text/javascript">
        function callAddS() {
            var x = $('#xValue').val();
            var y = $('#yValue').val();

            var requestData = JSON.stringify({ x: parseInt(x), y: parseInt(y) });

            $.ajax({
                type: "POST",
                url: "Simplex.asmx/AddS",
                data: JSON.stringify({ req: requestData }),
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: function (response) {
                    var parsedResult = JSON.parse(response.d);
                    $('#result').text('Result: ' + parsedResult.sumres);
                },
                error: function (xhr, status, error) {
                    console.log("Ошибка: " + xhr.responseText);
                }
            });
        }

    </script>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h2>18.Разработайте ASP.NET-приложение, применяющее AJAX-запрос (jQuery) и демонстрирующее работоспособность метода AddS ASMX-сервиса Simplex.</h2>
            <label for="xValue">Enter X:</label>
            <input type="text" id="xValue" /><br />
            <label for="yValue">Enter Y:</label>
            <input type="text" id="yValue" /><br />
            <button type="button" onclick="callAddS()">Calculate Sum</button>
            <p id="result"></p>
        </div>
    </form>
</body>
</html>
