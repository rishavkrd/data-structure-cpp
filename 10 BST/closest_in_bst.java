import java.util.*;

class Node{
	int val;
	Node left;
	Node right;

	public Node(int x){
		this.val = x;
		this.left = null;
		this.right = null;
	}
	public Node addleft(int x){
		Node n = new Node(x);
		this.left = n;
		return this;
	}
	public Node addright(int x){
		Node n = new Node(x);
		this.right = n;
		return this;
	}
}

class closest_bst{
	public static void main(String args[]){
		Node root = new Node(8);
		root.addleft(3).addright(10);
		root.left.addleft(1).addright(6).right.addleft(4).addright(7);
		root.right.addright(14).right.addleft(13);

		printTree(root);
		Scanner inp = new Scanner(System.in);
		int n = inp.nextInt();
		int closest = closest(root, n);
		System.out.println("closest: "+closest);
	}
	public static int closest(Node root, int n){
		if(root==null) return -1;
		int ans = root.val;
		int min_diff = Math.abs(root.val - n);

		while(root!=null){
			int diff = Math.abs(root.val - n);
			if(diff<min_diff) {
				ans = root.val;
				min_diff = diff;
			}
			if(n>root.val){
				root = root.right;

			}
			else if(root.val == n){ 
				return root.val;
			} 
			else{
				root = root.left;
			}


		}
		return ans;
	}
	public static int neg_bug_closest(Node root, int n){
		if(root==null) return Integer.MAX_VALUE;

		long d1 = Math.abs(n-root.val);
		int left = closest(root.left,n);
		long d2 = Math.abs(n - left);
		int right = closest(root.right,n);
		long d3 = Math.abs(n - right);

		int ans = root.val;
		ans = d1<d2?root.val : left;
		int dans = Math.abs(n - ans);
		ans = d3< dans? right : ans;

		return ans;


	}
	public static void printTree(Node root){
		Deque <Node> q = new LinkedList<Node>();

		q.add(root);
		q.add(null);

		while(!q.isEmpty()){
			Node current = q.remove();
			if(current==null){
				if(!q.isEmpty()) q.add(null);
				System.out.println();
				continue;
			}
			System.out.print(current.val+" ");
			if(current.left!=null) q.add(current.left);
			if(current.right!=null) q.add(current.right);
		}
	}
}