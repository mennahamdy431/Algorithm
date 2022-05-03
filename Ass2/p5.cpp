#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int Catch(char arr[], int N, int K)
{
    int max_num_of_caughts = 0;
    vector<int> thieves;
    vector<int> police;

    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 'P')
        {
            police.push_back(i);
        }

        else if (arr[i] == 'T')
        {
            thieves.push_back(i);
        }

    }

    int index_of_thieves = 0, index_of_police = 0;
    while(index_of_thieves < thieves.size() && index_of_police < police.size())
    {
            if (abs(thieves[index_of_thieves] - police[index_of_police]) <= K)
            {
                max_num_of_caughts++;
                index_of_police++;
                index_of_thieves++;
            }
            else if (index_of_police < index_of_thieves)
            {
                index_of_police++;
            }
            else
            {
                index_of_thieves++;
            }
    }

    return max_num_of_caughts;
}

int main()

{
    int K, N;
    char elem;

    cout << "Please enter the number of thieves and police... " << endl;
    cin >> N;
    char List[N];

    cout << "Please enter the space of area between the thief and police... " << endl;
    cin >> K;

    cout << "Please enter the list of thieves police "<<endl;

    for(int i = 0; i < N; i++)
    {
        cin >> elem;
        List[i] = elem;
    }

    cout << Catch(List, N, K) << endl;

    return 0;
}
