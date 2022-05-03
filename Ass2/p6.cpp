#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

pair <int,int> int_pairs;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Queue;

const int num_of_nodes = 100000;
const int Max = 1000000000;

int num_of_servers, num_of_routes, source, destination, y;
int Head[num_of_nodes], Next[num_of_nodes], server1[num_of_nodes], server2[num_of_nodes], latency[num_of_nodes], sum[num_of_nodes];
bool flag[num_of_nodes];

inline void Graph()
{
    cin>>num_of_servers>>num_of_routes>>source>>destination;
    memset(Head, -1, sizeof(Head));

    for(int i = 1; i <= num_of_routes; i++)
    {
        cin>>server1[i]>>server2[i]>>latency[i];
        server1[i+num_of_routes] = server2[i];
        server2[i+num_of_routes] = server1[i];
        latency[i+num_of_routes] = latency[i];
        Next[i] = Head[server1[i]];
        Head[server1[i]] = i;
        Next[i+num_of_routes] = Head[server1[i+num_of_routes]];
        Head[server1[i+num_of_routes]] = i+num_of_routes;
    }
}

inline void Shortest_path(int src)
{
    memset(flag, 0, sizeof(flag));

    for(int i = 0; i < num_of_servers; i++)
    {
        sum[i] = Max;
    }

    sum[src] = 0;
    Queue.push(make_pair(sum[src], src));

    while(!Queue.empty())
    {
        int_pairs = Queue.top();
        Queue.pop();
        int p = int_pairs.second;
        if(flag[p])
        {
            flag[p] = true;
        }
        for(int i = Head[p]; i != -1; i = Next[i])
        {
            if(sum[server2[i]] > sum[p] + latency[i])
            {
                sum[server2[i]] = sum[p] + latency[i];
                Queue.push(make_pair(sum[server2[i]], server2[i]));
            }
        }

    }
}

int main(){
    int T, Case = 1, cur;
    cout<<"please enter number of cases "<<endl;
    cin >> T;
    cur = T;
    int arr[T];
    cout<<"Enter number of servers, number of routes, source and destination then,"<<endl;
    cout<<"In every case for each route enter 2 different servers and latency between them"<<endl;
    while(T--)
    {
        Graph();
        Shortest_path(source);

        for(int i = T+1; i > 0; i--)
        {
            arr[i] = sum[destination];
        }
    }

    cout<<endl;

    for(int j = cur; j > 0; j--)
        {
            cout << "Time of of Case #"<< Case++ <<": ";
            if(arr[j]!=Max)
            {
                cout << arr[j]<<endl;
            }
            else
            {
                cout << "unreachable"<<endl;
            }
        }

    return 0;

}
