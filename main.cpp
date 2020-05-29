// Selling ice cream

#include "iostream"
#include "map"
#include "iomanip"
#include "cmath"

//Function declaration
float remaining_money(float);
void initial_information();
void choose_ice_cream();

using namespace std;

//Variable declaration
float mymoney_initial_money = 5;
float mymoney = mymoney_initial_money;
float final_amount;
float capri =  1.10;
float nogger = 1.60;
float cornetto = 2.30;
//dictionary with ice cream prices
map<int, float> PriceTable = {{1,capri}, {2,nogger},{3,cornetto}};
//dictionary with ice cream names
map<int, string> IceCreamTable = {{1,"Capri"}, {2,"Nogger"},{3,"Cornetto"}};

int main() {
    cout << fixed << setprecision(2);
    initial_information();

    //First ice cream question
    cout << "Which kind of ice cream does the first friend want?" << endl;
    cout << "Please type in the corresponding number (1,2 or 3):" << endl;
    choose_ice_cream();

    //Second ice cream question
    cout << "Which kind of ice cream does the second friend want?" << endl;
    cout << "Please type in the corresponding number (1,2 or 3):" << endl;
    choose_ice_cream();

    //Third ice cream choice
    if (mymoney < capri) {
        cout << "Unfortunately there is no money left to buy another ice cream." << endl;
    } else if (mymoney < nogger) {
        cout << "There is only enough money left to buy Capri." << endl;
        cout << "Please type in \"1\" if you want to buy Capri." << endl;
        choose_ice_cream();
    } else if (mymoney < cornetto) {
        cout << "There is enough money left to buy either Capri or Nogger." << endl;
        cout << "Please type in the corresponding number (1 or 2):" << endl;
        choose_ice_cream();
    } else if (mymoney >= cornetto) {
        cout << "Which kind of ice cream do you want want?" << endl;
        cout << "Please type in the corresponding number (1,2 or 3):" << endl;
        choose_ice_cream();
    }

    //Display final information
    final_amount = mymoney_initial_money-mymoney;
    cout << "The total amount is " << int(floor(final_amount)) << " € and ";
    cout << int(round(fmod(final_amount,1)*100)) << " cents." << endl << endl;

    cout << "Thanks for using the ice cream selling algorithm." << endl << "Enjoy your ice cream!" << endl;
    return 0;
}

//Function definitions

void initial_information()
{
    cout << "There are three types of ice creams available:" << endl << endl;
    cout << "1. Capri for 1.10 €" << endl;
    cout << "2. Nogger for 1.60 €" << endl;
    cout << "3. Cornetto for 2.30 €" << endl << endl;
}

void choose_ice_cream()
{
    int choice;
    cin >> choice;
    cout << "You picked " << IceCreamTable[choice] << endl;
    remaining_money(PriceTable[choice]);
}

float remaining_money(float ice_cream_price)
{
    float mymoney_after_buy;
    mymoney_after_buy = mymoney - ice_cream_price;
    if (mymoney_after_buy < 0) {
        cout << "There is not enough money left to buy this type of ice cream!" << endl;
    } else {
        mymoney = mymoney_after_buy;
        cout << "You have " << mymoney << " € left." << endl << endl;
    }
    return mymoney;
}