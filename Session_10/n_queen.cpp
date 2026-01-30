#include<bits/stdc++.h>
using namespace std;
 
int Safe(int col,int row,vector<string>&board,int n){
    for(int i=0;i<row;i++){
        if(board[row][col]=='Q')
        return false;
    }

    for(int i= row-1,j=col-1;i>=0 && j>=0;i--,j--){
         if(board[row][col]=='Q')
        return false;
    }

    
    for(int i= row-1,j=col+1;i>=0 && j<n;i--,j++){
         if(board[row][col]=='Q')
        return false;
    }
    return true;
}
 void solve(int row,vector<string>& board,vector<vector<string>> & ans,int n){
    if(row==n){ 
    ans.push_back(board);
    return;
    }
 }