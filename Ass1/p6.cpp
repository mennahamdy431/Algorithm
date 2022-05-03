#include<bits/stdc++.h>
using namespace std;

class Employee_hash
{
    int size_of_hash;
    list<int> *transaction_items_linkedLIST;
public:

    Employee_hash(int size_of_hash);
    void insertItem(int item);
    void deleteItem(int item);
    int hashFunction(int item)
    {
        return (item % size_of_hash);
    }

    void displayHash();
};

Employee_hash::Employee_hash(int size_of_hash)
{
    this->size_of_hash = size_of_hash;
    transaction_items_linkedLIST = new list<int>[size_of_hash];
}

void Employee_hash::insertItem(int item)
{
    int index = hashFunction(item);
    transaction_items_linkedLIST[index].push_back(item);
    int llSize = sizeof(transaction_items_linkedLIST)/sizeof(transaction_items_linkedLIST[0]);
}

void Employee_hash::deleteItem(int item)
{
    int index = hashFunction(item);
    list <int> :: iterator i;
    for (i = transaction_items_linkedLIST[index].begin(); i != transaction_items_linkedLIST[index].end(); i++)
    {
        if (*i == item)
        {
            break;
        }
    }

    if (i != transaction_items_linkedLIST[index].end())
    {
        transaction_items_linkedLIST[index].erase(i);
    }
}

void Employee_hash::displayHash()
{
    for (int i = 0; i < size_of_hash; i++)
    {
        cout << i;
        for (auto x : transaction_items_linkedLIST[i])
            cout << " --> " << x;
        cout << endl;
    }
}

int main()
{
    int soldBy[] = {11,12,25,16,28,25,9,33,9};
    int soldBy_llSize = sizeof(soldBy)/sizeof(soldBy[0]);

    Employee_hash employeeID(7);

    for (int i = 0; i < soldBy_llSize; i++)
    {
        employeeID.insertItem(soldBy[i]);
    }

    employeeID.deleteItem(12);
    employeeID.displayHash();

    return 0;
}
