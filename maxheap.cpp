#include <iostream>
#include <limits.h>
#include "graphUtility.h"

using namespace std;


	int H[NO_OF_VERTICES];
	int heapsize;
	int D[NO_OF_VERTICES];
	
	void initialize()
	{
		heapsize = -1;
		for(int i=0;i<NO_OF_VERTICES;i++)
		{
			H[i] = i;
			D[i] = INT_MIN;
		}
	}
	
	int parent(int index)
	{
		if(index/2+index%2 -1 >= 0)
			return index/2+index%2 -1;
		else
			return -1;
	}
	
	int leftchild(int index)
	{
		if(2*index + 1 <= heapsize)
			return 2*index + 1;
		else
			return -1;
	}
	
	int rightchild(int index)
	{
		if(2*index + 2 <= heapsize)
			return 2*index + 2;
		else
			return -1;
	}
	
	int getmaximum()
	{
		return H[0];
	}	
	
	void updateinchild(int i)
	{
		int l; 
		int r,temp; 
		int max,prev = -1;
		while(prev != i)
		{
			max = i;
			prev = i;
			l = leftchild(i);
			r = rightchild(i);
			if(l != -1 && D[H[max]] < D[H[l]])		
			{
				max = l;
			}
			if(r != -1  && D[H[max]] < D[H[r]])
			{
				max = r;
			}
			if(max != i)
			{
				temp = H[max];
				H[max] = H[i];
				H[i] = temp;
				
				i = max;
			}
		}
	}
	
	void updateinparent(int i)
	{
		int temp;
		while(i != -1 && parent(i) != -1 && D[H[parent(i)]] < D[H[i]])
		{		
			//cout<<"i is "<<i<<" Parent of i "<<parent(i)<<endl;					
			temp = H[i];
			H[i] = H[parent(i)];
			H[parent(i)] = temp;
			
			i = parent(i);
		}
	}
	
	void insert(int val)
	{
		int i,temp;
		heapsize++;
		D[heapsize] = val;
		i=heapsize;				
				
		updateinparent(i);
		/*while(i != -1 && parent(i) != -1 && D[H[parent(i)]] < D[H[i]])
		{		
			//cout<<"i is "<<i<<" Parent of i "<<parent(i)<<endl;					
			temp = H[i];
			H[i] = H[parent(i)];
			H[parent(i)] = temp;
			
			i = parent(i);
		}
		
		for(int p=0;p<=heapsize;p++)
			cout<<"Current H["<<p<<"] "<<H[p]<<endl;
			
		cout<<"\n";	*/
		
	}
	
	
	
	void remove(int index)
	{
		//int l; 
		//int r,temp; 
		int i=index;
		//int max,prev = -1;
				
			
		D[H[index]] = D[H[heapsize]];
		H[index] = H[heapsize];		
		heapsize--;
		
		updateinchild(i);
		
		/*while(prev != i)
		{
			max = i;
			prev = i;
			l = leftchild(i);
			r = rightchild(i);
			if(l != -1 && D[H[max]] < D[H[l]])		
			{
				max = l;
			}
			if(r != -1  && D[H[max]] < D[H[r]])
			{
				max = r;
			}
			if(max != i)
			{
				temp = H[max];
				H[max] = H[i];
				H[i] = temp;
				
				i = max;
			}
		}*/
	}
	
	
	void display()
	{
		cout<<"Printing.."<<endl;
		for(int i=0;i<=heapsize;i++)
		{
			cout<<"Vertex "<<H[i]<<" Edge weight "<<D[H[i]]<<endl;
		}
		
	}
	
	void updatevalue(int heapindex,int val)
	{
		int left,right;
		D[H[heapindex]] = val;
		
		left = leftchild(heapindex);
		right = rightchild(heapindex);
		
		if(parent(heapindex) != -1 && D[H[heapindex]] > D[H[parent(heapindex)]]) 
		{
			updateinparent(heapindex);
		}
		else if((left != -1 && D[H[heapindex]] < D[H[left]]) || (right != -1 && D[H[heapindex]] < D[H[right]]))
		{
			updateinchild(heapindex);
		}

	}
	
	int main()
	{
		initialize();
		insert(4);		
		insert(9);
		insert(6);		
		insert(45);
		insert(89);
		insert(386);
		insert(20);
		
		//display();
		remove(0);
		display();
		updatevalue(0,100);
		display();
		updatevalue(1,101);
		display();
		updatevalue(1,8);
		display();
		updatevalue(0,1);
		display();
		//cout<<"Parent "<<D[leftchild(1)]<<endl;
		return 0;
	}
	

