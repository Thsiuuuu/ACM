#include <iostream>
#include <vector>
using namespace std;

const int N=8;
vector<string> board(N,string(N,'.'));
vector<bool> colUsed(N,false);
vector<bool> diag1Used(2*N-1,false);
vector<bool> diag2Used(2*N-1,false);

bool backtrack(int row){
    if(row==N) return true;
    
    // 检查当前行是否已有皇后
    for(int col=0;col<N;col++){
        if(board[row][col]=='Q')
            return backtrack(row+1);
    }
    
    // 当前行没有皇后，尝试放置
    for(int col=0;col<N;col++){
        if(!colUsed[col] && !diag1Used[row-col+N-1] && !diag2Used[row+col]){
            board[row][col]='Q';
            colUsed[col]=true;
            diag1Used[row-col+N-1]=true;
            diag2Used[row+col]=true;
            
            if(backtrack(row+1)) return true;
            
            board[row][col]='.';
            colUsed[col]=false;
            diag1Used[row-col+N-1]=false;
            diag2Used[row+col]=false;
        }
    }
    return false;
}

int main(){
    int k;
    cin>>k;
    
    for(int i=0;i<k;i++){
        int r,c;
        cin>>r>>c;
        board[r][c]='Q';
        colUsed[c]=true;
        diag1Used[r-c+N-1]=true;
        diag2Used[r+c]=true;
    }
    
    backtrack(0);
    
    for(const string& row:board)
        cout<<row<<endl;
    return 0;
}
