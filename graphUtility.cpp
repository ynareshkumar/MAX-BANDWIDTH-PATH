#include <iostream>
#include <vector>
#include <stdlib.h>
#include "graphUtility.h"

using namespace std;

unsigned int vertexdegree[NO_OF_VERTICES];
std::vector<int> adjmatrix(NO_OF_VERTICES*NO_OF_VERTICES);

class UndirectedGraph : public GraphInterface
{
	public:
		UndirectedGraph()
		{

		}			

		void initialize()
		{
			for(int i=0;i<NO_OF_VERTICES;i++)
				vertexdegree[i] = 0;

		}

void addedge(int srcvertex,int dstvertex,unsigned int edgeweight)
		{
			/*struct edgedetails *newedge = (struct edgedetails *)malloc(sizeof(struct edgedetails));
			newedge->edgeweight = edgeweight;
			if (adjmatrix[srcvertex*NO_OF_VERTICES+dstvertex].empty)
			{
				newedge->next = NULL;
				adjmatrix[srcvertex*NO_OF_VERTICES+dstvertex].ed = newedge;
				adjmatrix[srcvertex*NO_OF_VERTICES+dstvertex].empty = 0;
			}
			else
			{
				newedge->next = &(adjmatrix[srcvertex*NO_OF_VERTICES+dstvertex].ed);
				adjmatrix[srcvertex*NO_OF_VERTICES+dstvertex].ed = newedge;
			}*/
			if(adjmatrix[srcvertex*NO_OF_VERTICES+dstvertex] == 0 && vertexdegree[srcvertex] < VERTEX_DEGREE)
			{
				adjmatrix[srcvertex*NO_OF_VERTICES+dstvertex] = edgeweight;
				vertexdegree[srcvertex]++;
				//cout<<"\nsrc vertex "<<srcvertex<<" degree "<<vertexdegree[srcvertex]<<endl;
				adjmatrix[dstvertex*NO_OF_VERTICES+srcvertex] = edgeweight;
				vertexdegree[dstvertex]++;
			}			

		}

void display(int srcvertex)
		{
			int size = 0;
			static double sumofedges = 0 ;
			cout<<"Source vertex "<<srcvertex<<endl;
			cout<<"\nDst vertex Edge weight"<<endl;
			for(int i=0;i<NO_OF_VERTICES;i++)
				{
					/*if (!adjmatrix[srcvertex*NO_OF_VERTICES+i].empty)
						cout<<i<<" ";*/
					if (adjmatrix[srcvertex*NO_OF_VERTICES+i] != 0)
					{
						cout<<i<<"\t    "<<adjmatrix[srcvertex*NO_OF_VERTICES+i]<<endl;
						size++;
					}
				}
			/*if(size != VERTEX_DEGREE)
				cout<<"\nsrc vertex "<<srcvertex<<" Degree is "<<size;*/
			//sumofedges += size;
			//cout<<"\n Sum of edges is "<<sumofedges;
		}
};

GraphInterface * creategraphInstance()
		{
			return new UndirectedGraph();
		}
