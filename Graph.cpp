
#include <vector>
#include <string>
#include <iostream>
#include "Graph.h"

using namespace std;


Graph::~Graph()
{
    for (size_t i = 0; i < adjList.size(); ++i)
    {
        delete adjList[i][0]->from;
        for (size_t j = 0; j < adjList[i].size(); ++j)
            delete adjList[i][j];
    }
}


GraphNode *Graph::AddNode(char key, int data)
{
    size = size + 1;
    adjList.resize(size);

    GraphNode *nodeptr = new GraphNode;
    nodeptr->key = key;
    nodeptr->data = data;

    Graph::AddEdge(nodeptr, nullptr, 0);
    return nodeptr;
}


GraphEdge *Graph::AddEdge(GraphNode *gn1, GraphNode *gn2, unsigned int weight)
{
    GraphEdge *edgeptr = new GraphEdge;
    edgeptr->from = gn1;
    edgeptr->to = gn2;
    edgeptr->weight = weight;

    for (size_t i = 0; i < adjList.size(); ++i)
    {
        if (adjList[i].empty())
            adjList[i].push_back(edgeptr);
        else if (adjList[i][0]->from == gn1)
            adjList[i].push_back(edgeptr);
    }
    
    return edgeptr;
}
		

string Graph::NodesToString() const
{
    string s = "[";
    for (int i = 0; i < adjList.size(); ++i)
    {
        if (!adjList[i].empty())
            s = s + Graph::GraphNodeToString(adjList[i][0]->from) + ", ";
    }
    s = s.substr(0, s.length() - 2);
    s = s + "]";
    return s;
}


string Graph::ToString() const
{
    string s = "";
    for (size_t i = 0; i < adjList.size(); ++i)
    {
        if (!adjList[i].empty())
        {
            s = s + adjList[i][0]->from->key;
            s = s + " | ";
            for (size_t j = 0; j < adjList[i].size(); ++j)
            {
                if (adjList[i][j]->to != nullptr)
                    s = s + GraphEdgeToString(adjList[i][j]) + ", ";
            }
            if (adjList[i].size() > 1)
                s = s.substr(0, s.length() - 2);
            s = s + "\n";
        }
        
    }
    return s;
}


string Graph::GraphNodeToString(const GraphNode *gn)
{
    if (gn == nullptr)
        return "()";
    string s = "(";
    s = s + gn->key;
    s = s + ":" + std::to_string(gn->data) + ")";
    return s;
}


string Graph::GraphEdgeToString(const GraphEdge *ge)
{
    string s = "[";
    s = s + GraphNodeToString(ge->from) + "->" + GraphNodeToString(ge->to);
    s = s + " w:" + to_string(ge->weight) + "]";
    return s;
}
		
		
const vector<GraphEdge*>& Graph::GetEdges(const GraphNode *gn) const
{
    static vector<GraphEdge*> edges;
    edges.clear();
    for (size_t i = 0; i < adjList.size(); ++i)
    {
        if (adjList[i][0]->from == gn)
            edges = adjList[i];
    }
    edges.erase(edges.begin());
    return edges;
}


const vector<GraphNode*>& Graph::GetNodes() const
{
    static vector<GraphNode*> nodes;
    nodes.clear();
    for (size_t i = 0; i < adjList.size(); ++i)
    {
        if (!adjList[i].empty())
            nodes.push_back(adjList[i][0]->from);
    }
    return nodes;
}


const GraphNode* Graph::NodeAt(unsigned int idx) const
{
    if (!adjList[idx].empty())
        return adjList[idx][0]->from;
    return nullptr;
}


size_t Graph::Size() const
{
    return size;
}