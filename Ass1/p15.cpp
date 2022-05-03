#include <iostream>
#include <unordered_set>
using namespace std;

void minimum(int Arr[], int num_of_elements)
{
    int mini = num_of_elements;

    unordered_set<int> s;

    for (int i = num_of_elements - 1; i >= 0; i--)
    {
        // if the element is seen before, update the minimum index
        if (s.find(Arr[i]) != s.end()) {
            mini = i;
        }
        // if the element is seen for the first time, insert it into the set
        else {
            s.insert(Arr[i]);
        }
    }

    if (mini == num_of_elements) {
        cout << "invalid input";
        return;
    }

    cout << "The minimum index of the repeating element is " << mini;

}

int main()
{
    int num_of_elements;
    int element;

    cout<<"please enter the number of elements"<<endl;
    cin>>num_of_elements;
    int Arr[num_of_elements];

    cout<<"please enter the elements"<<endl;
    for(int i = 0; i < num_of_elements; i++)
    {
        cin>>element;
        Arr[i] = element;
    }

    minimum(Arr, num_of_elements);

    return 0;
}
