#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
void merge_sort(std::vector<int>&,int,int);
void merge(std::vector<int>&,int,int,int);
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
	merge_sort(n,0,n.size()-1);
	for(auto i:n)
	{
		cout<<i<<" ";
	}
}

void merge_sort(std::vector<int> &n,int begin,int end)
{
	if(begin==end)
	{
		return;
	}

	int mid=(begin+end)/2;
	merge_sort(n,begin,mid);
	merge_sort(n,mid+1,end);
	merge(n,begin,mid,end);
}

void merge(std::vector<int> &n,int begin,int mid,int end)
{
	vector<int> temp;
	int beginnum=begin;
	int endnum=mid+1;
	while(1)
	{
		if(beginnum==mid+1)
		{
			for(int i=endnum;i!=end+1;i++)
			{
				temp.push_back(n[i]);
			}
			break;
		}
		if(endnum==end+1)
		{
			for(int i=beginnum;i!=mid+1;i++)
			{
				temp.push_back(n[i]);
			}
			break;
		}
		if(n[beginnum]>n[endnum])
		{
			temp.push_back(n[endnum]);
			endnum++;
		}
		else
		{
			temp.push_back(n[beginnum]);
			beginnum++;
		}
	}
	for(int i=begin;i!=end+1;i++)
	{
		n[i]=temp[i-begin];
	}
}
