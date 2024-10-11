import java.util.*;
import java.lang.*;
class permutations{
	static ArrayList<String> res = new ArrayList<String>();
	public static void main(String args[]){
		String inp = "abc";
		permute(inp, "");
		for(String s : res){
			System.out.print(s+',');

		}
		System.out.println();
	}
	public static void permute(String inp, String out){
		if(inp.length()==0){
			res.add(out);
			System.out.println(out);
			return;
		}
		// System.out.println(out);
		char charr[] = inp.toCharArray();
		for(int i=0;i<inp.length();i++){
			char temp = inp.charAt(0);
			// inp.setCharAt(0,inp.charAt(i));
			// inp.setCharAt(i,temp);
			charr[0] = charr[i];
			charr[i] = temp;
			// System.out.println(String.valueOf(charr).substring(1));
			permute(String.valueOf(charr).substring(1), out+charr[0]);
			//backtrack
			// inp.setCharAt(i, inp.charAt(0));
			// inp.setCharAt(0, temp);
			charr[i] = charr[0];
			charr[0] = temp;
		}
		return;
	}
}