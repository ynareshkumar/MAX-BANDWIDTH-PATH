#include <iostream>
#include <limits.h>
#include "maxheap.h"
#include "graphUtility.h"

int s =2,t = 4;
int dad[NO_OF_VERTICES];

int minimum(int a,int b)
{
	return a < b ? a:b;
}

int main()
{
	gengraphinterface * randomgraph;
	int u, v = 0,noofedges = 0;
	int distu,distv;
	
	randomgraph = createrandomgraphInstance();
	randomgraph->generaterandomgraph();		
	
	cout<<"\nGraph successfully generated"<<endl;
	
	maxheapinterface *heap;
	heap = createheapInstance();
	dad[s] = -1;
	heap->heapinitialize();
	
	heap->updatevalue(s,INT_MAX);
		
	
	while(heapsize > 0)
	{
		u = heap->remove(0);
		distu = heap->getvalue(u);
		//cout<<"u is "<<u<<" dist of u "<<distu<<endl;
		noofedges = 0;
		v = 0;
		while(noofedges < VERTEX_DEGREE && v < NO_OF_VERTICES)
		{
			while(adjmatrix[u*NO_OF_VERTICES+v] == 0)
			{
				v++;
			}
			//cout<<"V selected is "<<v<<endl;
			if(v < NO_OF_VERTICES)
			{
				noofedges++;
				distv = heap->getvalue(v);
				//cout<<"Min value chosen is "<<minimum(distu,adjmatrix[u*NO_OF_VERTICES+v])<<endl;
				if(distv < minimum(distu,adjmatrix[u*NO_OF_VERTICES+v]))
				{
					distv = minimum(distu,adjmatrix[u*NO_OF_VERTICES+v]);
					dad[v] = u;
					heap->updatevalue(v,distv);
				}
				
				v++;
			}
												
		}
	}
	int dst = t;	
	cout<<"Max bandwidth for vertex "<<t<<" from "<<s<<" is "<<D[t]<<endl;
	
	cout<<"The path between "<<dst<<" and "<<s<<" is "<<endl;
	cout<<dst;
	while(dst != s)
	{
		cout<<"->"<<dad[dst];
		dst = dad[dst];
	}
	cout<<endl;
			
	return 0;
}
	
	/*heap->insert(4);		
	heap->insert(9);
	heap->insert(6);		
	heap->insert(45);
	heap->insert(89);
	heap->insert(386);
	heap->insert(20);

	heap->remove(0);
	heap->displayheap();
	
	heap->updatevalue(0,100);
	heap->displayheap();
	heap->updatevalue(1,101);
	heap->displayheap();
	heap->updatevalue(1,8);
	heap->displayheap();
	heap->updatevalue(0,1);
	heap->displayheap();*/

