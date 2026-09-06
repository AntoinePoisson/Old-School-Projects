<html>
    <body>
        <h1>PHP test script</h1>
        <?php
        echo "This is a test scrip written in PHP";
        echo "<br>";
        echo "The name of the server is " . getenv('SERVER_NAME') . " !";
        ?>
    </body>
</html>