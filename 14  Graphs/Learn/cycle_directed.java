import java.util.*;

// class Node{
// 	string id;
// 	ArrayList<Node> neighbors;

// }

class Graph{
	int V;
	// static int y;

	List<List<Integer>> neighbors;
	Graph(int x){
		V = x;
		// y = x;
		neighbors = new ArrayList<List<Integer>>();
		for(int i=0;i<V;i++)
			neighbors.add(new ArrayList<Integer>());
	}
	void addEdge(int a, int b){
		neighbors.get(a).add(b);
		// neighbors[b].add(a);
	}
}
class CyclicGraph{
	public static void main(String args[]){
		int n = 6;
		Graph g = new Graph(n);
		g.addEdge(0,1);
		g.addEdge(1,2);
		g.addEdge(2,3);
		g.addEdge(3,0);	//cycle
		g.addEdge(0,5);
		g.addEdge(0,4);

		boolean visited[] = new boolean[n];
		Arrays.fill(visited, false);
		boolean stack[] = new boolean[n];
		Arrays.fill(stack, false);
		for(int i=0;i<g.V;i++){
			if(isCyclic(i,g,visited, stack)) {
				System.out.println("Cyclic: true");
				return;
			}
		}
		System.out.println("Cyclic: false");
		return;
		
	}
	static public boolean isCyclic(int n,Graph g, boolean visited[], boolean stack[]){
		System.out.println("parent: "+n);
		visited[n] = true;
		stack[n] = true;

		for(int i:g.neighbors.get(n)){
			System.out.println(" child: "+i);
			if(stack[i]) {
				System.out.println("back edge from "+n+" to "+i);
				return true;
			}
			
			// visited[i] = true;
			
			if(!visited[i]) if(isCyclic(i,g, visited, stack)) return true;

			// visited[i]=false;
			stack[i] =false;
		}
		return false;

	}
}