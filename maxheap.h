#ifndef MAXHEAPINTERFACE_H
#define MAXHEAPINTERFACE_H

class maxheapinterface
{
	public:
	virtual void heapinitialize() = 0;
	virtual void insert(int val) = 0;
	virtual void remove(int index) = 0;
	virtual void displayheap() = 0;
	virtual void updatevalue(int heapindex,int val) = 0;
};


maxheapinterface * createheapInstance();

#endif
