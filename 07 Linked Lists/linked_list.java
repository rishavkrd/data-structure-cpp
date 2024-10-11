
import java.util.*;

class linkedlist{

	static class Node{
		int val;
		Node next;
		Node(){
			this.val = 0;
			this.next = null;
		}
		 Node(int x){
			this.val = x;
			next = null;
		}
		
	}
	public static void main(String args[]){
		Node head = new Node(1);
		Node b = new Node(0);
		head = append(head, 2);
		b = append(b, 3);
		head = append(head, 4);
		head = append(head, 5);
		b = append(b, 6);
		head = append(head, 7);
		b = append(b, 8);
		head = itrReverse(head);
		b = reverse(b);
		// head = kreverse(head,3);

		Node randomlist = new Node(3);
		randomlist = append(randomlist, 5);
		randomlist = append(randomlist, 4);
		randomlist = append(randomlist, 1);
		randomlist = append(randomlist, 2);
		print (randomlist);
		System.out.println("Result of merge");
		randomlist = mergesort(randomlist);
		print(randomlist);
		// print(head);
		// System.out.println();
		// print (b);
		
		// print(mergesortedLists(head,b));
		return;
	}
	static Node mid(Node head){
		Node slow = head;
		Node fast = head.next;

		while(fast!=null && fast.next!=null){
			slow = slow.next;
			fast = fast.next.next;
		}
		return slow;
	}
	static Node mergesort(Node head){
		if(head==null || head.next==null) return head;

		Node mid = mid(head);
		Node l1 = mergesort(mid.next);
		mid.next = null;
		Node l2 = mergesort(head);
		// mid.next = null;
		// print(l1); print(l2);
		Node res = mergesortedLists(l1,l2);
		// System.out.print("merged: ");
		// print (res);
		return res;
	}
	static Node mergesortedLists(Node a, Node b){
		if(a==null) return b;
		if(b==null) return a;

		Node dummy = new Node();

		if(a.val<b.val){
			dummy = a;
			dummy.next = mergesortedLists(a.next, b);
		} else{
			dummy = b;
			dummy.next = mergesortedLists(a, b.next);
		}
		return dummy;
		
	}
	static Node kreverse(Node head, int k){
		Node prev = null, current = head, foll = head.next;
		int n = k;
		ArrayList<Node> res = new ArrayList<Node>();
		while(current!=null && k>0){
			k--;

			foll = current.next;
			current.next = prev;

			prev = current;
			current = foll;
			// if(k==0) {
			// 	k=n;
			// 	res.add(prev);
			// 	prev = null;
			// }
		}
		// if(k>0){
		// 	res.add(prev);
		// }
		if(current!=null){
			head.next = kreverse(current, n);
		}
		return prev;
	}
	static Node mergeList(ArrayList<Node> klist){
		
		// current = klist.get(0);
		for(int i=0;i<klist.size()-1;i++){
			Node nextNode = klist.get(i+1);
			Node node = klist.get(i);
			while(node.next!=null){
				node = node.next;
			}
			node.next = nextNode;
		}
		return klist.get(0);
	}
	static Node append(Node head, int x){
		Node temp = new Node(x);
		temp.next = head;
		return head = temp;
		// return temp;
	}
	static void print(Node head){
		Node current = head;
		while(current!=null){
			System.out.print(current.val+",");
			current = current.next;
		}
		System.out.println();
	}
	static Node reverse(Node head){
		if(head==null || head.next==null){
			return head;
		}
		Node shead = reverse(head.next);
		head.next.next = head;
		head.next = null;
		return shead;
	}
	static Node itrReverse(Node head){
		Node prev = null, current = head, foll = head.next;

		while(current!=null){
			foll = current.next;

			current.next = prev;
			prev = current;
			current = foll;
			
		}
		return prev;
	}

}