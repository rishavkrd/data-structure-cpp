import java.util.*;
// import java.util.Pair;
// import java.lang.*;
/*
3
92 022
82 5
77 13
2
numeric
false
*/
/*
3
92 022
82 5
77 13
2
lexo
false
*/
class Pair {
	String key;
	String value;

	public static int compare(Pair a, Pair b){
		return a.key.compareTo(b.key);
	}
}

class ComparePair implements Comparator<Pair>{

	public int compare(Pair a, Pair b){
		return a.key.compareTo(b.key);
	}
}
class CompareNumeric implements Comparator<Pair>{
	public int compare(Pair a, Pair b){
		int num1, num2;
		num1 = toInt(a.key);
		num2 = toInt(b.key);
		System.out.println(num1 + "," + num2);
		if(num1==num2) return 0;
		return num1<num2?-1:1;
	}
	public int toInt(String s){
		int res =0, pow = 1;
		for(int i=s.length()-1; i>=0;i--){
			res+= (s.charAt(i) - '0')*pow;
			pow*=10;
		}
		return res;
	}
}

class sortingStrings{
	public static void main(String[] args){
		// System.out.println("Happy Hacking");
		Scanner inp = new Scanner(System.in);

		int n = inp.nextInt();
		inp.nextLine();
		ArrayList<String> slines = new ArrayList<String>();
		for(int i=0;i<n;i++){
			slines.add(inp.nextLine());
			// System.out.println(slines.get(i));
		}
		int col = inp.nextInt();
		inp.nextLine();
		String order = inp.nextLine();
		// System.out.println(order);
		
		boolean reverse = inp.nextBoolean();

		ArrayList<Pair> pair = new ArrayList<Pair>();

		for(int i=0;i<n;i++){
			Pair p = new Pair();
			p.key = extractToken(slines.get(i), col);
			p.value = slines.get(i);
			pair.add(p);
		}

		if(order.equals("lexo")) {
			Collections.sort(pair, new ComparePair());
			System.out.println("lexo sort");
		}
		else Collections.sort(pair,new CompareNumeric());

		if(reverse) Collections.reverse(pair);

		for(Pair p : pair){
			System.out.println(p.value);
		}


	}

	public static String extractToken(String s, int col){
		StringTokenizer st = new StringTokenizer(s, " ");
		String res="";
		while(col!=0){
			col--;
			res = st.nextToken();
		}
		return res;
	}
}