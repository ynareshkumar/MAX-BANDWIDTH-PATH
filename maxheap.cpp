#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <vector>
#include "graphUtility.h"
#include "maxheap.h"

using namespace std;

int H[NO_OF_VERTICES];
int heapsize;
int edgesize;
int D[NO_OF_VERTICES];

std::vector<struct edges> edgeparameters(NO_OF_VERTICES*VERTEX_DEGREE);

class maxheapoperations : public maxheapinterface
{
	private:
		
		
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
		
		public:				
		
		maxheapoperations()
		{
			
		}
		
		void heapinitialize()
		{
			heapsize = -1;
			for(int i=0;i<NO_OF_VERTICES;i++)
			{
				H[i] = i;
				D[i] = INT_MIN;
				heapsize++;
			}
		}		
				
		void insert(int val)
		{
			int i,temp;
			heapsize++;
			D[heapsize] = val;
			i=heapsize;				
					
			updateinparent(i);			
			
		}
		
		int getvalue(int i)
		{
			return D[i];
		}				
		
		
		int remove(int index)
		{

			int i=index;	
			int returnindex = H[index];
			//D[H[index]] = D[H[heapsize]];
			H[index] = H[heapsize];		
			heapsize--;
			
			updateinchild(i);			
			return returnindex;
			
		}
		
		
		void displayheap()
		{
			cout<<"Printing.."<<endl;
			for(int i=0;i<=heapsize;i++)
			{
				cout<<"Vertex "<<H[i]<<" Edge weight "<<D[H[i]]<<endl;
			}
			
		}
		
		void updatevalue(int heapind,int val)
		{
			int left,right,heapindex;
			
			for(int m=0;m<NO_OF_VERTICES;m++)
			{
				if(H[m] == heapind)
				{
					heapindex = m;
					break;
				}
			}
			D[H[heapindex]] = val;			
			
			left = leftchild(heapindex);
			right = rightchild(heapindex);
			
			if(parent(heapindex) != -1 && D[H[heapindex]] > D[H[parent(heapindex)]]) 
			{
				//cout<<"Updating in parent "<<endl;
				updateinparent(heapindex);
			}
			else if((left != -1 && D[H[heapindex]] < D[H[left]]) || (right != -1 && D[H[heapindex]] < D[H[right]]))
			{
				//cout<<"Updating in child "<<endl;
				updateinchild(heapindex);
			}
			//cout<<"Value updated for "<<H[heapindex]<<" with "<<D[1]<<endl;
	
		}
		
		void insertedge(struct edges ed)
		{
			edgesize++;
			int i = edgesize;
			edgeparameters[edgesize] = ed;
			struct edges par;
			while(parent(i) != -1) 
			{
				par = edgeparameters[parent(i)];
				if(par.edgeweight < ed.edgeweight)
				{
					edgeparameters[parent(i)] = ed;
					edgeparameters[i] = par;
				}
				i = parent(i);
			}
			
		}
		
		int leftc(int i)
		{
			if(2*i+1 <= edgesize)
				return 2*i+1;
			else
				return -1;
		}
		
		int rightc(int i)
		{
			if(2*i+2 <= edgesize)
				return 2*i+2;
			else
				return -1;
		}
		
		
		struct edges extractmax()
		{
			struct edges edg = edgeparameters[0];
			struct edges temp,maxedge;
			edgeparameters[0] = edgeparameters[edgesize];
			edgesize--;
			int i = 0;
			int left,right;
			int max,prev = -1;
			while(prev != i)
			{
				max =i;
				prev = i;
				maxedge = edgeparameters[max];
				left = leftc(i);
				right = rightc(i);
				if(left != -1)		
				{
					temp = edgeparameters[left];
					if(temp.edgeweight > maxedge.edgeweight)
					{
						max = left;
						maxedge = edgeparameters[left];
					}
				}
				if(right != -1)
				{
					temp = edgeparameters[right];
					if(temp.edgeweight > maxedge.edgeweight)
					{
						max = right;
						maxedge = edgeparameters[right];
					}
				}
				if(max != i)
				{
					temp = edgeparameters[i];
					edgeparameters[i] = maxedge;
					if(max == left)
						edgeparameters[left] = temp;
					else if(max ==right)
						edgeparameters[right] = temp;
					
					i = max;
				}
			}
			
			return edg;
			
		}
		
		void heapsort()
		{
			int n = 0, noofedges, v;
			edgesize = -1;
			while(n < NO_OF_VERTICES)
			{				
				noofedges = 0;
				v = 0;
				while(noofedges < VERTEX_DEGREE && v < NO_OF_VERTICES)
				{
					while(adjmatrix[n*NO_OF_VERTICES+v] == 0)
					{
						v++;
					}
					if(v < NO_OF_VERTICES)
					{
						noofedges++;
						struct edges e;
						e.u = n;
						e.v = v;
						e.edgeweight = adjmatrix[n*NO_OF_VERTICES+v];
						if(n <= v)
						{
							//cout<<"Edge weight added is "<<e.edgeweight<<endl;
							insertedge(e);					
						}
						
					}
					v++;
				}
				n++;
				
			}
		}
		
	};
	
	maxheapinterface * createheapInstance()
		{
			return new maxheapoperations();
		}

	
	/*int main()
	{
		initialize();
		insert(4);		
		insert(9);
		insert(6);		
		insert(45);
		insert(89);
		insert(386);		insert(20);
		
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
	}*/
	

