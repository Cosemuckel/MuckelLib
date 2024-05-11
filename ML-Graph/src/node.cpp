#include <vector>

#include "ml-graph.hpp"

ML_NAMESPACE_BEGIN
GRAPH_NAMESPACE_BEGIN

Node::Node()
	: edges() {}
Node::Node(const std::vector<Edge*>& edges)
	: edges(edges) {}

void Node::addEdge(Edge* edge) {
	edges.push_back(edge);
}
void Node::removeEdge(Edge* edge) {
	edges.erase(std::remove(edges.begin(), edges.end(), edge), edges.end());
}
void Node::removeEdge(size_t index) {
	edges.erase(edges.begin() + index);
}

Edge* Node::getEdge(size_t index) const {
	return edges[index];
}

const std::vector<Edge*>& Node::getEdges() const {
	return edges;
}

bool Node::operator==(const Node& other) const {
	return this == &other;
}
bool Node::operator!=(const Node& other) const {
	return this != &other;
}


GRAPH_NAMESPACE_END
ML_NAMESPACE_END