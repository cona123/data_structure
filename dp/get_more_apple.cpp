/*一个矩形区域被划分为N*M个小矩形格子，在格子(i,j)中有A[i][j]个苹果。现在从左上角的格子(1,1)出发，要求每次只能向右走一步或向下走一步，最后到达(N,M)，每经过一个格子就把其中的苹果全部拿走。请找出能拿到最多苹果数的路线。*/
#include<iostream>
#include<vector>
using namespace std;
int get_more_apple(int length, int width, vector<vector<int> > apple_number )
{
	for(auto& i:apple_number)
	{
		for(auto& j:i)
		{
			cout << j << endl;
		}
	}
	//int **apple_number_sum;
	auto_ptr<auto_ptr<int> > apple_number_sum=new auto_ptr<auto_ptr<int[length]> >;
	for(int i = 0 ; i != length ; i++)
	{
		apple_number_sum[i]=new auto_ptr<int>[width];
	}
	/*
	apple_number_sum = new int*[length];
	for(int i = 0 ; i != length ; i++)
	{
		apple_number_sum[i] = new int[width];
	}
	*/
	for (int i = 0 ; i != length ; i++)
	{
		for (int j = 0 ; j != width ; j++)
		{
			apple_number_sum[i][j] = -1;
		}
	}
	apple_number_sum[0][0] = apple_number[0][0];
	for (int i = 0 ; i != length ; i++)
	{
		for (int j = 0 ; j != width ; j++)
		{
			if (i > 0) {
				apple_number_sum[i][j] = max(apple_number_sum[i][j],apple_number_sum[i-1][j] + apple_number[i][j]);
			}
			if (j > 0) {
				apple_number_sum[i][j] = max(apple_number_sum[i][j],apple_number_sum[i][j-1] + apple_number[i][j]);
			}
		}
	}
	/*int ret = apple_number_sum[length-1][width-1];
	for (int i = 0 ; i != length ; i++)
	{
		delete[] apple_number_sum[i];
	}
	delete[] apple_number_sum;
	return ret;*/
	return apple_number_sum[length-1][width-1];
}

int main()
{
	vector<vector<int> > apple_number;
	for(int i = 0 ; i != 4 ; i++)
	{
		vector<int> line_apple_number;
		for(int j = 0 ; j != 5 ; j++)
		{
			line_apple_number.push_back(rand() % 10);
		}
		apple_number.push_back(line_apple_number);
	}
	cout<<get_more_apple(4,5,apple_number);
				
}

				
