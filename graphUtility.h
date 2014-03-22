#ifndef GRAPHINTERFACE_H
#define GRAPHINTERFACE_H

#include <vector>
#define NO_OF_VERTICES 5000
#define VERTEX_DEGREE 6

using namespace std;

extern std::vector<int> adjmatrix;
extern unsigned int vertexdegree[NO_OF_VERTICES];

struct edgedetails{
	unsigned int edgeweight;
	struct edgedetails *next;	
};


class GraphInterface
{
public:
  //GraphInterface();
  virtual void addedge(int srcvertex,int dstvertex,unsigned int edgeweight) = 0;
  virtual void display(int srcvertex) = 0;
  virtual void initialize() = 0;
};

class gengraphinterface
{
	public:
	virtual void generaterandomgraph() = 0;
};

gengraphinterface * createrandomgraphInstance();

GraphInterface * creategraphInstance();

#endif
