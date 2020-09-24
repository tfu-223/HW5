
#include <iostream>
#include <cassert>
#include "Graph.h"

using namespace std;


void TestAddNode(){
	cout << "Testing AddNode..." << endl;
	Graph g = Graph();
	g.AddNode('a', 15);
	
	// cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << g.ToString() << endl;
	
	assert(g.NodesToString() == "[(a:15)]");
	assert(g.ToString() == "a | \n");
	
	g.AddNode('b', 12);
	//cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << endl << g.ToString() << endl;

	assert(g.NodesToString() == "[(a:15), (b:12)]");
	assert(g.ToString() == "a | \nb | \n");
	
	// more tests....
	
	cout << "PASSED!" << endl << endl;
}


void TestAddEdge(){
	cout << "Testing AddEdge..." << endl;
	Graph g = Graph();
	GraphNode *gn1 = g.AddNode('a', 15);
	
	//cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << g.ToString() << endl;
	
	assert(g.NodesToString() == "[(a:15)]");
	assert(g.ToString() == "a | \n");
	
	GraphNode *gn2 = g.AddNode('b', 12);
	//cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << endl << g.ToString() << endl;

	assert(g.NodesToString() == "[(a:15), (b:12)]");
	assert(g.ToString() == "a | \nb | \n");
	
	GraphNode *gn3 = g.AddNode('c', 9);
	assert(g.NodesToString() == "[(a:15), (b:12), (c:9)]");
	assert(g.ToString() == "a | \nb | \nc | \n");
	
	g.AddEdge(gn1, gn3, 2);
	//cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << endl << g.ToString() << endl;
	assert(g.NodesToString() == "[(a:15), (b:12), (c:9)]");
	assert(g.ToString() == "a | [(a:15)->(c:9) w:2]\nb | \nc | \n");
	
	g.AddEdge(gn3, gn2);
	g.AddEdge(gn1, gn2, 8);
	//cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << endl << g.ToString() << endl;
	
	assert(g.NodesToString() == "[(a:15), (b:12), (c:9)]");
	assert(g.ToString() == "a | [(a:15)->(c:9) w:2], [(a:15)->(b:12) w:8]\nb | \nc | [(c:9)->(b:12) w:0]\n");
	
	cout << "PASSED!" << endl << endl;
}


void TestDestructor(){
	cout << "Testing Destructor..." << endl;
	Graph *g = new Graph();
	
	GraphNode *a = g->AddNode('a', 3);
	GraphNode *b = g->AddNode('b', 5);
	g->AddEdge(b, a, 15);
	cout << "Graph: " << endl;
	cout << g->ToString() << endl;
	
	delete g;
	
	Graph g2 = Graph();
	GraphNode *c = g2.AddNode('c', 12);
	g2.AddNode('d', 11);
	assert(c->key == 'c' && c->data == 12);
	
	cout << "NO ERRORS.  Use valgrind to check!" << endl << endl;
}


// more test functions...
void TestGetEdges()
{
	cout << "Testing GetEdges..." << endl;
	Graph g = Graph();
	GraphNode *a = g.AddNode('a');
	GraphNode *b = g.AddNode('b');
	GraphNode *c = g.AddNode('c');
	g.AddEdge(a, b, 1);
	g.AddEdge(a, c, 2);

	assert(g.GraphEdgeToString(g.GetEdges(a)[0]) == "[(a:0)->(b:0) w:1]");
	assert(g.GraphEdgeToString(g.GetEdges(a)[1]) == "[(a:0)->(c:0) w:2]");

	cout << "PASSED!" << endl << endl;
}


void TestGetNodes()
{
	cout << "Testing GetNodes..." << endl;
	Graph g = Graph();
	GraphNode *a = g.AddNode('a');
	GraphNode *b = g.AddNode('b');
	GraphNode *c = g.AddNode('c');
	assert(g.GraphNodeToString(g.GetNodes()[0]) == "(a:0)");
	assert(g.GraphNodeToString(g.GetNodes()[1]) == "(b:0)");
	assert(g.GraphNodeToString(g.GetNodes()[2]) == "(c:0)");
	cout << "PASSED!" << endl << endl;
}


void TestNodeAt()
{
	cout << "Testing NodeAt..." << endl;
	Graph g = Graph();
	GraphNode *a = g.AddNode('a');
	GraphNode *b = g.AddNode('b');
	GraphNode *c = g.AddNode('c');
	assert(g.NodeAt(0) == a);
	assert(g.NodeAt(1) == b);
	assert(g.NodeAt(2) == c);
	cout << "PASSED!" << endl << endl;
}


int main(){
	
	Graph g = Graph();
	GraphNode *gn1 = g.AddNode('a', 15);
	GraphNode *gn2 = g.AddNode('b', 12);
	GraphNode *gn3 = g.AddNode('c', 9);
	GraphNode *gn4 = g.AddNode('m', 9);
	g.AddEdge(gn1, gn3, 2);
	cout << "nodes: "  << g.NodesToString() << endl;
	cout << "ToString: " << endl;
	cout << g.ToString() << endl;
	cout << "size: " << g.Size() << endl;
	cout << "node at: " << g.GraphNodeToString(g.NodeAt(2)) << endl;

	TestAddNode();
	TestAddEdge();
	TestDestructor();

	// ... more tests ... 
	TestGetEdges();
	TestGetNodes();
	TestNodeAt();

	cout << "ALL TESTS PASSED!" << endl;
	return 0;
}
