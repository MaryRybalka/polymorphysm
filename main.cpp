#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

enum size_type{small = 25, medium = 30, large = 35, extraLarge = 40 };

class Pizza {
protected:
    string name;
    unsigned int cheese;
    unsigned int salt;
    size_type size;
public:
    virtual string getName() = 0;
    virtual unsigned int getPrice() = 0;
    virtual string getDef() = 0;

    Pizza(unsigned int s, unsigned int c, size_type _size) {
        salt = s;
        cheese = c;
        size = _size;
    }
    unsigned int getSalt() const{
        return salt;
    }
    unsigned int getCheese() const{
        return cheese;
    }
    unsigned int getSize() const{
        return size;
    }
};

class Margarita : public Pizza {
    unsigned int price = 200;
public:
    Margarita(unsigned int s, unsigned int c, size_type _size) : Pizza(s, c, _size) {
        name = "Margarita";
        price +=(5*s + 20*c + (_size-25)*10);
    }
    string getName() override {
        return "Margarita";
    }

    unsigned int getPrice() override{
        return price;
    }

    string getDef() override{
        return "Thin oat dough, a lot of tomatos";
    }
};

class FourCheese : public Pizza {
    unsigned int price = 400;
public:
    FourCheese(unsigned int s, unsigned int c, size_type _size) : Pizza(s, c, _size){
        name = "FourCheese";
        price +=(10*s + 40*c + (_size-25)*20);
    }

    string getName()override{
        return "Four Cheese";
    }

    unsigned int getPrice() override{
        return price;
    }

    string getDef()override {
        return "Beautiful flavour of four refined types of cheese";
    }
};

class Pepperonni : public Pizza {
    unsigned int price = 250;
public:
    Pepperonni(unsigned int s, unsigned int c, size_type _size) : Pizza(s, c, _size){
        name = "Pepperonni";
        price +=(5*s + 25*c + (_size-25)*15);
    }

    string getName()override {
        return "Pepperonni";
    }

    unsigned int getPrice() override{
        return price;
    }

    string getDef()override {
        return "Hot pepperonni with amazing tomato sauce";
    }
};

class Cezar : public Pizza {
    unsigned int price = 350;
public:
    Cezar(unsigned int s, unsigned int c, size_type _size) : Pizza(s, c, _size){
        name = "Cezar";
        price +=(10*s + 30*c + (_size-25)*22);
    }
    string getName() override{
        return "Cezar";
    }

    unsigned int getPrice() override{
        return price;
    }

    string getDef()override {
        return "Chicken, salad and snacks on the thin wheat flat";
    }
};

class Order {
    vector<Pizza*> list;
    unsigned int total;
public:
    Order(){
        total = 0;
    }

    void add(Pizza *pizza) {
        list.push_back(pizza);
    }

    void takeOrder(){
        int option;
        int choosen_pizza;
        cout << "Choose a pizza: " << endl << "1. Margarita" << endl << "2. Cezar" << endl << "3. Four Cheese" << endl << "4. Pepperonni" << endl << "Input a number of choise: ";
        cin >> choosen_pizza;
        size_type _size;
        cout << "Choose a size: " << endl << "1. Small" << endl << "2. Medium" << endl << "3. Large" << endl << "4. Extra Large" << endl << "Input a number of choise: ";
        cin >> option;
        switch (option){
            case 1:{
                _size = small;
                break;
            }
            case 2:{
                _size = medium;
                break;
            }
            case 3:{
                _size = large;
                break;
            }
            default:{
                _size = extraLarge;
                break;
            }
        }
        cout << "Any extra? " << endl << "1.Cheese" << endl << "2.Salt" << endl << "3.Cheese + Salt" << endl << "4.No, thanks" << endl << "Input a number of choise: ";
        cin >> option;
        unsigned int _salt = 0;
        unsigned int _cheese = 0;
        switch (option){
            case 1:{
                cout << "How many cheese? ";
                cin >> _cheese;
                break;
            }
            case 2:{
                cout << "How many salt? ";
                cin >> _salt;
                break;
            }
            case 3:{
                cout << "How many cheese? ";
                cin >> _cheese;
                cout << "How many salt? ";
                cin >> _salt;
                break;
            }
            default:
                _salt = 0;
                _cheese = 0;
                break;
        }
        switch (choosen_pizza){
            case 1:{
                add(new Margarita(_salt, _cheese, _size));
                break;
            }
            case 2:{
                add(new Cezar(_salt, _cheese, _size));
                break;
            }
            case 3: {
                add(new FourCheese(_salt, _cheese, _size));
                break;
            }
            default:{
                add(new Pepperonni(_salt, _cheese, _size));
                break;
            }
        }

    }

    void print() {
        size_t size = list.size();
        if (size == 0) {
            cout << "Your order is empty" << endl;
        } else {
            cout << "Your order: " << endl;
            for (size_t i = 0; i < size; i++) {
                cout << (i + 1) << ") " << list[i]->getName();
                cout << " - " << list[i]->getDef() << endl;
                cout << "   " << list[i]->getCheese();
                cout << " - cheese, " << list[i]->getSalt();
                cout << " - salt, "  << list[i]->getSize();
                cout << "inch, "  << list[i]->getPrice() << endl;
                total +=list[i]->getPrice();
            }
            cout << "Total: " << total << "rub." << endl;
        }
    };
};

int main() {

    Order new_order;
    int out = 1;
    while (out == 1){
        new_order.takeOrder();
        cout << "Something else? " << endl <<" 1. yes " << endl <<" 2. no " << endl << "Input a number of choise: ";
        cin >> out;
   }
    new_order.print();
    return 0;
}
