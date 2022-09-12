const form = document.getElementById("form");
const cof = document.getElementById("coffee");
const addOnBox = document.getElementById("add-on-box");
const orderButton = document.getElementById("btn-order");
const successMessage = document.getElementById("success");
const ord_row = document.getElementById("table-ord-sum");

let ordered_coffee,
  addOn_overCoffee = "Milk";

class Orders {
  constructor(cfe, add_on, price = 0.0) {
    this.coffee = cfe;
    this.addOn = add_on;
    this.price = price;
  }
}

class Espresso {
  addMilk() {
    return 60;
  }
  addCream() {
    return 75;
  }
  addLatte() {
    return 100;
  }
}

class Cappuccino {
  addMilk() {
    return 80;
  }
  addCream() {
    return 90;
  }
  addLatte() {
    return 125;
  }
}

class Latte {
  addMilk() {
    return 100;
  }
  addCream() {
    return 125;
  }
  addLatte() {
    return 150;
  }
}

const ords = [];

cof.addEventListener("change", (e) => {
  if (e.target.value !== "nocoffee") {
    addOnBox.classList.remove("initialState");
    orderButton.classList.remove("disable");
    ordered_coffee = e.target.value;
  } else {
    addOnBox.classList.add("initialState");
    orderButton.classList.add("disable");
  }
});

addOnBox.addEventListener("click", (e) => {
  addOn_overCoffee = e.target.value;
});

const helper = (ordered_coffee, addOn_overCoffee, obj) => {
  const newOrder = new Orders(
    ordered_coffee,
    addOn_overCoffee,
    obj[`add${addOn_overCoffee}`]()
  );
  return newOrder;
};

form.addEventListener("submit", (e) => {
  let total_amt = 0;
  e.preventDefault();
  if (ordered_coffee === "Espresso")
    ords.push(helper(ordered_coffee, addOn_overCoffee, new Espresso()));
  else if (ordered_coffee === "Cappuccino")
    ords.push(helper(ordered_coffee, addOn_overCoffee, new Cappuccino()));
  else ords.push(helper(ordered_coffee, addOn_overCoffee, new Latte()));
  successMessage.classList.remove("hidden");

  let n = ords.length - 1;
  const html = `
    <tr>
        <td>${n + 1}</td>
        <td>${ords[n].coffee}</td>
        <td>${ords[n].addOn}</td>
        <td>${ords[n].price}</td>
    </tr>
    `;
  ord_row.insertAdjacentHTML("afterbegin", html);
  for (let i = 0; i < ords.length; i++) {
    total_amt += ords[i].price;
  }
  document.getElementById("total_amt").textContent = total_amt;
  document.querySelector('.orders').classList.remove('disapeear');
});

document.querySelector(".close-btn").addEventListener("click", () => {
  successMessage.classList.add("hidden");
});
