<?php
session_start();

class ShoppingCart {
    private $inventory = array();
    private $cart = array();
    private $totalPrice = 0;

    public function __construct($inventory) {
        $this->inventory = $inventory;
        $this->cart = isset($_SESSION['cart']) ? $_SESSION['cart'] : array();
        $this->totalPrice = isset($_SESSION['totalPrice']) ? $_SESSION['totalPrice'] : 0;
    }

    public function addItem($itemName, $quantity) {
        if (is_array($this->inventory) && array_key_exists($itemName, $this->inventory) && $this->inventory[$itemName]['stock'] >= $quantity) {
            $this->inventory[$itemName]['stock'] -= $quantity;
            if (isset($this->cart[$itemName])) {
                $this->cart[$itemName] += $quantity;
            } else {
                $this->cart[$itemName] = $quantity;
            }
            $this->totalPrice += $quantity * $this->inventory[$itemName]['price'];
        } else {
            echo "Insufficient stock of $itemName or invalid item. Please choose another item." . PHP_EOL;
        }
        $_SESSION['cart'] = $this->cart;
        $_SESSION['totalPrice'] = $this->totalPrice;
    }

    public function getCart() {
        return json_encode(array('cart' => $this->cart, 'totalPrice' => $this->totalPrice));
    }
}

$inventory = array(
    // Fruits
    'apple' => array('stock' => 40, 'price' => 2),
    'orange' => array('stock' => 50, 'price' => 2.25),
    'banana' => array('stock' => 60, 'price' => 3),
    'grapes' => array('stock' => 60, 'price' => 2.5),
    'pear' => array('stock' => 60, 'price' => 3.5),
    // Drinks
    'soda' => array('stock' => 25, 'price' => 1.5),
    'juice' => array('stock' => 25, 'price' => 2),
    'water' => array('stock' => 25, 'price' => 1),
    'coffee' => array('stock' => 25, 'price' => 2.5),
    'tea' => array('stock' => 25, 'price' => 2),
    // Meats
    'ham' => array('stock' => 20, 'price' => 1.25),
    'turkey' => array('stock' => 15, 'price' => 6.75),
    'chicken' => array('stock' => 15, 'price' => 5.5),
    'beef' => array('stock' => 15, 'price' => 7),
    'pork' => array('stock' => 15, 'price' => 6.5),
    // Dairy
    'eggs' => array('stock' => 10, 'price' => 7.5),
    'milk' => array('stock' => 10, 'price' => 2.5),
    'cheese' => array('stock' => 10, 'price' => 5),
    'yogurt' => array('stock' => 10, 'price' => 3),
    'butter' => array('stock' => 10, 'price' => 4),
    // Desserts
    'icecream' => array('stock' => 10, 'price' => 1.25),
    'cake' => array('stock' => 10, 'price' => 4),
    'cookies' => array('stock' => 10, 'price' => 3.5),
    'donuts' => array('stock' => 10, 'price' => 2),
    'chocolate' => array('stock' => 10, 'price' => 3)
);

$action = $_POST['action'];

$action = $_POST['action'];

if ($action === 'addToCartButton') {
    // Store the item values in localStorage
    $cartData = array();

    // Retrieve and store the field values in $cartData
    $cartData['apple'] = isset($_POST['apple']) ? $_POST['apple'] : 0;
    $cartData['orange'] = isset($_POST['orange']) ? $_POST['orange'] : 0;
    $cartData['banana'] = isset($_POST['banana']) ? $_POST['banana'] : 0;
    $cartData['grapes'] = isset($_POST['grapes']) ? $_POST['grapes'] : 0;
    $cartData['pear'] = isset($_POST['pear']) ? $_POST['pear'] : 0;

    $cartData['soda'] = isset($_POST['soda']) ? $_POST['soda'] : 0;
    $cartData['juice'] = isset($_POST['juice']) ? $_POST['juice'] : 0;
    $cartData['water'] = isset($_POST['water']) ? $_POST['water'] : 0;
    $cartData['coffee'] = isset($_POST['coffee']) ? $_POST['coffee'] : 0;
    $cartData['tea'] = isset($_POST['tea']) ? $_POST['tea'] : 0;

    $cartData['ham'] = isset($_POST['ham']) ? $_POST['ham'] : 0;
    $cartData['turkey'] = isset($_POST['turkey']) ? $_POST['turkey'] : 0;
    $cartData['chicken'] = isset($_POST['chicken']) ? $_POST['chicken'] : 0;
    $cartData['beef'] = isset($_POST['beef']) ? $_POST['beef'] : 0;
    $cartData['pork'] = isset($_POST['pork']) ? $_POST['pork'] : 0;

    $cartData['eggs'] = isset($_POST['eggs']) ? $_POST['eggs'] : 0;
    $cartData['milk'] = isset($_POST['milk']) ? $_POST['milk'] : 0;
    $cartData['cheese'] = isset($_POST['cheese']) ? $_POST['cheese'] : 0;
    $cartData['yogurt'] = isset($_POST['yogurt']) ? $_POST['yogurt'] : 0;
    $cartData['butter'] = isset($_POST['butter']) ? $_POST['butter'] : 0;

    $cartData['icecream'] = isset($_POST['icecream']) ? $_POST['icecream'] : 0;
    $cartData['cake'] = isset($_POST['cake']) ? $_POST['cake'] : 0;
    $cartData['cookies'] = isset($_POST['cookies']) ? $_POST['cookies'] : 0;
    $cartData['donuts'] = isset($_POST['donuts']) ? $_POST['donuts'] : 0;
    $cartData['chocolate'] = isset($_POST['chocolate']) ? $_POST['chocolate'] : 0;

    // Convert $cartData to JSON
    $cartDataJson = json_encode($cartData);

    // Store $cartDataJson in localStorage
    echo '<script>localStorage.setItem("cartData", ' . $cartDataJson . '); updateLocalStorageWithCart();</script>';
} else {
    // Handle the default behavior or display an error message
    echo "Invalid action. Please try again.";
}


$shoppingCart = new ShoppingCart($inventory);

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $action = $_POST['action'];

    if ($action === 'addToCartButton') {
        // Retrieve and store the field values in $cartData
        $cartData = array();

        // loop over all items in the inventory
        foreach($inventory as $item => $details) {
            $cartData[$item] = isset($_POST[$item]) ? $_POST[$item] : 0;
            if ($cartData[$item] > 0) {
                $shoppingCart->addItem($item, $cartData[$item]);
            }
        }

        // Send the updated cart back to the client
        header('Content-Type: application/json');
        echo json_encode($cartData);
    } else {
        // Handle the default behavior or display an error message
        echo "Invalid action. Please try again.";
    }
}

if ($_SERVER['REQUEST_METHOD'] === 'GET') {
    header('Content-Type: application/json');
    echo $shoppingCart->getCart();
}
?>