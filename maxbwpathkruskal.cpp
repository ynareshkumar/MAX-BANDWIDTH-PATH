#include <iostream>
#include <limits.h>
#include "graphUtility.h"
#include "maxheap.h"
#include "kruskal.h"
#include "mstalgorithms.h"

class kruskalimpl : public mstimplementationinterface
	{
	private:
	int minimum(int a,int b)
	{
		return a < b ? a:b;
	}
	
	public:
	kruskalimpl()
	{
		
	}
	
	void algoimplementation(gengraphinterface * randomgraph,int s,int t)
	{
		maxspanningtreeinterface * mst;
		int dad[NO_OF_VERTICES];	
		//int s = 1, t = 4;
		int u,v = 0,noofedges = 0,distu,distv;	
			
		mst = createmstInstance();
		mst->kruskalalgorithm();
		/*for(int k=0;k < NO_OF_VERTICES ;k++)
		{
			mst->displaymst(k);
		}*/
		
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
				while(maxspanningtree[u*NO_OF_VERTICES+v] == 0)
				{
					v++;
				}
				
				if(v < NO_OF_VERTICES)
				{
					//cout<<"V selected is "<<v<<endl;
					noofedges++;
					distv = heap->getvalue(v);
					//cout<<"Min value chosen is "<<minimum(distu,maxspanningtree[u*NO_OF_VERTICES+v])<<endl;
					if(distv < minimum(distu,maxspanningtree[u*NO_OF_VERTICES+v]))
					{
						distv = minimum(distu,maxspanningtree[u*NO_OF_VERTICES+v]);
						dad[v] = u;
						heap->updatevalue(v,distv);
					}
					
					
				}
				v++;
													
			}
		}
		int dst = t;	
		cout<<"Max bandwidth for vertex "<<t<<" from "<<s<<" is "<<D[t]<<endl;
		
		/*cout<<"The path between "<<dst<<" and "<<s<<" is "<<endl;
		cout<<dst;
		while(dst != s)
		{
			cout<<"->"<<dad[dst];
			dst = dad[dst];
		}
		cout<<endl;*/
		
	}
};

mstimplementationinterface * createalgo3instance()
		{
			return new kruskalimpl();
		}
