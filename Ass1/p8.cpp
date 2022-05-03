#include <iostream>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define RBT tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

// Driver program to test above functions
int main()
{
    // Ordered set declared with name o_set
    RBT Toyes;

    int numofQuries,q,x;
    cin>>numofQuries;
    for(int i=0;i<numofQuries;i++){
        cin>>q>>x;
        if(q==1){
                Toyes.insert(x);
        }else if(q==2){
                if (Toyes.find(x) != Toyes.end())
                {
                    int ans= Toyes.order_of_key(x);
                    cout<<ans+1<<' ';
                }
                else cout<<"-1 ";


        }

    }



return 0;
}