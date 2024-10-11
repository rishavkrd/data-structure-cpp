import java.util.*;
class coinchange{
	public static void main(String args[]){
		int coins[] = {1,3,7,10};
		int prices[] = {1,5,8,9,10,17,17,20};
		int arr[] = {6,10,12,7,9,14};
		// Scanner inp = new Scanner(System.in);
		// int target = inp.nextInt();
		int target = 15;
		// System.out.println(min_coins(coins, target));
		// System.out.println(cutting_rod(prices));
		System.out.println(non_adjacent_sum(arr));

	}
	private static int min_coins(int[] coins, int target){
		int dp[] = new int[target+1];
		Arrays.fill(dp, Integer.MAX_VALUE);
		dp[0] = 0;
		for(int i=1;i<=target;i++){
			for(int coin : coins){
				if(i>=coin){
					if(dp[i-coin]!=Integer.MAX_VALUE){
						int needed_coins = 1 + dp[i-coin];
						if(needed_coins<dp[i]){
							dp[i] = needed_coins;
						}
					}
				}
			}
		}
		return dp[target];

	}
	private static int cutting_rod(int[] prices){
		int dp[] = new int[prices.length];
		for(int i=0;i<prices.length;i++) dp[i] = prices[i];

		for(int i=1;i<prices.length;i++){
			for(int j=0;j<i;j++){
				int current = prices[j] + dp[i-j-1];
				dp[i] = Math.max(dp[i], current);
			}
		}
		return dp[prices.length-1];
	}
	private static int non_adjacent_sum(int arr[]){
		int n = arr.length;
		// int dp = new int[n];
		int prev1 = Math.max(arr[1],arr[0]);
		int prev2 = arr[0];
		for(int i=2;i<n;i++){
			int inc = arr[i] + prev2;
			int not_inc = prev1;

			prev2 = prev1;
			prev1 = Math.max(inc, not_inc);
		}
		return prev1;
	}
}