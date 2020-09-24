
#include <vector>
#include <queue>
#include "BetterPriorityQueue.h"

using namespace std;

int BetterPriorityQueue::Contains(DNode n)
{
    int i;
    for (i = 0; i < this->size(); ++i)
    {
        if (this->c.at(i).node == n.node)
            return i;
    }
    return -1;
}


bool BetterPriorityQueue::Update(DNode n)
{
    if (this->Contains(n) != -1)
    {
        vector<DNode> temp;

        for (size_t i = 0; i < this->size(); ++i)
        {
            if (i != this->Contains(n))
                temp.push_back(this->c.at(i));
        }

        temp.push_back(n);
        this->c.clear();
        
        for (size_t j = 0; j < temp.size(); ++j)
            this->push(temp[j]);

        return true;
    }
    return false;
}


string BetterPriorityQueue::ToString()
{
    if (this->empty())
        return "[]";

    string s = "[";
    for (int i = 0; i < this->size(); ++i)
    {
        s = s + DnodeToString(this->c.at(i)) + ", ";
    }
    s = s.substr(0, s.size() - 2);
    s = s + "]";
    return s;
}


string BetterPriorityQueue::DnodeToString(DNode d)
{
    string s = "(";
    s = s + d.node->key;
    s = s + ": " + std::to_string(d.pri);
    s = s + ")";
    return s;
}