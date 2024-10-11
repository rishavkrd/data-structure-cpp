import java.util.*;
class quickSelect{
	public static void main(String args[]){
		int[] arr = {10,5,2,0,7,6,4};
		Scanner inp = new Scanner(System.in);
		int n = inp.nextInt();

		System.out.println(n+"th smallest element is: "+quickselect(arr, n,0,arr.length -1));

		for(int i:arr){
			System.out.println(i);
		}
	}
	public static int quickselect(int[] arr, int n, int s, int e){
		if(s>e) return -1;
		int mid = partition(arr, s,e);
		if(mid == n){
			return arr[mid];
		}
		int left=-1, right =-1;
		left = quickselect(arr,n, s, mid-1);
		right = quickselect(arr, n,mid+1, e);

		if(left>=0) return left;
		else return right;

	}
	public static int partition(int[] arr, int s, int e){
		int p = arr[e];
		int i=s-1, j=s;
		while(j<e){
			if(arr[j]>p){
				j++;
			}
			else{
				i++;
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				j++;
			}
		}
		int temp = arr[i+1];	
		arr[i+1] = arr[j];
		arr[j] = temp;
		return i+1;
	}
}