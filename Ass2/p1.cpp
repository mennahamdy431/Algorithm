#include <iostream>


using namespace std;

// it define Number of vertices so that we can use it in intialize any array
#define x 7

//function to get the minimum key from vertices which is not in mstSet
int minKey(int Key[], bool mstSet[])
{
    // Initialize min value with the biggest value an integer can hold
    int Min = INT_MAX, index;

    for (int i = 0; i < x; i++)
        if (mstSet[i] == false && Key[i] < Min)
            Min = Key[i], index = i;

    return index;
}


void Print_MST(int Parent[], int graph[x][x])
{
    cout<<"Edge\tWeight\tCost"<<endl;
    for (int i = 1; i < x; i++)
        cout<<"v"<<Parent[i]<<" ----> "<<"v"<<i<<" \t "<<graph[i][Parent[i]]<<endl;
}


void Prim_MST(int graph[x][x])
{
    // this array to store parent of each node(vertix)
    int Parent[x];

    // this array to store weight of any declared edge and it store at the end minimum weight
    int Key[x];

    // this array used to make different between picked vertix in mst by make it true and vertix which is not picked make it false
    bool mstSet[x];


    for (int i = 0; i < x; i++)
       {
        Key[i] = INT_MAX;
         mstSet[i] = false;
       }
    //put first vertix in parent[] in mst and make its key 0 because its the root
    Key[0] = 0;
    Parent[0] = -1;


    for (int i = 0; i < x - 1; i++)
    {

        int u = minKey(Key, mstSet);

     //   make this vertix true as it put in mstSet
        mstSet[u] = true;


        for (int i = 0; i < x; i++)

            if (graph[u][i] && mstSet[i] == false && graph[u][i] < Key[i])
                Parent[i] = u, Key[i] = graph[u][i];
    }


    Print_MST(Parent, graph);
}


int main()
{

int Graph[x][x]={{0,2,4,1,0,0,0},
             {2,0,0,3,10,0,0},
              {4,0,0,2,0,5,0},
              {1,3,2,0,7,8,4},
              {0,10,0,7,0,0,6},
              {0,0,5,8,0,0,1},
              {0,0,0,4,6,1,0}};


    Prim_MST(Graph);

    return 0;
}


