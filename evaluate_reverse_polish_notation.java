class Solution { //T.C: O(n) and S.C: O(n)
    public int evalRPN(String[] tokens) {
        Stack<Integer> st = new Stack<>();

        for (String curr : tokens) {
            if (curr.equals("+") || curr.equals("-") || curr.equals("*") || curr.equals("/")) {
                int b = st.pop();
                int a = st.pop();

                if (curr.equals("+")) st.push(a + b);
                else if (curr.equals("-")) st.push(a - b);
                else if (curr.equals("*")) st.push(a * b);
                else st.push(a / b);
            } else {
                st.push(Integer.parseInt(curr));
            }
        }
        return st.pop();
    }
}
