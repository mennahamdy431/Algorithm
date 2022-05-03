#include <iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include <sstream>
using namespace std;

class Matrix_Multiplication
{
protected:
    int **m;
    int **S;
public:
    //constructor to intialize 2 arrays
    Matrix_Multiplication(int n)
    {
        m = new int*[n];
        for (int i=0; i<n; i++)
        {
            m[i] = new int [n];
        }
        S = new int*[n];
        for (int i=0; i<n; i++)
        {
            S[i] = new int [n];
        }

    }
  //this function to display minimum cost of the given multiplication to
  // equation like for example: ((A1xA2)xA3)
    void display(int Start,int End)
    {


        if(Start==End)
        {
            cout<<"A"<<Start;
            return ;
        }

        cout<<"(";
        display(Start,S[Start][End]);

        cout<<"x";
        display(S[Start][End]+1,End);
        cout<<")";

    }
//this function to choose the optimal solution (minimum cost) for a given matrices
    void optimal_multiplication(int arr[], int n)
    {


        int i, j, k, Len, min_cost;


        for (i = 1; i < n; i++)
        {
            m[i][i] = 0;
            S[i][i] = 0;
        }

        for (Len = 2; Len < n; Len++)
        {
            for (i = 1; i < n - Len + 1; i++)
            {
                j = i + Len - 1;
                //INT_MAX:this word store in this index the maximum value an integer can hold
                m[i][j] = INT_MAX;
                for (k = i; k <= j - 1; k++)
                {

                    min_cost = m[i][k] + m[k + 1][j]
                        + arr[i - 1] * arr[k] * arr[j];
                    if (min_cost < m[i][j])
                    {
                        m[i][j] = min_cost;
                        S[i][j] = k;
                    }

                }
            }
        }
        display(1,n-1);
    }
};

int main()
{
    int input,x;
    cout<<"enter number of sets"<<endl;
    cin>>input;
    x=input*2;
    int arr[x];
    int arr1[input];
    for(int i=0; i<x; i++)
    {
        cin>>arr[i];
    }
    arr1[0]=arr[0];
    for(int i=1; i<input; i++)
    {
        arr1[i]=arr[i*2];
    }
    arr1[input]=arr[x-1];


    Matrix_Multiplication m(input+1);
    m.optimal_multiplication(arr1, input+1);

    return 0;
}
