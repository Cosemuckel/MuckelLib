#include <vector>

#include "ml-graph.hpp"

ML_NAMESPACE_BEGIN
GRAPH_NAMESPACE_BEGIN

WeightedEdge::WeightedEdge()
	: Edge(), weight(1.0) {}
WeightedEdge::WeightedEdge(Node* source, Node* target)
	: Edge(source, target), weight(1.0) {}
WeightedEdge::WeightedEdge(Node* source, Node* target, double weight)
	: Edge(source, target), weight(weight) {}
WeightedEdge::WeightedEdge(Node* source, Node* target, double weight, bool directed)
	: Edge(source, target, directed), weight(weight) {}
WeightedEdge::WeightedEdge(Node* source, Node* target, double weight, bool directed, bool flipped)
	: Edge(source, target, directed, flipped), weight(weight) {}

double WeightedEdge::getWeight() const {
	return weight;
}
void WeightedEdge::setWeight(double weight) {
	this->weight = weight;
}

bool WeightedEdge::operator==(const WeightedEdge& other) const {
	return Edge::operator==(other) && weight == other.weight;
}


GRAPH_NAMESPACE_END
ML_NAMESPACE_END