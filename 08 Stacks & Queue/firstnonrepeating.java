import java.util.*;
class firstnonrepeating{
	public static void main(String args[]){
		String s = "aabccbcd";
		Queue<Character> queue = new LinkedList<>();
		Hashtable<Character,Integer> map = new Hashtable<Character,Integer>();
		ArrayList<String> res = new ArrayList<>();
		for(char c : s.toCharArray()){
			if(!map.containsKey(c)){
				map.put(c,1);
				
				queue.add(c);
				res.add(String.valueOf(queue.peek()));
			} else{
				map.replace(c, map.get(c)+1);
				while(!queue.isEmpty() && map.get(queue.peek())!=1){
					queue.remove();
				}
				if(queue.isEmpty()){
					res.add("-1");
				} else{
					res.add(String.valueOf(queue.peek()));
				}
			}
		}
		for(String c : res){
			System.out.print(c+",");
		}
		System.out.println();
	}
}