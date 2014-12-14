#include<iostream>
using namespace std;

int findMaxSum(int S[],int n)
{
	int accumulated_sum[n];
	int parent[n];

	accumulated_sum[0] = S[0];
	parent[0] = 0;

	for (int i=1;i<n;i++){
		if (accumulated_sum[i-1] > 0)
		{
			accumulated_sum[i] = accumulated_sum[i-1]+S[i];
			parent[i] = parent[i-1];
		}
		else
		{
			accumulated_sum[i]=S[i];
			parent[i]=i;
		}
	}

	int max = 0;
	int index = 0;
	for (int i=0;i<n;i++)
		if(accumulated_sum[i] > max)
		{
			max = accumulated_sum[i];
			index = i;
		}

	for (int i=parent[index];i<=index;i++)
		cout << S[i] << ' ';

	return max;
}

int main()
{
	int n;
	cout << "Enter length of array: " << endl;
	cin >> n;

	int S[n];
	cout << "Now insert 7 elements: " << endl;
	for(int i=0;i<n;i++)
		cin >> S[i];

	int result = findMaxSum(S,n);
	cout << endl << "The maximum sum is " << result << endl;

	return 0;
}
