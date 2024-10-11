import java.util.*;
//input 
/*
1
2
4
-1
-1
5
7
-1
-1
-1
3
-1
6
-1
7
-1
-1
*/
class Node{
	int val;
	Node left;
	Node right;
	Node(){
		this.val = 0;
		this.left = null;
		this.right = null;
	}
	Node(int x){
		this.val = x;
		this.left = null;
		this.right = null;
	}
}
class HDpair{
	int height;
	int dia;
	HDpair(){
		this.height = 0;
		this.dia = 0;
	}
}
class diameter{
	static Scanner inp = new Scanner(System.in);
	public static void main (String args[]){
		Node root;
		root = buildTree();
		System.out.println("Tree is: ");
		// printTree(root);
		levelTraversal(root);

		HDpair d = max_diameter(root);

		System.out.println("diameter: "+d.dia);

		return;
	}
	static HDpair max_diameter(Node root){
		HDpair p = new HDpair();
		if(root==null) return p;

		HDpair p1 = max_diameter(root.left);
		HDpair p2 = max_diameter(root.right);

		p.height = 1 + Math.max(p1.height, p2.height);
		int d1 = p1.height + p2.height;

		p.dia =  Math.max(d1, Math.max(p1.dia, p2.dia));

		return p;

	}
	static Node buildTree(){
		
		int n = inp.nextInt();
		// inp.nextLine();
		if(n==-1){
			return null;
		}
		Node node = new Node(n);
		node.left = buildTree();
		node.right = buildTree();

		return node;
	}
	static void printTree(Node root){
		if(root==null ) return;
		System.out.println(root.val);
		printTree(root.left);
		printTree(root.right);
		return;
	}
	static void levelTraversal(Node root){
		Queue<Node> queue = new LinkedList<>();
		queue.add(root);
		queue.add(null);

		while(!queue.isEmpty()){
			if(queue.peek()==null){
				queue.remove();
				if(!queue.isEmpty()) queue.add(null);
				System.out.println();
			}else{
				Node current = queue.remove();
				System.out.print(current.val+" ");
				if(current.left!=null) queue.add(current.left);
				if(current.right!=null) queue.add(current.right);
			}
		}
		return;
	}
}