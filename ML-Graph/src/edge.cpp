#include <vector>

#include "ml-graph.hpp"

ML_NAMESPACE_BEGIN
GRAPH_NAMESPACE_BEGIN

Edge::Edge()
	: source(nullptr), target(nullptr), directed(false), flipped(false) {}
Edge::Edge(Node* source, Node* target)
	: source(source), target(target), directed(false), flipped(false) {}
Edge::Edge(Node* source, Node* target, bool directed)
	: source(source), target(target), directed(directed), flipped(false) {}
Edge::Edge(Node* source, Node* target, bool directed, bool flipped)
	: source(source), target(target), directed(directed), flipped(flipped) {}

Node* Edge::getSource() const {
	return source;
}
Node* Edge::getTarget() const {
	return target;
}
bool Edge::isDirected() const { 
	return directed;
}
bool Edge::isFlipped() const {
	return flipped;
}

void Edge::setSource(Node* source) {
	this->source = source;
}
void Edge::setTarget(Node* target) {
	this->target = target;
}
void Edge::setDirected(bool directed) {
	this->directed = directed;
}
void Edge::setFlipped(bool flipped) {
	this->flipped = flipped;
}

bool Edge::operator==(const Edge& other) const {
	return source == other.source && target == other.target && directed == other.directed && flipped == other.flipped;
}
bool Edge::operator!=(const Edge& other) const {
	return !(*this == other);
}

GRAPH_NAMESPACE_END
ML_NAMESPACE_END
