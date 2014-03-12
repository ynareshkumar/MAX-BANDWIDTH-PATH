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
	int maxedge = 15000, minedge = 1;
	maxvertex = NO_OF_VERTICES-1;
	GraphInterface *graph;
	graph = createInstance();
	graph->initialize();
	for(int i=0;i < NO_OF_VERTICES ;i++)
	{	deg=0;	
		//minvertex = i;
		//cout<<"\nRandom dst vertex for src vertex "<<i<<" is ";
		while(deg < VERTEX_DEGREE)
		{
			do
			{
				dstvertex = rand()%(maxvertex-minvertex+1)+minvertex; // Generate the number, assign to variable.
				//cout<<dstvertex<<" ";
			}while(dstvertex == i);
			edgewt = rand()%(maxedge-minedge+1)+minedge;
			deg = graph->addedge(i,dstvertex,edgewt);		
			//cout<<"\n gen graph degree "<<deg<<endl;		
		}
	}
	for(int k=0;k < NO_OF_VERTICES ;k++)
	{	
		graph->display(k);
	}	
	return 0;
}
