class Solution {
public: //T.C: O(n) + O(m log m) + O(m) ~ O(nlogn) if n==m let's consider and S.C: O(1)

    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int appleCount = 0;
        for(int a : apple){
            appleCount += a;
        }
        sort(capacity.begin(),capacity.end(),greater<int>());
        int count = 0;
        for(int i=0;i<capacity.size();i++){
                appleCount -= capacity[i];
                count++;
                if(appleCount<=0) break;
        }
        return count;
    }
};