
#include <iostream>
#include <queue>
#include <cassert>
#include "Graph.h"
#include "BetterPriorityQueue.h"

using namespace std;


void ContainsTest() {
	cout << "Testing Contains Helper Method..." << endl;
	
	Graph g = Graph();
	BetterPriorityQueue q;
	
	GraphNode *a = g.AddNode('a');
	DNode n;
	n.node = a;
	q.push(n);

	assert(q.Contains(n) == 0);
	
	// more tests go here!
	Graph g2 = Graph();
	BetterPriorityQueue q2;
	
	GraphNode *b = g2.AddNode('b');
	GraphNode *c = g2.AddNode('c');
	DNode n2;
	n2.node = b;
	q2.push(n2);
	DNode n3;
	n3.node = c;
	q2.push(n3);

	assert(q2.Contains(n3) == 1);
	
	cout << "PASSED!" << endl << endl;
}


void UpdateTest()
{
	cout << "Testing Update Helper Method..." << endl;
	
	Graph g = Graph();
	BetterPriorityQueue q;
	
	g.AddNode('a');
	g.AddNode('b');
	g.AddNode('c');
	g.AddNode('d');
	GraphNode *e = g.AddNode('e');
	GraphNode *f = g.AddNode('f');
	vector<GraphNode*> nodes = g.GetNodes();
	for(size_t i = 0; i < nodes.size(); i++){
		DNode cur;
		cur.pri = i;
		cur.node = nodes.at(i);
		cout << "inserting cur.pri: " << cur.pri << "  node: " << cur.node->key << endl;
		q.push(cur);
		//cout << "size: " << q.size() << endl;
	}
	

	//cout << "q before: " << queue_to_string(q) << endl;

	DNode positive;
	positive.node = f;
	positive.pri = 0;
	cout << "q before: " << q.ToString() << endl;
	assert(q.Update(positive) == true);
	cout << "q after: " << q.ToString() << endl;
	assert(q.ToString() == "[(a: 0), (b: 1), (f: 0), (d: 3), (e: 4), (c: 2)]");	
	

	// more tests go here...
	Graph g2 = Graph();
	BetterPriorityQueue q2;

	g2.AddNode('g');
	g2.AddNode('h');
	g2.AddNode('i');
	g2.AddNode('j');
	GraphNode *k = g2.AddNode('k');
	GraphNode *l = g2.AddNode('l');
	vector<GraphNode*> nodes2 = g2.GetNodes();

	for(size_t j = 0; j < nodes2.size(); j++)
	{
		DNode cur;
		cur.pri = j;
		cur.node = nodes2.at(j);
		cout << "inserting cur.pri: " << cur.pri << "  node: " << cur.node->key << endl;
		q2.push(cur);
		//cout << "size: " << q.size() << endl;
	}
	
	DNode positive2;
	positive2.node = k;
	positive2.pri = 0;
	cout << "q2 before: " << q2.ToString() << endl;
	assert(q2.Update(positive2) == true);
	cout << "q2 after: " << q2.ToString() << endl;
	// assert(q.ToString() == "[(a: 0), (b: 1), (f: 0), (d: 3), (e: 4), (c: 2)]");	

	cout << "PASSED!" << endl << endl;
}


int main()
{
	ContainsTest();
	UpdateTest();
	
	cout << "ALL TESTS PASSED!!" << endl;
	
	return 0;
}
