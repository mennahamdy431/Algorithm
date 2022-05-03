#include <iostream>
using namespace std;
int part(int* arr, int l, int r) {
    int x = arr[r], i = l;

    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[r]);
    return i;
}

int Kthmin(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {

        int pos = part(arr, l, r);

        if (pos - l == k - 1)
            return arr[pos];

        if (pos - l > k - 1) 
            return Kthmin(arr, l, pos - 1, k);

        return Kthmin(arr, pos + 1, r, k - pos + l - 1);
    }

    return -1;
}

long long m_w, m_z;

int get_random() {
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    long long res = (m_z << 16) + m_w;
    return res % 1000000000;
}


int main() {
    int k, N;
    cin >> N >> k >> m_w >> m_z;
    int arr[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = get_random();
    }

    cout << Kthmin(arr, 0, N - 1, k);

}


