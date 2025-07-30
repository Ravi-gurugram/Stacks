class Solution {
public:
int find(string ch, int a, int b){
    if(ch=="+")
        return b+a ;
    else if(ch=="-")
        return b-a ;
     else if(ch=="*")
        return b*a ; 
    else
       return b/a ;
}
bool special(string ch){
      
    return ch=="+"||ch=="-"||ch=="*"||ch=="/" ;
}
    int evalRPN(vector<string>& tokens) {
        stack<int>st ;
        for(int i=0;i<tokens.size();i++){
            
            if(special(tokens[i])){
                int a=st.top();st.pop();
                int b =st.top();st.pop();
                int result= find(tokens[i],a,b) ;
                st.push(result ) ;
            }
            else{
                st.push(stoi(tokens[i])) ;
            }

        }
        return st.top() ;
    }
};