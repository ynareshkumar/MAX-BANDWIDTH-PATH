#include <iostream>
#include <stack> 
#include "maxheap.h"
#include "graphUtility.h"
#include "kruskal.h"

std::vector<int> maxspanningtree(NO_OF_VERTICES*NO_OF_VERTICES);

class kruskalmstimplementation:public maxspanningtreeinterface
{
	private:
	maxheapinterface *heap;
	int dad[NO_OF_VERTICES];
	int rank[NO_OF_VERTICES];
	
	void makeset(int v)
	{
		dad[v] = -1;
		rank[v] = 0;
	}
	
	int find(int v)
	{
		std::stack<int> S;
		int w = v, u;
		
		while(dad[w] != -1)
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
		//cout<<"w for "<<v<<" is "<<w<<endl;
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
			//cout<<"rank[r1] "<<rank[r1]<<" rank[r2] "<<rank[r2]<<endl;
	}
	
	public:
	
	kruskalmstimplementation()
	{
		heap = createheapInstance();
	}
	
	void kruskalalgorithm()
	{
		struct edges e;
		int r1,r2,u;		
		//heap->heapsort();
		int edgesadded = 0;
		for(int i=0;i<NO_OF_VERTICES;i++)
			makeset(i);
		
		while(edgesize > 0 && edgesadded < NO_OF_VERTICES-1)
		{
			e = heap->extractmax();			
			r1 = find(e.u);
			r2 = find(e.v);
			//cout<<" u value is "<<e.u<<" v is "<<e.v<<" wt is "<<e.edgeweight<<" r1 is "<<r1<<" r2 is "<<r2<<endl;
			if(r1 != r2 && edgesadded < NO_OF_VERTICES-1)
			{
				edgesadded++;
				//cout<<" u is "<<e.u<<" v is "<<e.v<<" wt is "<<e.edgeweight<<" r1 is "<<r1<<" r2 is "<<r2<<endl;
				maxspanningtree[(e.u)*NO_OF_VERTICES+(e.v)] = e.edgeweight;
				maxspanningtree[(e.v)*NO_OF_VERTICES+(e.u)] = e.edgeweight;
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
};

maxspanningtreeinterface * createmstInstance()
		{
			return new kruskalmstimplementation();
		}

/*int main()
{
	
	randomgraph = createrandomgraphInstance();
	randomgraph->generaterandomgraph();
	
	cout<<"\nGraph successfully generated"<<endl;
		
		
	kruskalalgorithm();
	for(int k=0;k < NO_OF_VERTICES ;k++)
	{
		displaymst(k);
	}
	
	return 0;
}*/
