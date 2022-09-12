#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

class Coffee {
 public:
    virtual double addMilk() {}
    virtual double addCream() {}
    virtual double addLatte() {}
};

class Espresso: public Coffee {
 public:
    double addMilk() {
        return 60.0;
    }
    double addCream() {
        return 75.0;
    }
    double addLatte() {
        return 100.0;
    }
};

class Cappuccino: public Coffee {
 public:
    double addMilk() {
        return 80.0;
    }
    double addCream() {
        return 95.0;
    }
    double addLatte() {
        return 125.0;
    }
};

class Latte: public Coffee {
 public:
    double addMilk() {
        return 100.0;
    }
    double addCream() {
        return 125.0;
    }
    double addLatte() {
        return 150.0;
    }
};

struct orders{
    string coffee, add_on;
    double price;

    void func(string ao, double pr) {
        add_on = ao;
        price = pr;
    }
};

void coffeeMenu() {
    cout << "1. Espresso" << endl;
    cout << "2. Cappuccino" << endl;
    cout << "3. Latte" << endl;
    cout << "4. Bill" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

void addOns() {
    cout << "1. Milk" << endl;
    cout << "2. Cream" << endl;
    cout << "3. Latte" << endl;
    cout << "Choose your add on: ";
}

orders helper(Coffee *cfe, orders &o) {
    int ch;
    addOns();
    cin >> ch;
    if(ch == 1) 
        o.func("Milk", cfe->addMilk());
    else if(ch == 2)
        o.func("Cream", cfe->addCream());
    else
        o.func("Latte", cfe->addLatte());
    delete cfe;
    return o;
}

void orderSummary(vector<orders> &ords) {
    double total = 0.0;
    cout << "\nS/No" << '\t' << "Coffee Type" << '\t' << "Add-On" << '\t' << "Price" << endl;
    for(int i = 0; i < ords.size(); i++) {
        cout << i + 1 << '\t' << ords[i].coffee << '\t' << ords[i].add_on << '\t' << ords[i].price << endl;
        total += ords[i].price;
    }
    if(total == 0.0) {
        cout << "No payment due.";
        return;
    }
    cout << "==============================================" << endl;
    cout << "Grand Total                     " << total << endl;
    cout << "==============================================\n" << endl;
}

int main() {
    int choice, flag = 1, prevChoice;
    vector<orders> ords;
    cout << "Welcome to coffeehouse. Quench your thirst with your favourite coffee" << endl;
    coffeeMenu();
    while(1) {
        orders o;
        int ch;
        cin >> choice;
        if(choice == 1) {
            Coffee *esp = new Espresso;
            o.coffee = "Espresso  ";
            ords.push_back(helper(esp, o));
        } else if(choice == 2) {
            Coffee *cap = new Cappuccino;
            o.coffee = "Cappuccino";
            ords.push_back(helper(cap, o));
        } else if(choice == 3) {
            Coffee *lat = new Latte;
            o.coffee = "Latte     ";
            ords.push_back(helper(lat, o));
        } else if(choice == 4) {
            orderSummary(ords);
        } else if(choice == 5) {
            if(prevChoice != 4)
                orderSummary(ords);
            cout << "Thank you for using our service. We'll Meet you soon.";
            exit(1);
        }
        else {
            cout << "This option is not available please choose view the menu again.";
            coffeeMenu();
            flag = 0;
        }
        if(flag) {
            cout << "Choose your favorite coffee or view bill (or exit)\n";
            coffeeMenu();
        }
        prevChoice = choice;
    }
    return 0;
}