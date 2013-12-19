//#ifdef _graph_h
#include "Graph.h"


Graph::Graph(string xd)
{
g=new graphT;


}

void Graph::addnode(char name)
{
  //if(!nodemap[name])

	nodeT *t=new nodeT;
	t->nodename=name;
	t->nodevalue=9999;
	t->predecessor='N';

	g->nodes.push_back(t);
	pqueue.push_back(t);
	g->nodemap[name]=t;
	
	
}

void Graph::addarc(char n1,char n2,int dist)
{   // cout<<"fssfsfsf"<<endl;
	nodeT *t1=g->nodemap[n1];
	//cout<<t1->nodename<<endl;
	nodeT *t2=g->nodemap[n2];

	arcfinal(t1,t2,dist);
	arcfinal(t2,t1,dist);

}

void Graph::arcfinal(nodeT * a,nodeT * b, int len)
{
	arcT * d=new arcT;
	d->start=a;
	d->finish=b;
	d->distance=len;

	g->arcs.push_back(d);
	a->arcs.push_back(d);
}


void Graph::setNodeValue(char name ,int value,char prede)
{
	nodeT *t1=g->nodemap[name];
	t1->nodevalue=value;
	t1->predecessor=prede;

}
void Graph::printarcs()
{  for (int i=0;i<g->arcs.size();i++)
{
	cout<<g->arcs[i]->start->nodename<<"-----"<<g->arcs[i]->finish->nodename<<endl;
}
}

void Graph::sort()
{
	for(int i=0;i<pqueue.size()-1;i++)
	{
		int minIndex=i;
		for(int j=i+1;j<pqueue.size();j++)
		{
			if(pqueue[j]->nodevalue < pqueue[minIndex]->nodevalue) 
			{
				minIndex=j;
		     }
		}
		//Swap function
			if(minIndex != i)
			{
			nodeT * temp =pqueue[minIndex];
			pqueue[minIndex]=pqueue[i];
			pqueue[i]=temp;
		}
	}

	for(int i=0;i<pqueue.size()-1;i++)
	{
		if((pqueue[i]->nodevalue==pqueue[i+1]->nodevalue) && (pqueue[i]->nodename>pqueue[i+1]->nodename))
		{
			nodeT * temp =pqueue[i+1];
			pqueue[i+1]=pqueue[i];
			pqueue[i]=temp; 
		}
	}
	
   /*
   //Print Queue
   for(int i=0;i<pqueue.size();i++)
   {
	   cout<<pqueue[i]->nodename<<pqueue[i]->nodevalue;
   }
   */

}

void Graph::rearrangeQueue()
{
	for(int i=0;i<pqueue.size()-1;i++)
	{
		pqueue[i]=pqueue[i+1];

	}
	pqueue.pop_back();

}

void Graph::prims()
{
	sort();
	vector<char> cycle;
	while(!pqueue.empty())
	{
		nodeT *f =pqueue[0];
		cout<<f->nodename<<"---predecesspr:"<<f->predecessor<<endl;
		rearrangeQueue();
		cycle.push_back(f->nodename);
		for(int m=0;m < f->arcs.size();m++)
		{   int x=0;

		   ////Checking if already visited
			for(int i=0;i<cycle.size();i++)
			{
				if(cycle[i]==f->arcs[m]->finish->nodename)
				{
					x=1;
				}
			}
			if(x==0)
			{
				if(f->arcs[m]->finish->nodevalue > f->arcs[m]->distance)
				{
					setNodeValue(f->arcs[m]->finish->nodename,f->arcs[m]->distance,f->arcs[m]->start->nodename);
					
				}
			}


		}
		sort();

	}
}
//#endif
