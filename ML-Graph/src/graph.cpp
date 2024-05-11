#include <vector>
#include <stdexcept>

#include "ml-graph.hpp"

ML_NAMESPACE_BEGIN
GRAPH_NAMESPACE_BEGIN

Graph::Graph()
	: nodes(), edges() {}
Graph::Graph(const std::vector<Node>& nodes, const std::vector<Edge>& edges)
	: nodes(nodes), edges(edges) {}

const std::vector<Node>& Graph::getNodes() const {
	return nodes;
}
const std::vector<Edge>& Graph::getEdges() const {
	return edges;
}

Node& Graph::getNode(int index) {
	return nodes[index];
}
Edge& Graph::getEdge(int index) {
	return edges[index];
}

int Graph::getNodeIndex(const Node& node) const {
	for (int i = 0; i < nodes.size(); ++i) {
		if (nodes[i] == node) {
			return i;
		}
	}
	return -1;
}
int Graph::getEdgeIndex(const Edge& edge) const {
	for (int i = 0; i < edges.size(); ++i) {
		if (edges[i] == edge) {
			return i;
		}
	}
	return -1;
}

Edge& Graph::getEdge(const Node& from, const Node& to) {
	for (Edge& edge : edges) {
		if (edge.getSource() == &from && edge.getTarget() == &to) {
			return edge;
		}
	}
	throw std::runtime_error("Edge not found.");
}
Edge& Graph::getEdge(int from, int to) {
	return getEdge(nodes[from], nodes[to]);
};

bool Graph::hasNode(const Node& node) const {
	return getNodeIndex(node) != -1;
}
bool Graph::hasEdge(const Edge& edge) const {
	return getEdgeIndex(edge) != -1;
}

void Graph::addNode(const Node& node) {
	nodes.push_back(node);
}
void Graph::addEdge(const Edge& edge) {
	edges.push_back(edge);
}

void Graph::removeNode(int index) {
	nodes.erase(nodes.begin() + index);
}
void Graph::removeEdge(int index) {
	edges.erase(edges.begin() + index);
}

void Graph::clearNodes() {
	nodes.clear();
}
void Graph::clearEdges() {
	edges.clear();
}

int Graph::getNodeCount() const {
	return nodes.size();
}
int Graph::getEdgeCount() const {
	return edges.size();
}

std::vector<Path> Graph::dfs(int start, int end) {

};
std::vector<Path> Graph::bfs(int start, int end) {

};

GRAPH_NAMESPACE_END
ML_NAMESPACE_END