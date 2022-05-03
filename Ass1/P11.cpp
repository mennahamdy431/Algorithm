#include <iostream>
#include <sstream>
#include<cstdlib>
#include <vector>
using namespace std;


//this function to get the maximum of the two numbers
int maximum (int num1, int num2)
{
    if(num1>num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
}
// this function to check if the given input all its elements is negative
// values or not and if all numbers are negative return maximum sum=0
void Check (vector <string> &v)
{
    int x, counter=0;
    for(int i=0 ; i< v.size(); i++)
    {
        istringstream(v[i]) >> x;
        if(x<0)
        {
            counter++;
        }

    }
    if(counter == v.size())
    {
        cout<<"maximum sum = 0"<<endl;
        exit(0);
    }

}


int main()
{

    string str;
    cout<<"Enter The Numbers:"<<endl;
    cout<<"==========================="<<endl;
    getline(cin,str);
    vector<string> arr ;
    string temp = "";
    int i=0;
    // loop to split the string
    for (char x : str)
    {
        if (x == ' ')
        {
            arr.push_back(temp);

            temp = "";
            i++;
        }
        else
        {
            temp = temp + x;
        }
    }
    if(temp!="")
    {
        arr.push_back(temp);
    }

    Check(arr);
    int Inci, Excl;
    int Temp2,elem;
    string choice;
    istringstream(arr[0]) >> Inci;
    Excl=0;
    for(int i=1; i<arr.size(); i++)
    {
        istringstream(arr[i]) >> elem;
        Temp2=Inci;
        Inci=maximum(Inci,Excl+elem);
        Excl=Temp2;

    }
    cout<<"The Maximum Sum = "<<Inci<<endl;

    return 0;
}
