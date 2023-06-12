class Food {
    constructor(count = 0, name = "") {
        this.count = count;
        this.name = name;
    }

    getCount() {
        return this.count;
    }

    getName() {
        return this.name;
    }
}

const FOODINVENTORY = {
    apple: 40,
    orange: 50,
    banana: 60,
    soda: 25,
    ham: 20,
    turkey: 15,
    eggs: 10,
    icecream: 10
};

const FOODNAMES = {
    costs: ["$2.00", "$2.25", "$3", "$1.50", "$1.25", "$6.75", "$7.50", "$1.25"],
    apple1: "Apple",
    orange1: "Orange",
    banana1: "Banana",
    soda1: "Soda",
    ham1: "Ham",
    turkey1: "Turkey",
    eggs1: "Eggs",
    icecream1: "Icecream"
};

function FOODSTOCK(world, NAMES) {
    console.log("These are the foods that we currently have in stock at this time");
    let inventory = {
        [NAMES.apple1]: world.apple,
        [NAMES.orange1]: world.orange,
        [NAMES.banana1]: world.banana,
        [NAMES.soda1]: world.soda,
        [NAMES.ham1]: world.ham,
        [NAMES.turkey1]: world.turkey,
        [NAMES.eggs1]: world.eggs,
        [NAMES.icecream1]: world.icecream
    };
    
    let index = 0;
    for (const item in inventory) {
        console.log(`Food Names: ${item}    Costs: ${NAMES.costs[index]}    Quantities: ${inventory[item]}`);
        index++;
    }
}


function FOODCHOICE(world, NAMES, USERCHOICE, cost, QUANTITY) {
    let inventory = {
        [NAMES.apple1]: world.apple,
        [NAMES.orange1]: world.orange,
        [NAMES.banana1]: world.banana,
        [NAMES.soda1]: world.soda,
        [NAMES.ham1]: world.ham,
        [NAMES.turkey1]: world.turkey,
        [NAMES.eggs1]: world.eggs,
        [NAMES.icecream1]: world.icecream
    };

    if (inventory[USERCHOICE] !== undefined) {
        inventory[USERCHOICE] -= QUANTITY;
        console.log(`The food you have picked is: ${USERCHOICE} for a price of: ${NAMES.costs[cost]} Quantity: ${QUANTITY}`);
    } else {
        console.log("You have picked an invalid value, please try again");
    }
}

function LOADSHOPPINGCART(world, foodNames, user_choices) {
    console.log("Items in your cart: ");
    for (const item in user_choices) {
        let food_name = item;
        let quantity = user_choices[item];
        let foodPrices = {
            "Apple": 2.00,
            "Orange": 2.25,
            "Banana": 3.00,
            "Soda": 1.50,
            "Ham": 1.25,
            "Turkey": 6.75,
            "Eggs": 7.50,
            "Icecream": 1.25
        };
        let price = foodPrices[food_name];

        console.log(`Food: ${food_name}, Quantity: ${quantity}, Price: ${price}`);
    }
}

function RECEIPT(world, NAMES, user_choices, PRICEPAID) {
    const SALESTAX = 1.0375;
    let total_cost = 0.0;
    let LEFTOVER = 0.0;

    let prices = {
        [NAMES.apple1]: 2.00,
        [NAMES.orange1]: 2.25,
        [NAMES.banana1]: 3.00,
        [NAMES.soda1]: 1.50,
        [NAMES.ham1]: 1.25,
        [NAMES.turkey1]: 6.75,
        [NAMES.eggs1]: 7.50,
        [NAMES.icecream1]: 1.25,
    };

    console.log("Item          Price     Quantity     Cost");
    console.log("---------------------------------------------");

    for (const item in user_choices) {
        let item_price = prices[item];
        let item_quantity = user_choices[item];
        let item_cost = item_price * item_quantity;
        total_cost += item_cost;

        console.log(`${item}     ${item_price}     ${item_quantity}     ${item_cost}`);
    }

    total_cost *= SALESTAX;
    LEFTOVER = PRICEPAID - total_cost;

    console.log("---------------------------------------------");
    console.log(`Total Cost                 ${total_cost}`);
    console.log(`Cash Provided              ${PRICEPAID}`);
    console.log(`Change                     ${LEFTOVER}`);
}

function FOODCHOICE(world, NAMES, USERCHOICE, cost, QUANTITY) {
    let inventory = {
        [NAMES.apple1]: world.apple,
        [NAMES.orange1]: world.orange,
        [NAMES.banana1]: world.banana,
        [NAMES.soda1]: world.soda,
        [NAMES.ham1]: world.ham,
        [NAMES.turkey1]: world.turkey,
        [NAMES.eggs1]: world.eggs,
        [NAMES.icecream1]: world.icecream
    };

    if (inventory[USERCHOICE] !== undefined) {
        inventory[USERCHOICE] -= QUANTITY;
        console.log(`The food you have picked is: ${USERCHOICE} for a price of: ${NAMES.costs[cost]} Quantity: ${QUANTITY}`);
    } else {
        console.log("You have picked an invalid value, please try again");
    }
}

function LOADSHOPPINGCART(world, foodNames, user_choices) {
    console.log("Items in your cart: ");
    for (const item in user_choices) {
        let food_name = item;
        let quantity = user_choices[item];
        let foodPrices = {
            "Apple": 2.00,
            "Orange": 2.25,
            "Banana": 3.00,
            "Soda": 1.50,
            "Ham": 1.25,
            "Turkey": 6.75,
            "Eggs": 7.50,
            "Icecream": 1.25
        };
        let price = foodPrices[food_name];

        console.log(`Food: ${food_name}, Quantity: ${quantity}, Price: ${price}`);
    }
}

function RECEIPT(world, NAMES, user_choices, PRICEPAID) {
    const SALESTAX = 1.0375;
    let total_cost = 0.0;
    let LEFTOVER = 0.0;

    let prices = {
        [NAMES.apple1]: 2.00,
        [NAMES.orange1]: 2.25,
        [NAMES.banana1]: 3.00,
        [NAMES.soda1]: 1.50,
        [NAMES.ham1]: 1.25,
        [NAMES.turkey1]: 6.75,
        [NAMES.eggs1]: 7.50,
        [NAMES.icecream1]: 1.25,
    };

    console.log("Item          Price     Quantity     Cost");
    console.log("---------------------------------------------");

    for (const item in user_choices) {
        let item_price = prices[item];
        let item_quantity = user_choices[item];
        let item_cost = item_price * item_quantity;
        total_cost += item_cost;

        console.log(`${item}     ${item_price}     ${item_quantity}     ${item_cost}`);
    }

    total_cost *= SALESTAX;
    LEFTOVER = PRICEPAID - total_cost;

    console.log("---------------------------------------------");
    console.log(`Total Cost                 ${total_cost}`);
    console.log(`Cash Provided              ${PRICEPAID}`);
    console.log(`Change                     ${LEFTOVER}`);
}

// This function can't be translated directly, JavaScript running in a web browser doesn't have direct file access for security reasons
//function STOREPURCHASES(NAMES, user_choices, TOTALPRICE, LEFTOVER, PRICEPAID) { ... }
