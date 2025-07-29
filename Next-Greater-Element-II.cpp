class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size= 2*nums.size();
        stack<int> s;
        vector<int>ans(nums.size(),-1) ;
        for(int j=0;j<size;j++)
          {      
                   while(!s.empty()&&nums[j%nums.size()]>nums[s.top()]){
                       if(ans[s.top()]==-1)
                          ans[s.top()]=nums[j%nums.size()] ;
                        s.pop() ;
                   }
                   s.push(j%nums.size()) ;
            }   
            return ans ;
 }
};