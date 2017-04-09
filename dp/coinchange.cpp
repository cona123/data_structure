#include<iostream>
#include<vector>
#include<memory>
using namespace std;
int get_coin_num(int goal_num, vector<int>& coins)
{
	//unique_ptr<int[]> dp(new int[goal_num+1]);
	auto dp(make_unique<int[]>(goal_num+1));
	dp[0] = 0;
	for(int i = 1 ; i != goal_num + 1 ; i++)
	{
		int minnum = i;
		dp[i] = i;
		for(auto j : coins)
		{
			if(i >= coins[j])
            {
				minnum = min (minnum , dp[i-coins[j]] + 1 );
			}
		}
		dp[i] = minnum;
	}
	return dp[goal_num];
}

int main()
{
    vector<int> coins = {1, 2, 7};
	cout << get_coin_num(23, coins)<<endl;
	cout << get_coin_num(50, coins)<<endl;
	cout << get_coin_num(100, coins)<<endl;
}

