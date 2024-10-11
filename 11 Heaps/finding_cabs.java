import java.util.*;
/*
5
C1
1
1
C1 1 1
C2
2
1
C2 2 1
C3
3
2
C3 3 2
C4
0
1
C4 0 1
C5
2
3
C5 2 3
3
*/
class Car{
	String name;
	int x;
	int y;
	public Car(){
		name = "";
		x=0;
		y=0;
	}
	public double dist(){
		return Math.pow(x*x+y*y, 0.5);
	}
}
class Compare implements Comparator<Car>{
	public int compare(Car a, Car b){
		if(a.dist()==b.dist()) return 0;
		else return a.dist()<b.dist()? -1:1;
	}
}
class finding_cabs{
	public static void main(String args[]){
		ArrayList<Car> cars = new ArrayList<>();
		Scanner inp = new Scanner(System.in);
		int n = inp.nextInt();
		// inp.nextLine();
		for(int i=0;i<n;i++){
			Car carinp = new Car();
			carinp.name = inp.nextLine();
			carinp.x = inp.nextInt();
			// inp.nextLine();
			carinp.y = inp.nextInt();
			// inp.nextLine();
			cars.add(carinp);
			System.out.println(carinp.name+" "+carinp.x+" "+carinp.y);

		}
		int k = inp.nextInt();


		PriorityQueue<Car> q = new PriorityQueue<Car>(new Compare());

		for(int i=0;i<k;i++){
			q.add(cars.get(i));
		}

		for(int i=k;i<cars.size();i++){
			Car item = cars.get(i);
			if(item.dist()<q.peek().dist()){
				q.remove();
				q.add(item);
			}
		}

		for(int i=0;i<k;i++){
			System.out.println(q.remove().name);
		}
		return;

	}
}