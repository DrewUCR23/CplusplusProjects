<?php

// Database connection variables
$servername = "localhost";
$dbUsername = "root";
$dbPassword = "";
$dbName = "SUPERMARKET"; 

// Establish the database connection
$conn = new mysqli($servername, $dbUsername, $dbPassword, $dbName);

// Check the connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Retrieve the user input
    $userNumber = $_POST['userNumber'];

    // Initialize the variables
    $loggedIn = false;
    $choice = "";
    $userQuantity = 0;
    $howMuchPaid = 0;


    require_once('ADMINPHP.php'); 
$admin = new Admin($servername, $dbUsername, $dbPassword, $dbName);


//instance of the shopping cart that was created accordingly
require_once('CHECKSHOPPINGCART.php');
$shoppingCart = new ShoppingCart($conn);

    // Handle the selected option
    switch ($userNumber) {
        case 1:
            // Handle user login
            $username = $_POST['username'];
            $password = $_POST['password'];
            require_once('USER.PHP');
            login($username, $password, $conn);
            break;
        case 2:
            require_once('USER.PHP');
            $newUsername = $_POST['new_username'];
            $newPassword = $_POST['new_password'];
            $email = $_POST['email'];
            
            // Call the createUser function
            createUser($newUsername, $newPassword, $email, $conn);
            break;
              case 3:
                    // Handle change password
                    if (isset($_POST['email'], $_POST['new_password'])) {
                        $email = $_POST['email'];
                        $newPassword = $_POST['new_password'];
                        require_once('USER.PHP');
                        changePassword($email, $newPassword, $conn);
                    } else {
                        echo "Email or new password not provided";
                    }
                    break;
                
            
             case 4:
            //handles admin login
            require_once('ADMINPHP.php');
            $admin->adminLogin($_POST['adminUsername'], $_POST['adminPassword']);
            break;
            case 5:
                if (isset($_POST['adminUsernameReg'], $_POST['adminPasswordReg'], $_POST['adminEmailReg'])) {
                    $admin->createAdminAccount($_POST['adminUsernameReg'], $_POST['adminPasswordReg'], $_POST['adminEmailReg']);
                } else {
                    echo 'Missing required POST data.';
                }  
                break;    
        case 6:
            //delete the  a user via admin
            require_once('ADMINPHP.php');
            $admin->deleteUser($_POST['deleteUsername']);

            break;
        case 7:
            //check the users purchases next 
            require_once('ADMINPHP.php');
            $admin->checkPurchases($_POST['checkpurchases']);
            break;
                //checks the item in the shopping cart and adds items accordingly 
                require_once('CHECKSHOPPINGCART.php');
                case 8:
                    // Check the value of the "action" input to determine the action to perform
                    $action = isset($_POST['action']) ? $_POST['action'] : '';
                    
                    if ($action === 'Check Cart') {
                        // Redirect to CART.html
                        header("Location: CART.html");
                        exit(); // Stop further execution of the script
                    } elseif ($action === 'addToCartButton') {
                        // Store the item values in the shopping cart
                        foreach ($_POST as $item => $quantity) {
                            if (is_numeric($item) && $quantity > 0) {
                                $shoppingCart->addItem($item, $quantity);
                            }
                        }
                    } else {
                        // Handle the default behavior or display an error message
                        echo "Invalid action. Please try again.";
                    }
                    break;
          case 9:
            require_once('RECEIPT.php');
            $username = $_POST['username'];
            generateReceipt($username, $conn);
            break;
        case 10: 
            require_once('CHECKSHOPPINGCART.php');
            foreach ($_POST as $item => $quantity) {
                if ($quantity > 0) {
                    $shoppingCart->addItem($item, $quantity);
                }
            }
             
            $shoppingCart->purchaseItems();
            break; 
        case 0:
            $loggedIn = false;
            echo "Logged out successfully!";
            break;
        default:
            echo "Invalid option. Please try again.";
            break;
    }
    // Close the database connection
    $conn->close();
}
?>
