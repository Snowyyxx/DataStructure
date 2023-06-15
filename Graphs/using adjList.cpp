#include<iostream>
#include<vector>
#include<list>

class Graph{
    int NumberOfVertices;
    std::vector<std::list<int>>AdjList;

    public:
    Graph(int NumberOfVertices){
        this->NumberOfVertices = NumberOfVertices;
        AdjList = std::vector<std::list<int>>(NumberOfVertices);
    }

    void AddEdge(int source, int destination){
        if(source<NumberOfVertices && source>=0 && destination<NumberOfVertices && destination>=0){
            AdjList[source].push_back(destination);
            AdjList[destination].push_back(source);
        }
    }

    void PrintGraph(){
        for(int i=0;i<NumberOfVertices;i++){
            std::cout<<i<<":";
            for(auto j = AdjList[i].begin();j!=AdjList[i].end();++j){
                std::cout<<*j<<",";
            }
            std::cout<<std::endl;
        }
    }

    void DeleteEdge(int src, int dest){
        if(src<NumberOfVertices && src>=0 && dest<NumberOfVertices && dest>=0){
            AdjList[src].remove(dest);
            AdjList[dest].remove(src);
        }
    }


};



int main(){
    Graph g(5);
    g.AddEdge(0,1);
    g.AddEdge(1,2);
    g.AddEdge(2,3);
    g.AddEdge(2,4);
    g.PrintGraph();
    g.DeleteEdge(1,2);
    std::cout<<"After Deletion"<<std::endl;
    g.PrintGraph();

}