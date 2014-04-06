#include <iostream>
#include <stdio.h>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include "mstalgorithms.h"
#include "graphUtility.h"
#include "maxheap.h"

int main()
{
		std::clock_t start;
		FILE *pFile;
		double duration1,duration2,duration3;
		pFile = fopen ("time.txt","a");

		cout<<"\nNO OF VERTICES "<<NO_OF_VERTICES<<" VERTEX DEGREEE "<<VERTEX_DEGREE<<endl<<endl;     
		
		srand(time(NULL)); // Seed the time
		int maxvertex = NO_OF_VERTICES-1;
		int minvertex=0, s, t;
		gengraphinterface * randomgraph;
		
		randomgraph = createrandomgraphInstance();
		randomgraph->generaterandomgraph();		
		cout<<"\nGraph successfully generated"<<endl;
		mstimplementationinterface * mstimpl;
		
		//for(int i=0;i<5;i++)
		//{
			s = rand()%(maxvertex-minvertex+1)+minvertex;
			do
			{
				t = rand()%(maxvertex-minvertex+1)+minvertex;
			}while(s == t);		
			
			cout<<"Source vertex is "<<s<<" Destination vertex is "<<t<<endl;		
					
			cout<<"\nDIJKSTRA WITHOUT HEAP:\n"<<endl;
			start = std::clock();
			cout<<start<<" ";
			mstimpl = createalgo1instance();
			mstimpl->algoimplementation(randomgraph,s,t);
			cout<<std::clock()<<endl;
			duration1 = (std::clock()-start)/(double)CLOCKS_PER_SEC;
			cout<<"Time taken for Dijkstra without heap implementation is : "<< duration1 <<'\n';
			fprintf (pFile, "%lf",duration1);			
			
			
			cout<<"\nDIJKSTRA USING HEAP:\n"<<endl;
			start = std::clock();
			cout<<start<<" ";
			mstimpl = createalgo2instance();
			mstimpl->algoimplementation(randomgraph,s,t);
			cout<<std::clock()<<endl;
			duration2 = (std::clock()-start)/(double)CLOCKS_PER_SEC;
			cout<<"Time taken for Dijkstra using heap implementation is : "<< duration2 <<'\n';
			fprintf (pFile, " %lf",duration2);
			
			maxheapinterface *heap = createheapInstance();
			heap->heapsort();
			
			cout<<"\nKRUSKAL USING HEAPSORT:\n"<<endl;
			start = std::clock();
			
			mstimpl = createalgo3instance();
			mstimpl->algoimplementation(randomgraph,s,t);
			
			duration3 = (std::clock()-start)/(double)CLOCKS_PER_SEC;
			cout<<"Time taken for Kruskal using heapsort is : "<< duration3 <<'\n';
			fprintf (pFile, " %lf\n",duration3);
			
		//}
		
		fclose (pFile);
		 
		return 0;
}
