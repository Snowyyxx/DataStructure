#include<iostream>
#include<vector>
#include<queue>
#include<list>


class Graph{
    int NumberOfVertices;
    std::vector <std::list<int>> AdjList;
    
    public:

    Graph(int NumberOfVertices){
      this->NumberOfVertices= NumberOfVertices;
      AdjList = std::vector <std::list<int>>(NumberOfVertices); 
    }

    void Insert(int i,int j){
        if(i>=0 && i<NumberOfVertices && j>=0 && j<NumberOfVertices){
            AdjList[i].push_back(j);
            AdjList[j].push_back(i);
        }
    }

    void Delete(int i, int j){
        if(i>=0 && i<NumberOfVertices && j>=0 && j<NumberOfVertices){
            AdjList[i].remove(j);
            AdjList[j].remove(i);
    }
    }

    void Display(){
        for(int i=0;i<NumberOfVertices;i++){
            std::cout<<i<<":";
            for(auto j = AdjList[i].begin();j!=AdjList[i].end();++j){
                std::cout<<*j<<",";
            }
            std::cout<<std::endl;
        }
    }

    void BreadthFirstSearch(int start_vertex=0){
        std::vector<bool> Visited(NumberOfVertices,false);
        std::queue<int>Q;

        Q.push(start_vertex);
        Visited[start_vertex]=true;

        while(!Q.empty()){
            int current_index = Q.front();
            Q.pop();
            std::cout<<current_index<<",";
            for(auto i = AdjList[current_index].begin();i!=AdjList[current_index].end();++i){
                if(Visited[*i]==false){
                    Q.push(*i);
                    Visited[*i]=true;
                }
            }
        }

    }


};

int main(){

    Graph g(5);
    g.Insert(1,2);
    g.Insert(2,3);
    g.Insert(1,0);
    g.Insert(4,3);
    //g.Display();
    g.BreadthFirstSearch(2);

}