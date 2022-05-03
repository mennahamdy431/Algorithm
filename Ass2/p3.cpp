#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nodes[100];

int find(int x)
{
    if(nodes[x] == x)
    {
      return x;
    }
    return find(nodes[x]);

}

void unite(int x , int y)
{
    int father_x = find(x);
    int father_y = find(y);
    nodes[father_x] = father_y;
}
int main()
{
    for(int i=0 ; i<100 ;i++)
    {
        nodes[i] = i;
    }

    int g_nodes , g_edges;
    int g_from , g_to , g_weight;
    vector < pair <int , pair < int , int > > >edges;

    cin>>g_nodes>>g_edges;
    for(int i=0 ; i<g_edges ;i++)
    {
        cin>>g_from>>g_to>>g_weight;
        edges.push_back(make_pair(g_weight , make_pair(g_from,g_to)));
    }
    cout<<endl;
    int mst_weight = 0;
    int mst_edges = 0;
    int mst_next_edge = 0;
    sort(edges.begin() , edges.end());
    while( (mst_edges < g_nodes-1) || (mst_next_edge < g_edges) )
    {
        g_from = edges[mst_next_edge].second.first;
        g_to = edges[mst_next_edge].second.second;
        g_weight = edges[mst_next_edge].first;
        if( find(g_from) != find(g_to) )
        {
            unite(g_from , g_to);
            mst_weight += g_weight;
            mst_edges++;
        }
        mst_next_edge++;

    }
    cout<<"Weight of the MST is: "<<mst_weight<<endl;

    return 0;
}
