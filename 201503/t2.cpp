#include<iostream>
#include<map>
#include<queue>

using namespace std;

struct node {
	int count,key;
	bool operator < (const node& n) const {
		if(count==n.count) {
			return key>n.key;
		}
		else return count<n.count;
	}
}; 

int main() {
	int n,num;
	map<int,int> m;
	priority_queue<node> q;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>num;
		m[num]++;
	}
	
	node keyval;
	for(map<int,int>::iterator it = m.begin();it!=m.end();it++) {
		keyval.key=it->first;
		keyval.count=it->second;
		q.push(keyval);
	}
	while(!q.empty()) {
		keyval = q.top();
		q.pop();
		cout<<keyval.key<<" "<<keyval.count<<endl;
	}
	return 0;
}
