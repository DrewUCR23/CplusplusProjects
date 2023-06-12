<?php
class Admin {
    private $username;
    private $password;
    private $status;
    private $conn;
    private $email; 

    function __construct($servername, $username, $password, $dbname) {
        // Create database connection
        $this->conn = new mysqli($servername, $username, $password, $dbname);

        // Check connection
        if ($this->conn->connect_error) {
            die("Connection failed: " . $this->conn->connect_error);
        }
    }

    // Function to handle admin login
    public function adminLogin($adminUsername, $adminPassword) {
        $this->username = $adminUsername;
        $this->password = $adminPassword;

        $this->validateUser();

        if ($this->status) {
            echo "Admin logged in successfully.";
            // Handle admin actions here
            header('Refresh: 2; URL = GROCERYSHOP.html');

        } else {
            echo "Invalid admin credentials.";
        }
    
    }

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

    public function createAdminAccount($adminUsername, $adminPassword, $adminEmail) {
        $this->username = $adminUsername;
        $this->password = password_hash($adminPassword, PASSWORD_DEFAULT);
        $this->email = $adminEmail;
    
        $sql = "INSERT INTO admin (username, password_hash, email) VALUES (?, ?, ?)";
        $stmt = $this->conn->prepare($sql);
        $stmt->bind_param("sss", $this->username, $this->password, $this->email);
    
        // reset to the home page upon execution
        if ($stmt->execute()) {
            echo "Registration successful!";
            // Redirect back to the home page
            header('Refresh: 3; URL = GROCERYSHOP.html');
        } else {
            echo "Error: " . $stmt->error;
        }
    
        $stmt->close();
    }

    private function validateUser() {
        $sql = "SELECT * FROM admin WHERE username = ?";
        $stmt = $this->conn->prepare($sql);
        $stmt->bind_param("s", $this->username);

        if ($stmt->execute()) {
            $result = $stmt->get_result();
            $admin = $result->fetch_assoc();
            if ($admin && password_verify($this->password, $admin['password_hash'])) {
                $this->status = true;
            } else {
                $this->status = false;
            }
        }

        $stmt->close();
    }

    // Function to delete an admin account
    public function deleteAdmin($username) {
        $sql = "DELETE FROM admin WHERE username = ?";
        $stmt = $this->conn->prepare($sql);
        $stmt->bind_param("s", $username);

        if ($stmt->execute()) {
            echo "Admin account deleted successfully!";
        } else {
            echo "Error: " . $sql . "<br>" . $this->conn->error;
        }

        $stmt->close();
    }

    // Function to check admin actions
    public function checkActions($username) {
        $sql = "SELECT * FROM actions WHERE username = ?";
        $stmt = $this->conn->prepare($sql);
        $stmt->bind_param("s", $username);

        if ($stmt->execute()) {
            $result = $stmt->get_result();
            while($row = $result->fetch_assoc()) {
                echo "Action ID: " . $row["id"] . ", Action: " . $row["action"] . ", Timestamp: " . $row["timestamp"] . "<br>";
            }
        } else {
            echo "Error: " . $sql . "<br>" . $this->conn->error;
        }

        $stmt->close();
    }
}
?>
