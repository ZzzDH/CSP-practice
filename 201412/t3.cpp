#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 5000;

struct trade {
	int orderNo;
	char t;
	float price;
	long long quantity;
	bool operator < (const trade& n) const {
		if(t=='s') {
			return price>n.price;
		}
		else {
			return price<n.price;
		}
	}
};

bool cancelflag[N+1];

int main() {
	trade t;
	priority_queue<trade> sell,buy;
	string trading;
	memset(cancelflag,false,sizeof(cancelflag));
	int no=0,tno;
	while(cin>>trading) {
		if(trading[0]=='c') {
			no++;
			cin>>tno;
			cancelflag[tno] = true; 
		}
		else if(trading[0]=='b'||trading[0]=='s') {
			t.orderNo = ++no;
			
			cin>>t.price>>t.quantity;
			
			if(trading[0]=='b') {
				t.t = trading[0];
				buy.push(t);
			} else {
				t.t = trading[0];
				sell.push(t);
			}
		} else break;
	}
	t.price = 0;
	t.quantity = 0;
	trade b,s;
	for(;;) {
		while(!buy.empty()) {
			b = buy.top();
			if(cancelflag[b.orderNo]) {
				buy.pop();
			} else break;
		}
		while(!sell.empty()) {
			s = sell.top();
			if(cancelflag[s.orderNo]) {
				sell.pop();
			} else break;
		}
		if(buy.empty()||sell.empty()) {
			break;
		}
		if(b.price>=s.price) {
			t.quantity+=min(b.quantity,s.quantity);
			t.price = b.price;
			if(b.quantity == s.quantity) {
				buy.pop();
				sell.pop();
			} else if(b.quantity>s.quantity) {
				b.quantity -= s.quantity;
				buy.pop();
				buy.push(b);
				sell.pop();
			} else {
				buy.pop();
				s.quantity -= b.quantity;
				sell.pop();
				sell.push(s);
			}
		} else break;
	}
	printf("%.2f",t.price);
	cout<<" "<<t.quantity;
	return 0;
}
