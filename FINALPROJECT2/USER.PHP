<?php
// Connect to the database
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "SUPERMARKET";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}
// Function to change password
function changePassword($email, $newPassword, $conn) {
    $hashedPassword = password_hash($newPassword, PASSWORD_DEFAULT);
    $sql = "UPDATE user SET password_hash = ? WHERE email = ?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param('ss', $hashedPassword, $email);

    if ($stmt->execute()) {
        echo "Password changed successfully!";
        header('Refresh: 3; URL = GROCERYSHOP.html');
    } else {
        echo "Error: " . $stmt->error;
    }
}



// Function for user login and shopping
function login($username, $password, $conn) {
    $sql = "SELECT * FROM user WHERE username=?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param('s', $username);
    $stmt->execute();
    $result = $stmt->get_result();

    if ($result->num_rows > 0) {
        $row = $result->fetch_assoc();
        if (password_verify($password, $row['password_hash'])) {
            session_start();
            $_SESSION['loggedin'] = true;
            $_SESSION['username'] = $username;
            echo "Login successful!";
            // Redirect back to the home page
            header('Refresh: 3; URL = GROCERYSHOP.html');
        } else {
            echo "Login failed: Incorrect password.";
        }
    } else {
        echo "Login failed: Username not found.";
    }
}

// Function to register a new user
function createUser($username, $password, $email, $conn) {
    $sql = "SELECT * FROM user WHERE username = ?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param('s', $username);
    $stmt->execute();
    $result = $stmt->get_result();

    if ($result->num_rows > 0) {
        echo "Username already exists. Please choose another username.";
    } else {
        $hashedPassword = password_hash($password, PASSWORD_DEFAULT);
        $sql = "INSERT INTO user (username, password_hash, email) VALUES (?, ?, ?)";
        $stmt = $conn->prepare($sql);
        $stmt->bind_param('sss', $username, $hashedPassword, $email);

        if ($stmt->execute()) {
            echo "Registration successful!";
            // Redirect back to the home page
            header('Refresh: 3; URL = GROCERYSHOP.html');
        } else {
            echo "Error: " . $stmt->error;
        }
    }
}

// Check if form is submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Check if user wants to login or register
    if($_POST['userNumber'] == 1) {
        // Login
        login($_POST['username'], $_POST['password'], $conn);
    } elseif ($_POST['userNumber'] == 2) {
        // Register
        createUser($_POST['new_username'], $_POST['new_password'], $_POST['email'], $conn);
    }
}
?>

 