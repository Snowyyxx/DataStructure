#include<iostream>
#include<vector>
#include<climits>
#include<stack>
#include<queue>

class Graph{
    std::vector<std::vector<int>>AdjMatrix;
    int NumberOfVertices;

    Graph(int NumberOfVertices){
        this->NumberOfVertices = NumberOfVertices;
        AdjMatrix = std::vector<std::vector<int>>(NumberOfVertices,std::vector<int>(NumberOfVertices,-1));
    }

    void InsertRelation(int x, int y, int weight){
        if(x<NumberOfVertices && x>=0 && y<NumberOfVertices && y>=0){
            AdjMatrix[x][y] = weight;
            AdjMatrix[y][x] = weight;
        }
    }

    void DeleteRelation(int x, int y){
        if(x<NumberOfVertices && x>=0 && y<NumberOfVertices && y>=0){
            AdjMatrix[x][y] = -1;
            AdjMatrix[y][x] = -1;
        }
    }

    
    void Dijkstra(int start_index =0){
        std::vector<int>ShortestDistanceOfAIndexFromStartIndex(NumberOfVertices,INT_MAX);
        std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>>Q; // distance,node

        ShortestDistanceOfAIndexFromStartIndex[start_index]=0;
        Q.push({0,start_index});

        while(!Q.empty()){
            int current_vertex = Q.top().second;
            Q.pop();

        }

    }
  


};

int main(){

}