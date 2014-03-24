#include <iostream>
#include <stack> 
#include "maxheap.h"
#include "graphUtility.h"

gengraphinterface * randomgraph;
maxheapinterface *heap;
int dad[NO_OF_VERTICES];
int rank[NO_OF_VERTICES];

std::vector<int> maxspanningtree(NO_OF_VERTICES*NO_OF_VERTICES);

void makeset(int v)
{
	dad[v] = 0;
	rank[v] = 0;
}

int find(int v)
{
	std::stack<int> S;
	int w = v, u;
	
	while(dad[w] != 0)
	{
		S.push(w);
		w = dad[w];
	}
	
	while(!S.empty())
	{
		u = S.top();
		S.pop();
		dad[u] = w;
	}
	
	return w;
	
}

void merge(int r1,int r2)
{
	if(rank[r1] < rank[r2])
		dad[r1] = r2;
	else if(rank[r1] > rank[r2])
		dad[r2] = r1;
	else
	{
		dad[r2] = r1;
		rank[r1] += 1;
	}
}

void kruskalalgorithm()
{
	struct edges e;
	int r1,r2,u;
	heap->heapsort();
	
	for(int i=0;i<NO_OF_VERTICES;i++)
		makeset(i);
	
	while(edgesize > 0)
	{
		e = heap->extractmax();
		//cout<<" u is "<<e.u<<" v is "<<e.v<<" wt is "<<e.edgeweight<<endl;
		r1 = find(e.u);
		r2 = find(e.v);
		if(r1 != r2)
		{
			maxspanningtree[(e.u)*NO_OF_VERTICES+(e.v)] = e.edgeweight;
			merge(r1,r2);
		}
		
	} 
}

void displaymst(int srcvertex)
{
	cout<<"Source vertex "<<srcvertex<<endl;
	cout<<"Dst vertex Edge weight"<<endl;
	for(int i=0;i<NO_OF_VERTICES;i++)
	{
		if (maxspanningtree[srcvertex*NO_OF_VERTICES+i] != 0)
		{
			cout<<i<<"\t    "<<maxspanningtree[srcvertex*NO_OF_VERTICES+i]<<endl;			
		}
	}
}

int main()
{
	
	randomgraph = createrandomgraphInstance();
	randomgraph->generaterandomgraph();
	
	cout<<"\nGraph successfully generated"<<endl;
		
	heap = createheapInstance();	
	kruskalalgorithm();
	for(int k=0;k < NO_OF_VERTICES ;k++)
	{
		displaymst(k);
	}
	
	return 0;
}
