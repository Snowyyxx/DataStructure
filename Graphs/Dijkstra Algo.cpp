#include<iostream>
#include<vector>
#include<set>
#include<climits>

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

    void Dijkstra(int start_vertex){
        std::vector<int>Shortest_Distance_from_start_vertex(NumVertices,INT_MAX);
        std::set<std::pair<int,int>>Set;

        Set.insert({0,start_vertex});
        Shortest_Distance_from_start_vertex[start_vertex]=0; // (distance,vertex)

        while(!Set.empty()){
            int new_vertex = (*Set.begin()).second;
            Set.erase(Set.begin());
            for(auto i =0;i<NumVertices;i++){
                if(AdjMatrix[new_vertex][i]!=0){
                    int potential_shortest_distance;
                    potential_shortest_distance = Shortest_Distance_from_start_vertex[new_vertex]+AdjMatrix[new_vertex][i];
                    if(potential_shortest_distance<Shortest_Distance_from_start_vertex[i]){
                        Set.erase({Shortest_Distance_from_start_vertex[i],i});
                        Shortest_Distance_from_start_vertex[i] = potential_shortest_distance;
                        Set.insert({Shortest_Distance_from_start_vertex[i],i});
                    }
                }
            }


        }

        //printing distances:

        for(auto i =0;i<NumVertices;i++){
            if(Shortest_Distance_from_start_vertex[i]!=INT_MAX){
                std::cout<<"Distance"<<"of vertex "<<i<< " from Vertex "<<start_vertex<<": "<<Shortest_Distance_from_start_vertex[i]<<std::endl;
            }else{
                std::cout<<"Distance of vertex "<<i<<" from "<<start_vertex<<": INT_MAX"<<std::endl;
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
