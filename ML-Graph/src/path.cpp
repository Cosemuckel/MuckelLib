#include <vector>

#include "ml-graph.hpp"

ML_NAMESPACE_BEGIN
GRAPH_NAMESPACE_BEGIN

Path::Path()
	: edges(), source(nullptr), target(nullptr) {}
Path::Path(const std::vector<Edge*>& edges)
	: edges(edges), source(edges.front()->getSource()), target(edges.back()->getTarget()) {}

void Path::addEdge(Edge* edge) {
	edges.push_back(edge);
	target = edge->getTarget();
}
void Path::addEdges(const std::vector<Edge*>& edges) {
	this->edges.insert(this->edges.end(), edges.begin(), edges.end());
	target = edges.back()->getTarget();
}

const std::vector<Edge*>& Path::getEdges() const {
	return edges;
}
Node* Path::getSource() const {
	return source;
}
Node* Path::getTarget() const {
	return target;
}

void Path::popFront() {
	edges.erase(edges.begin());
	source = edges.empty() ? nullptr : edges.front()->getSource();
}
void Path::popBack() {
	edges.pop_back();
	target = edges.empty() ? nullptr : edges.back()->getTarget();
}

GRAPH_NAMESPACE_END
ML_NAMESPACE_END