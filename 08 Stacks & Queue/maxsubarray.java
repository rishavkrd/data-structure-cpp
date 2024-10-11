import java.util.*;
class maxsubarray{
	public static void main(String args[]){
		int arr[] = {1,2,3,1,6,1,1,1,1,4,0,1,2,3,4};
		int k = 3;
		Deque<Integer> deque = new LinkedList<>();
		int max=0;
		int i=0;
		int age = 0;
		for(;i<k;i++){
			if(max<arr[i]){
				age = k-i;
			}
			max = Math.max(arr[i], max);
		}
		deque.addFirst(max);
		System.out.print(max+",");
		
		for(;i<arr.length;i++){
			
			if(arr[i]>=deque.getFirst()){
				age = 0;
				while(!deque.isEmpty()){
					deque.removeFirst();
				}
				deque.addFirst(arr[i]);

			} 
			if(arr[i]<deque.getFirst()){
				while(arr[i]>deque.getLast()){
					deque.removeLast();
				}
			}
			if(age==k){
				//expired
				deque.removeFirst();
				age = 0;

			}
			deque.addLast(arr[i]);
			age++;

			System.out.print(deque.removeFirst()+",");

		}
		System.out.println();

	}
}