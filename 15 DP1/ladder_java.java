import java.util.*;

class ladder{
	public static void main(String args[]){
		int n=4, k=3;
		int cache[] = new int [n+1];
		Arrays.fill(cache, -1);

		System.out.println( climb_dp(n,k));
	}
	public static int climb_dp(int n, int k){
		int dp[] = new int [n+1];
		Arrays.fill(dp,0);
		dp[0]=1;
		dp[1]=1;
		for(int i=2;i<=n;i++){
			if(i-k-1<0){
				for(int j=i-1;j>=0 && j>=i-k;j--){
					dp[i] += dp[j];

				}
			} else{
				dp[i] = 2*dp[i-1] - dp[i-k-1];
			}
			
			
		}
		return dp[n];
	}
	public static int climb(int n, int k, int[] cache){
		if(n<0) return 0;
		if(n==0 || n==1){
			return 1;
		}
		if(cache[n]!=-1) return cache[n];
		int ans=0;
		for(int i=1;i<=k;i++){
			ans+=climb(n-i,k, cache);
		}
		return cache[n] = ans;
	}
}