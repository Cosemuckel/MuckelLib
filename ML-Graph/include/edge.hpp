#ifndef EDGE_HPP
#define EDGE_HPP

#include <vector>

#include "ml-graph.hpp"

ML_NAMESPACE_BEGIN
GRAPH_NAMESPACE_BEGIN

class Edge {
protected:
	Node* source, *target;
	bool directed;
	bool flipped; // used for undirected graphs to indicate that the edge is flipped (source and target are swapped)

public:
	Edge();
	Edge(Node* source, Node* target);
	Edge(Node* source, Node* target, bool directed);
	Edge(Node* source, Node* target, bool directed, bool flipped);

	Node* getSource() const;
	Node* getTarget() const;
	bool isDirected() const;
	bool isFlipped() const;

	void setSource(Node* source);
	void setTarget(Node* target);
	void setDirected(bool directed);
	void setFlipped(bool flipped);

	bool operator==(const Edge& other) const;
	bool operator!=(const Edge& other) const;
};

GRAPH_NAMESPACE_END
ML_NAMESPACE_END

#endif // !EDGE_HPP
