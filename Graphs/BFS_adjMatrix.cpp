#include<iostream>
#include<vector>
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

    void BFS(int start_index=0){
        std::vector<bool>Visited(NumberVertices,false);
        std::queue<int>Q;

        Visited[start_index]=true;
        Q.push(start_index);

        while(!Q.empty()){
            int current_value = Q.front();
            Q.pop();
            std::cout<<current_value<<",";

            for(int j =0;j<NumberVertices;j++){
                if(AdjMatrix[current_value][j]==1&&!Visited[j]){                
                    Q.push(j);
                    Visited[j]=true;
                }
            }

        }


    }


};


int main(){

    Graph g(5);
    g.Insert(1,2);
    g.Insert(2,3);
    g.Insert(0,1);
    g.Insert(1,4);
    //g.Display();
    g.BFS();
}