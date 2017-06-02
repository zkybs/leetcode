#include <iostream>
#include <queue>
using namespace std;
/********************
 [ ]+[ ]-[9]=4
  +   -   -
 [ ]-[ ]*[ ]=4
  /   *   -
 [ ]+[ ]-[ ]=4
  ||  ||  ||
  4   4   4
*********************/
class nineGrid{
public:
    void match(){
        vector<int>q;
        vector<int>grid;
        for(int j=1;j<9;j++){q.push_back(j);}//init
        if(find(q,grid)){
            cout<<"sucess"<<endl;
        }
    }
    bool find(vector<int> q,vector<int> grid){
        int line=grid.size()/3;
        if((!(grid.size()%3)) && line && (!linecalcute(line-1,grid))) return false;
        if(grid.size()==9 && columcalcute(grid)) {
            for(int i=0;i<9;i++){
                // cout<<grid[i]<<" "<<grid[i+1]<< " "<<grid[i+2]<<endl;
                cout<<i<<endl;
                cout<<grid[i]<<" "<<grid[++i]<< " "<<grid[++i]<<endl;
                cout<<i<<endl;
            }
            return true;
        }
        if(grid.size()==2){
            vector<int> ngrid(grid);
            ngrid.push_back(9);
            if(find(q,ngrid))
                return true;
        }else {
            for(int i=0;i<q.size();i++){
                vector<int> ngrid(grid);
                int num=q[i];
                vector<int> nq(q); 
                ngrid.push_back(num);
                nq.erase(nq.begin()+i);
                if(find(nq,ngrid))
                    return true;
            }
        }
        return false;
    }
    bool linecalcute(int l,vector<int> &grid){
        
        switch(l){
            case 0: return (grid[0]+grid[1]-9)==4;
            case 1: return ((grid[3]-grid[4])*grid[5])==4;
            case 2: return (grid[6]+grid[7]-grid[8])==4;
        }
    }
    bool columcalcute(vector<int> &grid){
        return ((grid[0]+grid[3])/grid[6])==4 &&\
                ((grid[1]-grid[4])*grid[7])==4 &&\
                (grid[2]-grid[5]-grid[8])==4;
    }
};

int main(int arg, char *argv[]){
    nineGrid g;
    g.match();
}
