class Solution {
public:
    int maxDepth(string s) {
        stack<char>st ;
        int maxi=INT_MIN ;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') {
               st.push(s[i]) ; int curr= st.size() ;
                 maxi= max(curr,maxi) ;}
            else if(s[i]==')'){
                if(st.empty())
                    continue ;
                else
                   st.pop(); 
            }
            else
               continue ;
        
        }
    if(maxi==INT_MIN)
        return 0 ;
    else 
        return maxi ;
    }
};