#include <iostream>
using namespace std;

int arr[5007];

int call(int l, int r, int d)
{
    if (l > r)
        return 0;

    int pos = l;

    for (int i = l; i <= r; i++)
        if (arr[pos] > arr[i])
            pos = i;

    int ret = r - l + 1;
    int lefcall=call(l, pos - 1, arr[pos]);
    int righcall=call(pos + 1, r, arr[pos]);
    return min(ret, arr[pos] - d +lefcall+ righcall);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << call(0, n - 1, 0) << endl;

}