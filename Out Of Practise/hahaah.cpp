#include<iostream>
#include<vector>
#include<set>
#include<climits>
#include<queue>

class Graph{
    
    int NumVertices;
    std::vector<std::vector<int>>AdjMatrix;
    
    public:
    Graph(int NumVertices){
        this->NumVertices =NumVertices;
        AdjMatrix = std::vector<std::vector<int>>(NumVertices,std::vector<int>(NumVertices,0));
    }

    void Insert(int row, int column, int weight){
        if(row>=0&&row<NumVertices&&column>=0&&column<NumVertices){
            AdjMatrix[row][column]=weight;
        }
    }

    void Delete(int row, int column){
        if(row>=0&&row<NumVertices&&column>=0&&column<NumVertices){
            AdjMatrix[row][column]=0;
        }
    }

    void Dijkstra(int start_vertex=0){
    std::vector<int>ShortestDistanceFromStartVertex(NumVertices,INT_MAX);
    ShortestDistanceFromStartVertex[start_vertex]=0;
    std::priority_queue<std::pair<int,int>>Q; // (vertex,distance)

    Q.push({start_vertex,0});

    while(!Q.empty()){
        int current_vertex = Q.top().first;
        Q.pop();

        for(auto i =0; i<NumVertices; i++){
            if(AdjMatrix[current_vertex][i]!=-1){
                int p_distance = AdjMatrix[current_vertex][i] + ShortestDistanceFromStartVertex[current_vertex];
                if(p_distance<ShortestDistanceFromStartVertex[i]){
                    ShortestDistanceFromStartVertex[i] = p_distance;
                    Q.push({i,p_distance});
                }
            }
        }

    }

        for(auto i =0; i<NumVertices;i++){
            
            
            if(ShortestDistanceFromStartVertex[i]==INT_MAX){
                std::cout<<"Uncreachable: "<<i<<",";
                std::cout<<std::endl;
            }   
        }

    }    

};

int main() {
    // Create a graph of 5 vertices
    Graph g(5);

    // Add edges
    g.Insert(0, 1, 10);
    g.Insert(0, 4, 5);
    g.Insert(1, 2, 1);
    g.Insert(1, 4, 2);
    g.Insert(2, 3, 4);
    g.Insert(3, 0, 7);
    g.Insert(3, 2, 6);
    g.Insert(4, 1, 3);
    g.Insert(4, 2, 9);
    g.Insert(4, 3, 2);

    // Run Dijkstra's algorithm from vertex 0
    g.Dijkstra(1);

    return 0;
}
