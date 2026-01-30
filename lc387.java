class Solution {
    //T.C: O(n) and S.C: O(1)
    public int firstUniqChar(String s) {
        int[] freq = new int[26];
        for(char ch : s.toCharArray()){
            freq[ch-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(freq[s.charAt(i)-'a'] == 1) return i;
        }
        return -1; 
    }
}