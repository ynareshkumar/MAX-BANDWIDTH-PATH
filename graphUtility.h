#ifndef GRAPHINTERFACE_H
#define GRAPHINTERFACE_H

#include <vector>
#define NO_OF_VERTICES 5000
#define VERTEX_DEGREE 1000

using namespace std;

static std::vector<int> adjmatrix(NO_OF_VERTICES*NO_OF_VERTICES);
extern unsigned int vertexdegree[NO_OF_VERTICES];

struct edgedetails{
	unsigned int edgeweight;
	struct edgedetails *next;	
};


class GraphInterface
{
public:
  //GraphInterface();
  //virtual ~MyObjectIn
  virtual void addedge(int srcvertex,int dstvertex,unsigned int edgeweight) = 0;
  virtual void display(int srcvertex) = 0;
  virtual void initialize() = 0;
};

GraphInterface * createInstance();

#endif
