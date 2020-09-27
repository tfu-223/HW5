
#include "Graph.h"
#include "BetterPriorityQueue.h"
#include <iostream>
#include <climits>
#include <cassert>

using namespace std;

// Total time complexity: n * ( O(n) + O(log(n)) )
int dijkstra(const GraphNode *start, const GraphNode *end, Graph *g)
{
	BetterPriorityQueue q;
	int ans;

	// Push n DNodes into the priority queue,
	// Time complexity: O(n)
	for (size_t i = 0; i < g->GetNodes().size(); ++i)
	{
		DNode n;
		n.node = g->GetNodes().at(i);
		if (n.node == start)
		{
			n.pri = 0;
		} else {
			n.pri = INT_MAX;
		}
		q.push(n);
	}

	// Time complexity: n * ( 3*O(n) + O(log(n)) )
	while (q.size() > 0)
	{
		DNode n = q.top();
		// Get the adjacent nodes
		// Time complexity: 3*O(n) + O(log(n))
		for (size_t i = 0; i < g->GetEdges(n.node).size(); ++i)
		{
			DNode m;
			m.node = g->GetEdges(n.node)[i]->to; // O(n)
			if (q.Contains(m)) // O(n)
			{
				m.pri = n.pri + g->GetEdges(n.node)[i]->weight;
				q.Update(m); // O(n)
			}
		}
		// cout << q.ToString() << endl;
		cout << "(" << n.node->key << ": " << n.pri << ")" << endl;
		if (n.node == end)
			ans = n.pri;
		q.pop(); // O(log(n))
	}

	return ans;
}


int DijkstraTest()
{
	// Note, when grading I will replace this with
	// other / more tests.  I recommend you do the same!
	
	Graph *g = new Graph();
	
	GraphNode *a = g->AddNode('1');
	GraphNode *b = g->AddNode('2');
	GraphNode *c = g->AddNode('3');
	GraphNode *d = g->AddNode('4');
	GraphNode *e = g->AddNode('5');
	GraphNode *f = g->AddNode('6');
	
	g->AddEdge(a, b, 7);
	g->AddEdge(b, a, 7);
	g->AddEdge(a, c, 9);
	g->AddEdge(c, a, 9);
	g->AddEdge(a, f, 14);
	g->AddEdge(f, a, 14);
	
	g->AddEdge(b, c, 10);
	g->AddEdge(c, b, 10);
	g->AddEdge(b, d, 15);
	g->AddEdge(d, b, 15);
	
	g->AddEdge(c, f, 2);
	g->AddEdge(f, c, 2);
	g->AddEdge(c, d, 11);
	g->AddEdge(d, c, 11);
	
	g->AddEdge(f, e, 9);
	g->AddEdge(e, f, 9);
	
	g->AddEdge(d, e, 6);
	g->AddEdge(e, d, 6);
	
	
	cout << g->ToString() << endl;
	
	unsigned int ans = dijkstra(g->NodeAt(0), e, g);
	// assert(ans == 20);

	delete g;
		
	Graph *g2 = new Graph();

	GraphNode *a2 = g->AddNode('a');
	GraphNode *b2 = g->AddNode('b');
	GraphNode *c2 = g->AddNode('c');
	GraphNode *d2 = g->AddNode('d');
	GraphNode *e2 = g->AddNode('e');
	GraphNode *f2 = g->AddNode('f');

	g2->AddEdge(a, b, 2);
	g2->AddEdge(b, a, 2);
	g2->AddEdge(a, c, 7);
	g2->AddEdge(c, a, 7);
	g2->AddEdge(a, f, 3);
	g2->AddEdge(f, a, 3);
	
	g2->AddEdge(b, c, 2);
	g2->AddEdge(c, b, 2);
	g2->AddEdge(b, d, 9);
	g2->AddEdge(d, b, 9);
	
	g2->AddEdge(c, f, 4);
	g2->AddEdge(f, c, 4);
	g2->AddEdge(c, d, 8);
	g2->AddEdge(d, c, 8);
	
	g2->AddEdge(f, e, 9);
	g2->AddEdge(e, f, 9);
	
	g2->AddEdge(d, e, 6);
	g2->AddEdge(e, d, 6);\
	
	cout << g2->ToString() << endl;
	
	unsigned int ans2 = dijkstra(g2->NodeAt(0), a, g);

	delete g2;

	return ans;
}


int main()
{
	int ans = DijkstraTest();
	cout << "ans: "  << ans << endl;
	
	return 0;
}
