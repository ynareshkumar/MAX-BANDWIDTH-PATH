#ifndef MAXHEAPINTERFACE_H
#define MAXHEAPINTERFACE_H

#include "graphUtility.h"

extern int H[NO_OF_VERTICES];
extern int heapsize;
extern int edgesize;
extern int D[NO_OF_VERTICES];

struct edges
{
	int u;
	int v;
	int edgeweight;
};

extern std::vector<struct edges> edgeparameters;

class maxheapinterface
{
	public:		
	virtual void heapinitialize() = 0;
	virtual void insert(int val) = 0;
	virtual int remove(int index) = 0;
	virtual int getvalue(int i) = 0;
	virtual void displayheap() = 0;
	virtual void updatevalue(int heapindex,int val) = 0;
	virtual void heapsort() = 0;
	virtual struct edges extractmax() = 0;
};


maxheapinterface * createheapInstance();

#endif
