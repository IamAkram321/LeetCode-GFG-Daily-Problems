class Solution {
public: //T.C: O(N) and S.C: O(N)
    vector<int> arrayRankTransform(vector<int>& arr) {
        
         
        int n=arr.size();
        vector<int> temp=arr;
        sort(begin(temp),end(temp)); //10,20,30,40
        
        unordered_map<int,int> rank;
        int r=1;
        for(int x : temp){
            if(rank.find(x)==rank.end()){
                rank[x]=r;
                r++;
            }
        }
        vector<int> ans;
        for(int x : arr){
            ans.push_back(rank[x]);
        }
        
        return ans;
    }
};