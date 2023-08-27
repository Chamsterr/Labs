<!DOCTYPE html>
<html>
<head>
    <title>Input Form</title>
</head>
<body>
    <h1>Введите ваш телефон и email</h1>
    <form action="MyServlet" method="post">
        <label for="phone">Телефон:</label><br>
        <input type="text" id="phone" name="phone"><br>
        <label for="email">Email:</label><br>
        <input type="text" id="email" name="email"><br>
        <input type="submit" value="Submit">
    </form>
</body>
</html>
