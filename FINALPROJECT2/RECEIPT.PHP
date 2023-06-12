<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Retrieve the purchase details from the request
    $transactionId = $_POST['transaction_id'];
    $itemName = $_POST['item_name'];
    $quantity = $_POST['quantity'];
    $price = $_POST['price'];

    // Establish a database connection
    $servername = "localhost";  // Replace with your database server name
    $username = "root";  // Replace with your database username
    $password = "";  // Replace with your database password
    $dbname = "SUPERMARKET";

    $conn = new mysqli($servername, $username, $password, $dbname);

    // Check the connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    // Prepare the SQL statement to insert the purchase into the receipts table
    function generateReceipt($transactionId, $itemName, $quantity, $price, $conn) {
        // Prepare the SQL statement to insert the purchase into the receipts table
        $sql = "INSERT INTO receipts (transaction_id, item_name, quantity, price)
                VALUES ('$transactionId', '$itemName', '$quantity', '$price')";
    
        if ($conn->query($sql) === TRUE) {
            echo "Purchase recorded successfully.";
        } else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }
    }
    
    function displayReceipts($conn) {
        // Retrieve all the receipt details from the database
        $sql = "SELECT * FROM receipts";
        $result = $conn->query($sql);
    
        // Generate the HTML table for the receipt
        $html = '<html><head><title>Receipt Details</title></head><body>';
        $html .= '<h1>Receipt Details</h1>';
        $html .= '<table border="1"><tr><th>Receipt ID</th><th>Transaction ID</th><th>Item Name</th><th>Quantity</th><th>Price</th></tr>';
    
        if ($result->num_rows > 0) {
            while ($row = $result->fetch_assoc()) {
                $receiptId = $row['receipt_id'];
                $transactionId = $row['transaction_id'];
                $itemName = $row['item_name'];
                $quantity = $row['quantity'];
                $price = $row['price'];
                $html .= "<tr><td>$receiptId</td><td>$transactionId</td><td>$itemName</td><td>$quantity</td><td>$price</td></tr>";
            }
        } else {
            $html .= '<tr><td colspan="5">No receipt details found.</td></tr>';
        }
    
        $html .= '</table>';
        $html .= '</body></html>';
    
        // Display the HTML receipt page
        echo $html;
    }
    // Close the database connection
    $conn->close();
}
?>
