import java.util.*;
class parenthesis{
	static boolean isBalanced(String s){
	Stack<Character> brackets = new Stack<Character>();
	for(char c : s.toCharArray()){
		switch(c){
		case '(':
			brackets.push(')');
			break;
		case '{': 
			brackets.push('}');
			break;
		case '[':
			brackets.push(']');
			break;
		}
		if(c==')' || c=='}' || c==']'){
            if(brackets.empty()) return false;
            if (brackets.peek() == c){
				// cout<<brackets.peek()<<endl;
				brackets.pop();
            } else return false;
        }
	}
	if(brackets.empty()) return true;
	return false;
}


	public static void  main(String args[]){
		String s = "{ a + (b+c) + ([d+e]*f) } + { a + (b+c) + ([d+e]*f)) } + k";

		if(isBalanced(s)){
			System.out.println("Balanced!");
		}
		else{
			System.out.println("Not Balanced!");

		}
		return;
	}
}