#ifndef WEIGHTEDGRAPH_HPP
#define WEIGHTEDGRAPH_HPP

#include <vector>
#include <functional>

#include "ml-graph.hpp"

ML_NAMESPACE_BEGIN
GRAPH_NAMESPACE_BEGIN

class WeightedGraph : public Graph {
protected:
	std::vector<WeightedEdge> edges;

public:
	WeightedGraph();
	WeightedGraph(const std::vector<Node>& nodes, const std::vector<WeightedEdge>& edges);

	WeightedEdge& getEdge(int index);
	WeightedEdge& getEdge(int start, int end);

	std::vector<Path> dijkstra(int start, int end);
	std::vector<Path> bellmanFord(int start, int end);
	std::vector<Path> aStar(int start, int end, std::function<double(int, int)> heuristic);
};

GRAPH_NAMESPACE_END
ML_NAMESPACE_END

#endif // !WEIGHTEDGRAPH_HPP
