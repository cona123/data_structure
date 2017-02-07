#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;
void heap_insert(vector<int>&,int);
void heap_pop(vector<int>&);
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
	vector<int> heap;
	for(auto i:n)
	{
		heap_insert(heap,i);
	}
	for(auto i:heap)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	int count=heap.size();
	for(int i=0;i!=count;i++)
	{
		heap_pop(heap);
		for(auto j:heap)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
}

void heap_insert(vector<int> &heap,int n)
{
	heap.push_back(n);
	if(heap.size()==1)
	{
		return;
	}
	else
	{
		int pos=heap.size()-1;
		while(1)
		{
			if(heap[pos]<heap[(pos-1)/2])
			{
				int swap=heap[pos];
				heap[pos]=heap[(pos-1)/2];
				heap[(pos-1)/2]=swap;
				pos=(pos-1)/2;
			}
			else
			{
				return;
			}
		}
	}
}

void heap_pop(vector<int> &heap)
{
	cout<<"pop the num:"<<heap[0]<<endl;
	heap[0]=heap[heap.size()-1];
	heap.pop_back();
	int pos=0;
	while(1)
	{
		if(pos*2+1>=heap.size())
		{
			return;
		}
		if(pos*2+2>=heap.size())
		{
			if(heap[pos]>heap[pos*2+1])
			{
				int swap=heap[pos];
				heap[pos]=heap[pos*2+1];
				heap[pos*2+1]=swap;
				return;
			}
			else
			{
				return;
			}
		}
		if(heap[pos*2+1]<heap[pos*2+2])
		{
			if(heap[pos]<heap[pos*2+1])
			{
				return;
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
				return;
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
}
