#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;
void heap_sort(vector<int>&);
int heap_pop(vector<int>&);
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
	heap_sort(n);
	for(auto i:n)
	{
		cout<<i<<" ";
	}
	cout<<endl;
}

void heap_sort(vector<int> &n)
{
	if(n.size()==1)
	{
		return;
	}
	int pos=(n.size()-2)/2;
	for(int j=pos;j!=-1;j--)
	{
		int i=j;
		while(1)
		{
			if(2*i+1>n.size()-1)
			{
				break;
			}
			if(2*i+2==n.size())
			{
				if(n[i]>n[i*2+1])
				{
					int swap=n[i];
					n[i]=n[i*2+1];
					n[i*2+1]=swap;
					i=i*2+1;
					break;
				}
				else
				{
					break;
				}
			}
			else
			{
				if(n[i*2+1]>n[i*2+2])
				{
					if(n[i]>n[i*2+2])
					{
						int swap=n[i];
						n[i]=n[i*2+2];
						n[i*2+2]=swap;
						i=i*2+2;
					}
					else
					{
						break;
					}
				}
				else
				{
					if(n[i]>n[i*2+1])
					{
						int swap=n[i];
						n[i]=n[i*2+1];
						n[i*2+1]=swap;
						i=i*2+1;
					}
					else
					{
						break;
					}
				}
			}
		}
	}
	vector<int> ret;
	int num=n.size();
	for(int i=0;i!=num;i++)
	{
		ret.push_back(heap_pop(n));
	}
	for(int i=0;i!=num;i++)
	{
		n.push_back(ret[i]);
	}
}


int heap_pop(vector<int> &heap)
{
	int ret=heap[0];
	heap[0]=heap[heap.size()-1];
	heap.pop_back();
	int pos=0;
	while(1)
	{
		if(pos*2+1>=heap.size())
		{
			return ret;
		}
		if(pos*2+2>=heap.size())
		{
			if(heap[pos]>heap[pos*2+1])
			{
				int swap=heap[pos];
				heap[pos]=heap[pos*2+1];
				heap[pos*2+1]=swap;
				return ret;
			}
			else
			{
				return ret;
			}
		}
		if(heap[pos*2+1]<heap[pos*2+2])
		{
			if(heap[pos]<heap[pos*2+1])
			{
				return ret;
			}
			else
			{
				int swap=heap[pos];
				heap[pos]=heap[pos*2+1];
				heap[pos*2+1]=swap;
				pos=pos*2+1;
			}
		}
		else
		{
			if(heap[pos]<heap[pos*2+2])
			{
				return ret;
			}
			else
			{
				int swap=heap[pos];
				heap[pos]=heap[pos*2+2];
				heap[pos*2+2]=swap;
				pos=pos*2+2;
			}
		}
	}
	return ret;
}
