#include <iostream>
#include <unordered_map>

using namespace std;

void check(int Arr[], int num_of_elements, int target)
{
    unordered_map <int, int> m;
    int flag = 0;
    for (int i = 0; i < num_of_elements; i++)
    {
        if (m.find(target - Arr[i]) != m.end())
        {
            cout <<"(" << Arr[m[target - Arr[i]]] << "," << Arr[i] << ")"<<endl;
            flag = 1;
        }

        m[Arr[i]] = i;
    }
    if (flag == 0)
    {
        cout<<"Pair not found"<<endl;
    }
}

int main()
{
    int num_of_elements;
    int target;
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

    cout<<"please enter the target"<<endl;
    cin>>target;

    check(Arr, num_of_elements, target);

    return 0;
}

