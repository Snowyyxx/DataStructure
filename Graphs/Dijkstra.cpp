#include<iostream>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
class Graph{

    std::vector<std::vector<int>>AdjMatrix;
    int NumVertices;
    public:

    Graph(int NumVertices){
        this->NumVertices = NumVertices;
        AdjMatrix = std::vector<std::vector<int>>(NumVertices,std::vector<int>(NumVertices,-1));
    }

    void InsertRelation(int x, int y, int weight){
        if(x>=0 && x<NumVertices && y>=0 && y<NumVertices){
            AdjMatrix[x][y] = weight;
            AdjMatrix[y][x] = weight; 
        }
    }

    void DeleteRelation(int x, int y){
        if(x>=0 && x<NumVertices && y>=0 && y<NumVertices){
            AdjMatrix[x][y] = -1;
            AdjMatrix[y][x] = -1; 
        }
    }

    void Dijkstra(int start_index=0){
        std::vector<int>ShortestDistanceFromStartIndex(NumVertices,INT_MAX);
        std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>>Q; // distance,node

        Q.push({0,start_index});
        ShortestDistanceFromStartIndex[start_index]=0;

        while(!Q.empty()){

            int current_index = Q.top().second;
            Q.pop();

            for(auto i = 0;i<NumVertices;i++){
                if(AdjMatrix[current_index][i]!=-1){
                    int potential_distance = ShortestDistanceFromStartIndex[current_index]+AdjMatrix[current_index][i];
                    if(potential_distance<ShortestDistanceFromStartIndex[i]){
                        ShortestDistanceFromStartIndex[i]=potential_distance;
                        Q.push({potential_distance,i});
                    }
                }
            }

        }

        for(auto j =0;j<NumVertices;j++){
            if(ShortestDistanceFromStartIndex[j]!=INT_MAX){
                std::cout<<"Minimum distace of "<<j<<" from "<<start_index<< " is:"<<ShortestDistanceFromStartIndex[j]<<std::endl ;
        }
        
        }

    }

};

int main() {
    // Create a Graph with 5 vertices
    Graph g(5);

    // Insert some relations in the graph (Format: Vertex1, Vertex2, Weight)
    g.InsertRelation(0, 1, 1);
    g.InsertRelation(0, 2, 3);
    g.InsertRelation(1, 2, 1);
    g.InsertRelation(1, 3, 7);
    g.InsertRelation(2, 4, 2);
    g.InsertRelation(4, 3, 2);

    // Run Dijkstra algorithm starting from vertex 0
    g.Dijkstra(0);

    return 0;
}
