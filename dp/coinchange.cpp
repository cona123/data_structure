#include<iostream>
#include<vector>
using namespace std;
int get_coin_num(int goal_num,vector<int>& coins)
{
	int *sum=new int[goal_num+1];
	sum[0] = 0;
	for(int i = 1 ; i != goal_num + 1 ; i++)
	{
		int minnum = i;
		sum[i] = i;
		for(auto j : coins)
		{
			if(i >= coins[j]) {
				minnum = min (minnum , sum[i-coins[j]] + 1 );
			}
		}
		sum[i] = minnum;
	}
	int ret = sum[goal_num];
	delete[] sum;
	return ret;
}

int main()
{
	vector<int> coins;
	coins.push_back(1);
	coins.push_back(2);
	coins.push_back(7);
	cout<<get_coin_num(23, coins)<<endl;
	cout<<get_coin_num(50, coins)<<endl;
	cout<<get_coin_num(100, coins)<<endl;
}

