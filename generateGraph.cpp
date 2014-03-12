#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "graphUtility.h"

using namespace std;

int main()
{	
	srand(time(NULL)); // Seed the time
	int dstvertex = -1, edgewt; 
	unsigned int deg=0;
	int maxvertex, minvertex=0;
	int maxedge = 15000,minedge = 1;
	maxvertex = NO_OF_VERTICES-1;
	GraphInterface *graph;
	graph = createInstance();
	graph->initialize();
	int ctr;
	
	for(int i=0;i < NO_OF_VERTICES ;i++)
	{	//deg=0;	
		//minvertex = i;
		//cout<<"\nRandom dst vertex for src vertex "<<i<<" is ";
		ctr=0;
		while(vertexdegree[i] < VERTEX_DEGREE)
		{
			
			//ctr++;
			//cout<<"\n ctr is "<<ctr;
			if(ctr >  NO_OF_VERTICES)
				break;
			do
			{
				ctr++;
				dstvertex = rand()%(maxvertex-minvertex+1)+minvertex; // Generate the number, assign to variable.
				//cout<<vertexdegree[dstvertex]<<" ";
				if(ctr > NO_OF_VERTICES)
					break;
			}while(dstvertex == i || vertexdegree[dstvertex] >= VERTEX_DEGREE);
			edgewt = rand()%(maxedge-minedge+1)+minedge;
			graph->addedge(i,dstvertex,edgewt);		
			//cout<<"\n gen graph degree for src vertex "<<i<<" is "<<vertexdegree[i]<<endl;		
		}
	}
	//cout<<"Printing..\n";
	for(int k=0;k < NO_OF_VERTICES ;k++)
	{	
		graph->display(k);
	}
	return 0;
	}
