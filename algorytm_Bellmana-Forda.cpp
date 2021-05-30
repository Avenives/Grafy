#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct edge
{
	int from;
	int to;
	int weight;	
};

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	
	int V, E, S;
	input >> V >> E >> S;

	vector< struct edge> edges(E);
	for(int i=0;i<E;++i)
		input >> edges[i].from >> edges[i].to >> edges[i].weight;
		
	vector<int> d(V);
	vector<int> p(V);
	
	for(int i=0;i<V;++i)
	{
		d[i]=1000000000;
		p[i]=-1;
	}
	d[S]=0;
	
	for(int i=1;i<V;++i)
	{
		for(int e=0;e<E;++e)
		{
			int u = edges[e].from;
			int v = edges[e].to;
			int w = edges[e].weight;
			
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				p[v]=u;
			}
		}
	}
	
	for(int i=0;i<V;++i)
	{
		cout << i << ": " << d[i] << endl;
		output << i << ": " << d[i] << endl;
	}
	
	
	
}
