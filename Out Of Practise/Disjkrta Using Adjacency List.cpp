#include<iostream>
#include<vector>
#include<list>
class Graph{

    int NumVertices;
    std::vector<std::list<int>>AdjList;

    bool CheckLegal(int i, int j){
        if(i>=0 && i<NumVertices && j>=0 && j<NumVertices){
            return true;
        } else{
            return false;
        }
    }

    public:

    Graph(int NumVertices){
        this->NumVertices = NumVertices;
        AdjList = std::vector<std::list<int>>(NumVertices);
    }

    void AddEdge(int i, int j){
        if(CheckLegal(i,j)==true){
            AdjList[i].push_back(j);
            AdjList[j].push_back(i);
        }
    }

    void DeleteEdge(int i, int j){
        if(CheckLegal(i,j)==true){
            AdjList[i].remove(j);
            AdjList[j].remove(i);
        }
    }

    void DisplayAdjacencyList(){
        for(auto i = 0; i<NumVertices; i++){
            std::cout<<i<<":";
            for(auto j =AdjList[i].begin();j!=AdjList[i].end();++j){
                std::cout<<*j<<",";
            }
            std::cout<<std::endl;
        }
    }

};


int main() {
    int numVertices = 5;
    Graph graph(numVertices);

    graph.AddEdge(0, 1);
    graph.AddEdge(0, 4);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(1, 4);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 4);

    std::cout << "Initial Adjacency List:" << std::endl;
    graph.DisplayAdjacencyList();

    graph.DeleteEdge(1, 4);

    std::cout << "After Deleting Edge (1, 4):" << std::endl;
    graph.DisplayAdjacencyList();

    return 0;
}
