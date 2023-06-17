#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<queue>

class Graph{
    int NumVertices;
    std::vector<std::list<int>>Adjlist;

    public:
    Graph(int NumVertices){
        this->NumVertices = NumVertices;
        Adjlist = std::vector<std::list<int>>(NumVertices);
    }

    void Insert(int i,int j){
        if(i>=0 && i <NumVertices && j>=0 && j<NumVertices){
            Adjlist[i].push_back(j);
            Adjlist[j].push_back(i);
        }
    }

    void Delete(int i,int j ){
        if(i>=0 && i <NumVertices && j>=0 && j<NumVertices){
            Adjlist[i].remove(j);
            Adjlist[j].remove(i);
        }
    }

    void BFS(int start_index=0){
        std::vector<bool>Visited(NumVertices,false);
        std::queue<int>Q;

        Q.push(start_index);
        while(!Q.empty()){
            int vertex = Q.front();
            Q.pop();
            
            if(!Visited[vertex]){
                Visited[vertex]=true;   
                std::cout<<vertex<<",";

                for(auto i =Adjlist[vertex].begin();i!=Adjlist[vertex].end();++i){
                    Q.push(*i);
                }



            }


        }

    }

    void DFS(int start_index =0){

        std::vector<bool>visited(NumVertices,0);
        std::stack<int>stack;

        stack.push(start_index);

        while(!stack.empty()){

            int vertex = stack.top();
            stack.pop();

            if(!visited[vertex]){
                std::cout<<vertex<<",";
                visited[vertex]=true;

                for(auto i = Adjlist[vertex].begin();i!=Adjlist[vertex].end();++i){
                    stack.push(*i);
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
    g.Insert(0,4);
    g.BFS();
    std::cout<<std::endl;
    g.DFS();


}