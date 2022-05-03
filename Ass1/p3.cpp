#include <bits/stdc++.h>
using namespace std;

int sorting(int arr[], int temp[], int left, int right);
int M(int arr[], int temp[], int left, int mid, int right);


int mergeSort(int arr[], int size)
{
    int T[size];
    return sorting(arr, T, 0, size - 1);
}

int sorting(int arr[], int T[], int L, int R)
{
    int mid, inversions = 0;
    if (R > L) {

        mid = (R + L) / 2;

        inversions += sorting(arr, T, L, mid);
        inversions += sorting(arr, T, mid + 1, R);
        inversions += M(arr, T, L, mid + 1, R);
    }
    return inversions;
}

int M(int arr[], int T[], int L, int mid, int R)
{
    int i, j, k;
    int inversions = 0;

    i = L;
    j = mid;
    k = L;
    while ((i <= mid - 1) && (j <= R)) {
        if (arr[i] <= arr[j]) {
            T[k++] = arr[i++];
        }
        else {
            T[k++] = arr[j++];

            inversions = inversions + (mid - i);
        }
    }

    while (i <= mid - 1)
        T[k++] = arr[i++];

    while (j <= R)
        T[k++] = arr[j++];

    for (i = L; i <= R; i++)
        arr[i] = T[i];

    return inversions;
}
void solve(){
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << mergeSort(arr, N)<<endl;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
        solve();


}

