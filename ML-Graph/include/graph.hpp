#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <functional>

#include "ml-graph.hpp"

ML_NAMESPACE_BEGIN
GRAPH_NAMESPACE_BEGIN

class Graph {
protected:
	std::vector<Node> nodes;
	std::vector<Edge> edges;

public:
	Graph();
	Graph(const std::vector<Node>& nodes, const std::vector<Edge>& edges);

	const std::vector<Node>& getNodes() const;
	const std::vector<Edge>& getEdges() const;

	Node& getNode(int index);
	Edge& getEdge(int index);
	int getNodeIndex(const Node& node) const;
	int getEdgeIndex(const Edge& edge) const;

	Edge& getEdge(const Node& from, const Node& to);
	Edge& getEdge(int from, int to);

	bool hasNode(const Node& node) const;
	bool hasEdge(const Edge& edge) const;

	void addNode(const Node& node);
	void addEdge(const Edge& edge);

	void removeNode(int index);
	void removeEdge(int index);

	void clearNodes();
	void clearEdges();

	int getNodeCount() const;
	int getEdgeCount() const;

	std::vector<Path> dfs(int start, int end); // Depth First Search, all paths, with the same length
	std::vector<Path> bfs(int start, int end); // Breadth First Search, all paths, with the same length
};

GRAPH_NAMESPACE_END
ML_NAMESPACE_END

#endif // !GRAPH_HPP
