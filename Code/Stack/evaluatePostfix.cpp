int evaluatePostfix(string S)
{
    stack<int> st;
    for(char ch: S){
        if(isdigit(ch)){
            st.push(ch-'0');
        }else{
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            switch(ch){
                case '*':
                    st.push(a*b);
                break;
                case '/':
                    st.push(a/b);
                break;
                case '+':
                    st.push(a+b);
                break;
                case '-':
                    st.push(a-b);
                break;
            }
        }
    }
    return st.top();
}