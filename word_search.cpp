class Solution {
  public:
    //T.C: O(R*C*4^L) and S.C: O(L) where L is length or word 
    bool dfs(vector<vector<char>> &mat, string &word, int i, int j, int index){
        
        if(index==word.size()) return true;
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || mat[i][j] != word[index]) return false;
        char ch = mat[i][j];
        mat[i][j]='#';
        bool op1 = dfs(mat,word,i,j+1,index+1);
        bool op2 = dfs(mat,word,i+1,j,index+1);
        bool op3 = dfs(mat,word,i-1,j,index+1);
        bool op4 = dfs(mat,word,i,j-1,index+1);
        
        mat[i][j]=ch;
        return op1 || op2 || op3 || op4;
        
    }
  
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==word[0] && dfs(mat,word,i,j,0)) return true;
            }
        }
        return false;
    }
};