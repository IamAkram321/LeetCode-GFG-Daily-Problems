class Solution {
public: //T.C: O(l+r) and S.C: O(1)
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int last_moment = 0;

        for(auto l : left)  last_moment = max(last_moment,l);
        for(auto r : right) last_moment = max(last_moment,n-r);

        return last_moment;
    }
};