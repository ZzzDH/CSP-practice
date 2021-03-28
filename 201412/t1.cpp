#include<iostream>
#include<map>
using namespace std;

int main() {
	map<int,int> m;
	int n,v;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>v;
		m[v]++;
		
		if(i!=1) {
			cout<<" ";
		}
		cout<<m[v];
	}
	cout<<endl;
	cout<<endl;
	return 0;
}
