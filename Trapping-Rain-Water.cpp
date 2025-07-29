class Solution {
public:
    int trap(vector<int>& height) {
         int n=height.size() ;

           vector<int>arr(n) ;
           arr[0]=0;
           arr[n-1]=0;
           int maxi=INT_MIN ;
           for(int i=n-2;i>=1;i--){
                maxi=max(height[i+1],maxi);
                arr[i]=maxi;
           }

          int ans=0;
          int low=INT_MIN;

          for(int j=1;j<=n-2;j++){
            low=max(low,height[j-1]);
            int x= min(low,arr[j])-height[j] ;
            if(x>=0)
               ans+=x;
          }


      return ans;
    }
};