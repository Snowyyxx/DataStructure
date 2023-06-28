#include<iostream>
#include<queue>
#include<vector>

class Graph{
    
    std::vector<std::vector<int>>AdjMatrix;
    int NumVertices;

    public:

    Graph(int NumVertices){
        this->NumVertices = NumVertices;
        AdjMatrix = std::vector<std::vector<int>>(NumVertices,std::vector<int>(NumVertices,-1));
    }

    void Dijskra(){

        




    }

    void BFS(int start_index=0){

        std::queue<int>Q;
        std::vector<bool>Visited(NumVertices,false);

        Visited[start_index]=true;
        Q.push(start_index);

        while(!Q.empty()){

            int current_index = Q.front();
            Q.pop();

            for(auto i =0;i<NumVertices;i++){
                if(AdjMatrix[current_index][i]!=-1 && Visited[i]==false){
                    Q.push(i);
                    Visited[i]=true;
                    std::cout<<i<<",";
                }
            }

        }



    }

    void addEdge(int x,int y){
        if(x>=0&&x<NumVertices&&y>=0&&y<NumVertices){
            AdjMatrix[x][y]=1;
            AdjMatrix[y][x]=1;
        }
    }

};

int main() {
    // Create a graph with 6 vertices
    Graph graph(6);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    
    // Perform BFS starting from vertex 0
    std::cout << "BFS Traversal starting from vertex 0: ";
    graph.BFS(0);

    return 0;
}
