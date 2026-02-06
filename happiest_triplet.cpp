class Solution {
  public: //T.C: O(nlogn) and S.C: O(1)
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        
        int i=0,j=0,k=0;
        
        int diff = INT_MAX;
        
        int bestSum = INT_MAX;
        
        int x,y,z;
        
        while(i<a.size() && j<b.size() && k<c.size()){
            
            int low  = min({a[i],b[j],c[k]});
            int high = max({a[i],b[j],c[k]});
            
            int currDiff = high-low;
            int currSum = a[i]+b[j]+c[k];
            
            if(currDiff < diff || (currDiff==diff && currSum < bestSum)){
                diff = currDiff;
                bestSum = currSum;
                x=high;
                y=currSum - (low+high);
                z=low;
            }
            
            if(a[i]==low) i++;
            else if(b[j]==low) j++;
            else k++;
            
        }
        
        return {x,y,z};
        
    }
};