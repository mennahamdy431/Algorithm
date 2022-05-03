#include<iostream>
#include<algorithm>
using namespace std;

struct Job
{
	char jobID;	
	int deadline; 
	int profit; 
};

bool comparison(Job a, Job b)
{
	return (a.profit > b.profit);
}

void print(Job arr[], int n)
{
	sort(arr, arr + n, comparison);

	int ans[n]; 
	bool flag[n]; 

	for (int i = 0; i < n; i++)
		flag[i] = false;

	for (int i = 0; i < n; i++)
	{
		for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
		{
			if (flag[j] == false)
			{
				ans[j] = i; 
				flag[j] = true; 
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
		if (flag[i])
			cout << arr[ans[i]].id << " ";
}

int main()
{
	Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
				{'d', 1, 25}, {'e', 3, 15} };
	int n = sizeof(arr) / sizeof(arr[0]);
	print(arr, n);
	return 0;
}
