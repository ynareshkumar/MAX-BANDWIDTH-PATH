#include <vector>

using namespace std;

extern std::vector<int> maxspanningtree;

class maxspanningtreeinterface
{
	public:
	virtual void kruskalalgorithm() = 0;
	virtual void displaymst(int srcvertex) = 0;
};

maxspanningtreeinterface * createmstInstance();
