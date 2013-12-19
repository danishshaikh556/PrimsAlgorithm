#ifndef _Graph_h
#define _Graph_h
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>



#include <fstream>
#include <vector>
#include <string>
using namespace std;



class Graph
{
public:
  
Graph(string xd);
	
	void addnode(char name);
	void addarc(char n1,char n2,int dist);
	void prims();
	void printarcs();
private:

	struct nodeT;
struct arcT;
	struct graphT
	{
		vector<nodeT *>nodes;
		vector<arcT * > arcs;
		map<char,nodeT * > nodemap;
	};
	struct nodeT{
		char nodename;
		int nodevalue;
		char predecessor;
		vector<arcT * > arcs;
	};
	struct arcT{
		nodeT * start;
		nodeT * finish;
		int distance;
	};

	vector<nodeT *>pqueue;
	void sort();   ///Try returning a pointer to the node here
	void rearrangeQueue();
	
	void setNodeValue(char name,int value,char prede);
	void arcfinal(nodeT * a,nodeT * b, int len);
	graphT * g;
	//graphT *g=new graphT;
};

//#include "BST.cpp"

#endif

