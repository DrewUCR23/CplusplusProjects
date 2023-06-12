<?php

function storePurchases($names, $user_choices, $totalPrice, $leftOver, $pricePaid) {
    $purchase_file = fopen("purchase_records.bin", "ab");
    $counter = 0;

    if ($purchase_file) {
        foreach ($user_choices as $food => $quantity) {
            fwrite($purchase_file, pack('A*', $food));
            fwrite($purchase_file, pack('A*', $names["costs"][$counter]));
            fwrite($purchase_file, pack('i', $quantity));
            $counter++;
        }
        fwrite($purchase_file, pack('f', $totalPrice));
        fwrite($purchase_file, pack('f', $pricePaid));
        fwrite($purchase_file, pack('f', $leftOver));
        fclose($purchase_file);
    } else {
        echo "Unable to open the purchase records file";
    }
}

?>
