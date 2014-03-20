#include <iostream>
#include <vector>
#include "graphUtility.h"

int s = 1, t = 3, noofedges = 0, j = 0, nooffringes = 0, fringelength = 0;
gengraphinterface * randomgraph;
int status[NO_OF_VERTICES],dist[NO_OF_VERTICES],dad[NO_OF_VERTICES],fringes[NO_OF_VERTICES];
//vector<int> adjacencymatrix(NO_OF_VERTICES*NO_OF_VERTICES);

int getmaximumfringe()
{
	int max = 0,index;
	for(int i=0;i<fringelength;i++)
	{
		if(status[fringes[i]] == 1)
		{
			if(max < dist[fringes[i]])
			{
				max = dist[fringes[i]];
				index = fringes[i];
			}
		}
	}
	return index;
}

int minimum(int a,int b)
{
	return a < b ? a:b;
}

void dijkstraalgorithm()
{
	int k = 0,maxindex;
	
	while(noofedges < VERTEX_DEGREE && j < NO_OF_VERTICES)
	{
		while(adjmatrix[s*NO_OF_VERTICES+j] == 0)
		{
			j++;
		}
		if(j < NO_OF_VERTICES)
		{
			noofedges++;
			dist[j] = adjmatrix[s*NO_OF_VERTICES+j];
			fringes[fringelength] = j;
			fringelength++;
			nooffringes++;
			status[j] = 1;//Vertex is a fringe
			dad[j] = s;
			j++;
		}
	}
		
	cout<<"Initial done"<<endl;
	//cout<<"val at 0 is "<<adjmatrix[0]<<endl;	
	//cout<<"Fringes for source done!"<<endl;	
	while(nooffringes > 0)
	{
		maxindex = getmaximumfringe();
		//cout<<"Max fringe index is "<<maxindex<<" "<<adjmatrix[maxindex*NO_OF_VERTICES+k]<<endl;
		status[maxindex] = 2;		
		nooffringes--;
		noofedges = 0;
		k=0;
		while(noofedges < VERTEX_DEGREE && k < NO_OF_VERTICES)
		{
			while(adjmatrix[maxindex*NO_OF_VERTICES+k] == 0)
			{
				//cout<<"Searching.."<<endl;
				k++;
			}
			if(k < NO_OF_VERTICES)
			{
				noofedges++;
				//cout<<"Fringe found is "<<k<<endl;
				//Unseen vertex
				if(status[k] == 0)
				{
					status[k] = 1;
					fringes[fringelength] = k;
					fringelength++;
					nooffringes++;
					dist[k] = minimum(dist[maxindex],adjmatrix[maxindex*NO_OF_VERTICES+k]);
					//if(k == t)
						//cout<<"Dist initially for "<<k<<" is "<<dist[k]<<endl;
					dad[k] = maxindex;
				}
				//Fringe vertex
				else if(status[k] == 1 && dist[k] < minimum(dist[maxindex],adjmatrix[maxindex*NO_OF_VERTICES+k]))
				{
					dist[k] = minimum(dist[maxindex],adjmatrix[maxindex*NO_OF_VERTICES+k]);
					dad[k] = maxindex;
					//if(k == t)
						//cout<<"Dist after updation for "<<k<<" is "<<dist[k]<<endl;
				}				
				k++;
			}
			
		}
		
	}
}

int main()
{
	int dst = t;
	randomgraph = createrandomgraphInstance();
	randomgraph->generaterandomgraph();		
	
	cout<<"\nGraph successfully generated"<<endl;
	for(int v=0;v<NO_OF_VERTICES;v++)
		status[v] = 0;//All vertices are unseen
		
	status[s] = 2;//Vertx is in-tree
	dist[s] = 0;
	dad[s] = -1;
	
	dijkstraalgorithm();
	
	cout<<"Max bandwidth for vertex "<<t<<" from "<<s<<" is "<<dist[t]<<endl;
	
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
