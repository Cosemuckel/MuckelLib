#ifndef WEIGHTEDEDGE_HPP
#define WEIGHTEDEDGE_HPP

#include <vector>

#include "ml-graph.hpp"

ML_NAMESPACE_BEGIN
GRAPH_NAMESPACE_BEGIN

class WeightedEdge : public Edge {
protected:
	double weight;

public:
	WeightedEdge();
	WeightedEdge(Node* source, Node* target);
	WeightedEdge(Node* source, Node* target, double weight);
	WeightedEdge(Node* source, Node* target, double weight, bool directed);
	WeightedEdge(Node* source, Node* target, double weight, bool directed, bool flipped);

	double getWeight() const;

	void setWeight(double weight);

	bool operator==(const WeightedEdge& other) const;
};

GRAPH_NAMESPACE_END
ML_NAMESPACE_END

#endif // !WEIGHTEDEDGE_HPP
