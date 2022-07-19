// C++ Early Objects: Page 536, Problem 7

#include <iostream>
#include <iomanip>

using namespace std;

class Inventory
{
private:
    int itemNumber;
    int quantity;
    double cost;

public:

    Inventory(): itemNumber(0), quantity(0), cost(0.0) {} // Default constructor

    Inventory(int i, int q, double c): itemNumber(i), quantity(q), cost(c) {} // Constructor

    void setItemNumber(int n) { itemNumber = n; };

    void setQuantity(int q) { quantity = q; };

    void setCost(double c) { cost = c; };

    int getItemNumber() const { return itemNumber; };

    int getQuantity() const;

    int getCost() const { return cost; };

    double getTotalCost() const { return cost * quantity; };
};

int Inventory::getQuantity() const
{ return quantity; }


int main()
{
    Inventory i;
    cout << i.getCost() << endl;

    Inventory i2(5, 7, 88.99);
    cout << i2.getQuantity() << endl;
    cout << fixed << setprecision(2) << i2.getTotalCost() << endl;

    return 0;
}