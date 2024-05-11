#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

#include "ml-graph.hpp"

ML_NAMESPACE_BEGIN
GRAPH_NAMESPACE_BEGIN

class Node {
protected:
	std::vector<Edge*> edges;

public:
	Node();
	Node(const std::vector<Edge*>& edges);

	void addEdge(Edge* edge);
	void removeEdge(Edge* edge);
	void removeEdge(size_t index);

	Edge* getEdge(size_t index) const;

	const std::vector<Edge*>& getEdges() const;

	bool operator==(const Node& other) const;
	bool operator!=(const Node& other) const;
};

GRAPH_NAMESPACE_END
ML_NAMESPACE_END

#endif // !NODE_HPP
