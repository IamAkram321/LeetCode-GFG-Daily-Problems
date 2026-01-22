class Solution {
    public int subarrayRanges(int[] arr) {
        // code here
        int n = arr.length;
        long maxSum = 0, minSum = 0;

        int[] pge = new int[n];
        int[] nge = new int[n];
        int[] pse = new int[n];
        int[] nse = new int[n];

        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() && arr[st.peek()] <= arr[i]) st.pop();
            pge[i] = st.isEmpty() ? -1 : st.peek();
            st.push(i);
        }

        st.clear();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.isEmpty() && arr[st.peek()] < arr[i]) st.pop();
            nge[i] = st.isEmpty() ? n : st.peek();
            st.push(i);
        }

        st.clear();
        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() && arr[st.peek()] >= arr[i]) st.pop();
            pse[i] = st.isEmpty() ? -1 : st.peek();
            st.push(i);
        }

        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.isEmpty() && arr[st.peek()] > arr[i]) st.pop();
            nse[i] = st.isEmpty() ? n : st.peek();
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            long maxCount = (long)(i - pge[i]) * (nge[i] - i);
            long minCount = (long)(i - pse[i]) * (nse[i] - i);

            maxSum += maxCount * arr[i];
            minSum += minCount * arr[i];
        }

        return (int)(maxSum - minSum);
    }
}
