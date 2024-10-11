#include <iostream>
using namespace std;

int main(){
	int n = 15;
	int m = 2;

	int i=1, j=3;

	int mask = -1;
	mask = mask << (j+1);
	// int m2 = -1;
	// m2 = m2 >> (32-i);
	int m2 = (1<<i) -1;
	mask = mask|m2;

	n = n&mask;

	n = n|(m<<i);

	// cout<<n<<endl;
	//Fast Exponent

	// int a,b,ans=1; //a^b
	// cin>>a>>b;
	// while(b){
	// 	int last_bit = b&1;
	// 	if(last_bit){
	// 		ans *=a;
	// 	}
	// 	a*=a;
	// 	b = b>>1;
	// }
	// cout<<ans<<endl;

	//decimal to binary
	int num;
	cin>>num;
	int res=0;
	int p = 1;
	while(num){
		res += (num&1)*p;
		num=num>>1;
		p*=10;
	}

	cout<<res<<endl;
	return 0;
}