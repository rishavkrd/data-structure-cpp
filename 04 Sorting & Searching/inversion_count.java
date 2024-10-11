
class inversion_count{
	public static void main(String args[]){
		int arr[] = {0,5,2,3,1};
		System.out.println("the inversion_count is "+ mergesort(arr, 0, arr.length-1));
	}
	private static int mergesort(int[] arr, int s, int e){
		if(s>=e){
			return 0;
		}
		int mid = (s+e)/2;
		int c1 = mergesort(arr, s, mid);
		int c2 = mergesort(arr, mid+1, e);
		int c3 = merge(arr, s,e);

		return c1+c2+c3;
	}
	private static int merge(int[] arr, int s, int e){
		
		int mid = (s+e)/2;
		int i=s, j=mid+1;
		int temp[] = new int[e-s+1];
		int idx=0;
		int count = 0;
		while(i<=mid && j<= e){
			if(arr[i]<arr[j]){
				temp[idx++] = arr[i++];
			} else{
				temp[idx++] = arr[j++];
				count += mid-i+1;
			}
		}
		while(i<=mid){
			temp[idx++] = arr[i++];
		}
		while(j<=e){
			temp[idx++] = arr[j++];
		}

		for(int k=s; k<=e; k++){
			arr[k] = temp[k-s];
		}
		return count;
	}
}