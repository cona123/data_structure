#include <iostream>
#include <vector>
using namespace std;
int lis(vector<int> &arr)
{
	vector<int> longlis;
	vector<vector<int>> longresult;
	for (auto i : arr)
	{
		longlis.push_back(1);
		vector<int> temp;
		temp.push_back(i);
		longresult.push_back(temp);
	}
	for (int i = 0; i != arr.size(); i++)
	{
		for (auto j : longresult[i])
		{
			cout << " " << j;
		}
		cout << endl;
	}
	for (int i = 1; i != arr.size(); i++)
	{
		for (int j = 0; j != i; j++)
		{
			if (arr[j]<arr[i] && longlis[j] + 1>longlis[i])
			{
				longlis[i] = longlis[j] + 1;
				//longresult[i].clear;
				vector<int> temp(longresult[j]);
				temp.push_back(arr[i]);
				longresult[i] = temp;
			}
		}
	}
	int max = 0;
	for (int i = 0; i != arr.size(); i++)
	{
		if (max < longlis[i])
		{
			max = longlis[i];
		}
		cout << "i num is " << longlis[i];
		cout << " value is ";
		for (auto j : longresult[i])
		{
			cout << " " << j;
		}
		cout << endl;
	}
	return max;
}

int main()
{
	int array[] = { 2, 5, 27, 12, 45, 51, 25, 34, 52, 62, 22, 11, 21 };
	vector<int> arr(array, array + sizeof(array) / sizeof(int));
	int ret = lis(arr);
	return 0;
}
//#define len(a) (sizeof(a) / sizeof(a[0])) //���鳤��  
/*int lis(int arr[], int len)
{
	int longest[7];
	for (int i = 0; i < len; i++)
		longest[i] = 1;

	for (int j = 1; j < len; j++) {
		for (int i = 0; i<j; i++) {
			if (arr[j]>arr[i] && longest[j] < longest[i] + 1){ //ע��longest[j]<longest[i]+1�������������ʡ�ԡ�  
				longest[j] = longest[i] + 1; //������arr[j]��β�����е�����������г���  
			}
		}
	}

	int max = 0;
	for (int j = 0; j<len; j++) {
		cout << "longest[" << j << "]=" << longest[j] << endl;
		if (longest[j] > max) max = longest[j];  //��longest[j]���ҳ����ֵ  
	}
	return max;
}

int main()
{
	int arr[] = { 1, 4, 5, 6, 2, 3, 8 }; //��������  
	int ret = lis(arr, 7);
	cout << "max increment substring len=" << ret << endl;
	return 0;
	}*/