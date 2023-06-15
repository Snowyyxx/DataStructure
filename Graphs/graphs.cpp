#include<iostream>
#include<vector>

class Graph {
private:
    int NumberOfVertices;
    std::vector<std::vector<int>> AdjacencyMatrix;

public:
    // Constructor
    Graph(int NumberOfVertices) {
        this->NumberOfVertices = NumberOfVertices;
        AdjacencyMatrix = std::vector<std::vector<int>>(NumberOfVertices, std::vector<int>(NumberOfVertices, 0));
    }

    // Function to insert an edge into the graph
    void addEdge(int i, int j) {
        if(i >= 0 && i < NumberOfVertices && j >= 0 && j < NumberOfVertices) {
            AdjacencyMatrix[i][j] = 1;
            AdjacencyMatrix[j][i] = 1;  // This line should be removed if your graph is directed
        }
    }

    // Function to remove an edge from the graph
    void removeEdge(int i, int j) {
        if(i >= 0 && i < NumberOfVertices && j >= 0 && j < NumberOfVertices) {
            AdjacencyMatrix[i][j] = 0;
            AdjacencyMatrix[j][i] = 0;  // This line should be removed if your graph is directed
        }
    }

    // Function to print the graph
    void printGraph() {
        for(int i = 0; i < NumberOfVertices; i++) {
            std::cout << i << " : ";
            for(int j = 0; j < NumberOfVertices; j++) {
                std::cout << AdjacencyMatrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    Graph g(5);  // Creating a graph with 5 vertices

    g.addEdge(0, 1); 
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph(); // Print the adjacency matrix

    return 0;
}
s