#include <vector>

#include "ml-graph.hpp"

ML_NAMESPACE_BEGIN
GRAPH_NAMESPACE_BEGIN

WeightedGraph::WeightedGraph()
	: Graph() {}
WeightedGraph::WeightedGraph(const std::vector<Node>& nodes, const std::vector<WeightedEdge>& edges)
	: Graph(nodes, std::vector<Edge>(edges.begin(), edges.end())) {}

double WeightedGraph::weightImpl(const WeightedEdge& edge) const {
	return edge.getWeight();
};

std::vector<Path> WeightedGraph::dijkstra(int start, int end) {
	
}
std::vector<Path> WeightedGraph::bellmanFord(int start, int end) {
	
}

GRAPH_NAMESPACE_END
ML_NAMESPACE_END