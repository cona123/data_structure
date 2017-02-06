#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
void insertion_sort(std::vector<int>&);
using namespace std;
int main()
{
	vector<int> n;
	srand(unsigned(time(0)));
	for(int i=0;i!=30;i++)
	{
		n.push_back(unsigned(random()%100));
	}

	for(auto i:n)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	insertion_sort(n);
	for(auto i:n)
	{
		cout<<i<<" ";
	}
}

void insertion_sort(std::vector<int> &n)
{
	int swap=0;
	for(int i=1;i!=n.size();i++)
	{
		swap=n[i];
		for(int j=i-1;j!=-1;j--)
		{
			if(n[j]<swap)
			{
				continue;
			}
			else
			{
				n[j+1]=n[j];
				n[j]=swap;
			}
		}
	}
}
