#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "graphUtility.h"

using namespace std;

class creategraph : public gengraphinterface
{	
	public:
	
	int dstvertex, edgewt; 
	int ctr,breakaway;
	unsigned int deg;
	int maxvertex, minvertex;
	int maxedge,minedge;
	
	creategraph()
	{
		
	}
	
	void generaterandomgraph()
	{
		dstvertex = -1;
		deg=0;		
		minvertex=0;
		maxedge = 15000;
		minedge = 1;
	
		srand(time(NULL)); // Seed the time
		
		maxvertex = NO_OF_VERTICES-1;
		GraphInterface *graph;
		graph = creategraphInstance();
		graph->initialize();
	
	
		for(int i=0;i < NO_OF_VERTICES ;i++)
		{	//deg=0;	
			//minvertex = i;
			//cout<<"\nRandom dst vertex for src vertex "<<i<<" is ";
			ctr=0;
			breakaway = 1;
			while(vertexdegree[i] < VERTEX_DEGREE)
			{
	
				//ctr++;
				//cout<<"\n ctr is "<<ctr;
				if(ctr >  NO_OF_VERTICES || !breakaway)
					break;
				do
				{
					ctr++;
					dstvertex = rand()%(maxvertex-minvertex+1)+minvertex; // Generate the number, assign to variable.
					//cout<<vertexdegree[dstvertex]<<" ";
					if(ctr > NO_OF_VERTICES)
					{
						breakaway=0;
						break;
					}
				}while(dstvertex == i || vertexdegree[dstvertex] >= VERTEX_DEGREE);
				if(breakaway)
				{
					edgewt = rand()%(maxedge-minedge+1)+minedge;
					graph->addedge(i,dstvertex,edgewt);	
				}	
				//cout<<"\n gen graph degree for src vertex "<<i<<" is "<<vertexdegree[i]<<endl;		
			}
		}
		//cout<<"Printing..\n";
		/*for(int k=0;k < NO_OF_VERTICES ;k++)
		{	
			graph->display(k);
		}*/
			
	}
};

gengraphinterface * createrandomgraphInstance()
		{
			return new creategraph();
		}
