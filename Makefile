all:
	g++ -Wall -std=c++11 -g Graph.cpp GraphTests.cpp -o graph-tests
	g++ -Wall -std=c++11 -g Graph.cpp BetterPriorityQueue.cpp BPQTests.cpp -o bpq-tests