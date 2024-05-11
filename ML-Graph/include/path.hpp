#ifndef PATH_HPP
#define PATH_HPP

#include <vector>

#include "ml-graph.hpp"

ML_NAMESPACE_BEGIN
GRAPH_NAMESPACE_BEGIN

class Path {
protected:
	std::vector<Edge*> edges;
	Node* source, *target; // Same as edges.front()->getSource() and edges.back()->getTarget() respectively

public:
	Path();
	Path(const std::vector<Edge*>& edges);

	void addEdge(Edge* edge);
	void addEdges(const std::vector<Edge*>& edges);

	const std::vector<Edge*>& getEdges() const;
	Node* getSource() const;
	Node* getTarget() const;

	void popFront();
	void popBack();
};

GRAPH_NAMESPACE_END
ML_NAMESPACE_END

#endif // !PATH_HPP
