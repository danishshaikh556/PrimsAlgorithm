#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include "Graph.h"

#include<map>
#include<set>

#include <fstream>
#include <vector>
#include <string>
using namespace std;
string a,m,n;
float b,c,l;

int main()
{
  Graph danny("danish");

	/*
	ifstream in;
	string s="Stanfordnodes.txt";
	in.open(s.c_str());
	if(in.fail()) cout<<"wew"<<endl;
	while(!in.fail())
	{
		
	//	getline(in,a);
		in>>a>>b>>c;
		//cout<<a<<b<<c<<endl;
	danny.addnode(a,b,c);
	}
	in.close();
	
	ifstream inn;
	string q="Stanfordarcs.txt";
	inn.open(q.c_str());
	if(inn.fail()) cout<<"wew"<<endl;
	while(!inn.fail())
	{
		//cout<<"sdsddse"<<endl;
	//	getline(in,a);
		inn>>m>>n>>l;
		//cout<<m<<n<<l<<endl;
	danny.addarc(m,n,l);
	}*/
  danny.addnode('A');
  danny.addnode('B');
  danny.addnode('C');
  danny.addnode('D');
  danny.addnode('E');
  danny.addnode('F');
  danny.addnode('G');
//danny.addnode('H');
 // danny.addnode('I');

danny.addarc('A','B', 3);
danny.addarc('A','E',4);
danny.addarc('B','C',7);
danny.addarc('B','E',6);
danny.addarc('B','F',5);
danny.addarc('C','D',9);
danny.addarc('C','F',8);
danny.addarc('D','F',9);
danny.addarc('D','G',4);
danny.addarc('E','F',6);
  danny.addarc('F','G',8);


/*	  
  danny.addarc('A','B',4);
  danny.addarc('A','H',8);
  danny.addarc('B','H',11);
  danny.addarc('B','C',8);
  danny.addarc('H','I',7);
  danny.addarc('I','C',2);
  danny.addarc('I','G',6);
  danny.addarc('H','G',1);
  danny.addarc('C','F',4);
  danny.addarc('F','G',2);
  danny.addarc('C','D',7);
  danny.addarc('D','F',14);
  danny.addarc('D','E',9);
  danny.addarc('E','F',10);
  
*/












  


	danny.printarcs();
	danny.prims();
	int yu;
	cout<<"thsfisend"<<endl;
	cin>>yu;

	return 1;
}
