class Solution {
public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int n = arr.size();
        int mx = *max_element(arr.begin(), arr.end());
        vector<bool> present(mx+1, false);
        for(int x : arr){
            present[x] = true;
        }
        for(int a=1;a<=mx;a++){
            for(int b=a;b<=mx;b++){
                int c2 = a*a + b*b;
                int c = sqrt(c2);
                if(c*c == c2 && c<=mx && present[a] && present[b] && present[c]){
                    return true;
                }
            }
        }
        return false;
    }
};