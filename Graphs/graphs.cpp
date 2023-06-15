/* Created using adjanecy list and adjancy matrix!

For Example:
this is the graph-
  0---1
  |  /|
  | / |
  2---3


this is the adjanecy matrix (1 -> there is a connection bw the nodes and 0 means there is no connection)
    0 1 2 3
  ----------
0 | 0 1 1 0
1 | 1 0 1 1
2 | 1 1 0 1
3 | 0 1 1 0

*/

#include<iostream>
#include<vector>

class Graph{
    int NumberOfVertices;
    std::vector <std::vector<int>> AdjacencyMatrix; // Every element of the Adjanecy Matrix is a vector! ===> 2D Matrix!
    public:

    Graph(int NumberOfVertices){
        this->NumberOfVertices = NumberOfVertices;
        std::vector<std::vector<int>> NewMatrix (NumberOfVertices,std::vector<int>(NumberOfVertices,0));
        AdjacencyMatrix =NewMatrix;
    }

    // Function to insert an edge into the graph
    void AddEdge(int i, int j){
        if(i>=0 && i <NumberOfVertices && j>=0 && j<NumberOfVertices){
            AdjacencyMatrix[i][j]=1;
            AdjacencyMatrix[j][i]=1;
        }
    }

    void RemoveEdge(int i,int j ){
        if(i>=0 && i <NumberOfVertices && j>=0 && j<NumberOfVertices){
            AdjacencyMatrix[i][j]=0;
            AdjacencyMatrix[j][i]=0;
        }
    }

    void Print_Graph(){
        std::cout<<"   ";
        for(int k=0;k<NumberOfVertices;k++){
            std::cout<<k<<" ";
        }
        std::cout<<std::endl;
        for(int i=0;i<NumberOfVertices;i++){
            std::cout<<i<<": ";
            for(int j=0;j<NumberOfVertices;j++){
                std::cout<<AdjacencyMatrix[i][j]<<" ";    
            }
            std::cout<<std::endl;
        }
    }



};
int main(){
    Graph graph(5);
    graph.AddEdge(1,2);
    graph.AddEdge(0,0);
    graph.AddEdge(4,3);
    graph.Print_Graph();


}