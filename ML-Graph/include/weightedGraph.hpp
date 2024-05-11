#ifndef WEIGHTEDGRAPH_HPP
#define WEIGHTEDGRAPH_HPP

#include <vector>

#include "ml-graph.hpp"

ML_NAMESPACE_BEGIN
GRAPH_NAMESPACE_BEGIN

class WeightedGraph : public Graph {
protected:
	std::vector<WeightedEdge> edges;

	// Might be overriden for custom weight calculation
	virtual double weightImpl(const WeightedEdge& edge) const;

public:
	WeightedGraph();
	WeightedGraph(const std::vector<Node>& nodes, const std::vector<WeightedEdge>& edges);

	std::vector<Path> dijkstra(int start, int end);
	std::vector<Path> bellmanFord(int start, int end);
};

GRAPH_NAMESPACE_END
ML_NAMESPACE_END

#endif // !WEIGHTEDGRAPH_HPP
