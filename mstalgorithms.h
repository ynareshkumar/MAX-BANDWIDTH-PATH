#include "graphUtility.h"

class mstimplementationinterface
{
	public:
	virtual void algoimplementation(gengraphinterface * randomgraph,int s,int t) = 0;
};

mstimplementationinterface * createalgo1instance();
mstimplementationinterface * createalgo2instance();
mstimplementationinterface * createalgo3instance();
