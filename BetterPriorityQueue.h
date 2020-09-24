
#ifndef BETTERPRIORITYQUEUE_H
#define BETTERPRIORITYQUEUE_H

#include <vector>
#include <queue>
#include "Graph.h"


struct DNode
{
	int pri = INT_MAX;
	bool visited = false;
	const GraphNode *node = nullptr;
	
	bool operator<(const DNode &other) const
	{
		return pri < other.pri;
	}

	bool operator>(const DNode &other) const
	{
		return pri > other.pri;
	}
	
	bool operator==(const DNode &other) const
	{
		return node == other.node;
	}
};


class BetterPriorityQueue: public priority_queue<DNode, vector<DNode>, greater<DNode>>::priority_queue 
{
    public:
		int Contains(DNode n);

        bool Update(DNode n);

        string ToString();

        static string DnodeToString(DNode d);
};


#endif