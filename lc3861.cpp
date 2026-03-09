class Solution {
public: //T.C: O(n) and S.C: O(1)
    int minimumIndex(vector<int>& capacity, int itemSize) {

        int minCapacity = INT_MAX;
        int minIndex = -1;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i]>=itemSize && capacity[i]<minCapacity){
                minCapacity = capacity[i];
                minIndex = i;
            }
        }
       return minIndex;
    }
};