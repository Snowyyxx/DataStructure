#include<iostream>
#include<vector>
#include<stack>
#include<queue>
class Graph{
    std::vector<std::vector<int>>AdjMatrix;
    int NumberVertices;

    public:

    Graph(int NumberVertices){
        this->NumberVertices =NumberVertices;
        AdjMatrix = std::vector<std::vector<int>>(NumberVertices,std::vector<int>(NumberVertices,0));
    }

    void Insert(int x,int y){
        if(x>=0 && x<NumberVertices && y>=0 && y<NumberVertices){
            AdjMatrix[x][y]=1;
            AdjMatrix[y][x]=1;
        }
    }

    void Delete(int x,int y){
        if(x>=0 && x<NumberVertices && y>=0 && y<NumberVertices){
            AdjMatrix[x][y]=0;
            AdjMatrix[y][x]=0;        
        }

    }
    
    void Display() {
    // Print top line
    std::cout << "  ";
    for (int j = 0; j < NumberVertices; j++) {
        std::cout << "+---";
    }
    std::cout << "+\n";

    // Print rows with row headers
    for (int i = 0; i < NumberVertices; i++) {
        std::cout << i << " ";
        for (int j = 0; j < NumberVertices; j++) {
            std::cout << "| " << AdjMatrix[i][j] << " ";
        }
        std::cout << "|\n";

        // Print separator line
        std::cout << "  ";
        for (int j = 0; j < NumberVertices; j++) {
            std::cout << "+---";
        }
        std::cout << "+\n";
    }
}

void Visit(std::vector<bool>&visited,int i){
    visited[i]=true;
}

void DepthFirstSearch(int start_index = 0){

    std::vector<bool>visited(NumberVertices,false);
    std::stack<int>stack;

    stack.push(start_index);

    while(!stack.empty()){
        int vertex =stack.top();
        stack.pop();
        if(!visited[vertex]){
            std::cout<<vertex<<",";
            Visit(visited,vertex);
            for(auto i = 0;i<NumberVertices;i++){
                if(AdjMatrix[vertex][i]==1&&!visited[i]){
                    stack.push(i);
                }
            }
        }

    }


}


void BreadthFirstSearch(int start_index=0){
    std::vector<bool>visited(NumberVertices,false);
    std::queue<int>Q;

    Q.push(start_index);
    Visit(visited,start_index);

    while(!Q.empty()){
        int vertex = Q.front();
        Q.pop();

        std::cout<<vertex<<",";
        for(auto i =0;i<NumberVertices;i++){
            if(AdjMatrix[vertex][i]==1&&!visited[i]){
                Q.push(i);
                Visit(visited,i);
            
            }
        }

    }

}

};

int main() {
    Graph g(4);
    g.Insert(0, 1);
    g.Insert(0, 2);
    g.Insert(1, 2);
    g.Insert(2, 0);
    g.Insert(2, 3);
    g.Insert(3, 3);
    
    std::cout << "Adjacency Matrix: \n";
    g.Display();
    
    std::cout << "Depth First Traversal (starting from vertex 2): \n";
    g.DepthFirstSearch(2);
    std::cout<<std::endl;
    g.BreadthFirstSearch(2);
    return 0;
}