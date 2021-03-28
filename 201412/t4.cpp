#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//要写一个并查集

class UF {
private:
	vector<int> v;
public:
	UF(int n) {
		for(int i=0;i<=n;i++) {
			v.push_back(i);
		}
	}
	int Find(int x) {
		while(v[x]!=x) {
			x=v[x];
		}
		return x;
	}
	bool Union(int x,int y) {
		x=Find(x);
		y=Find(y);
		if(x==y)
			return false;
		else {
			v[x]=y;
			return true;
		}
	}		
}; 

struct edge {
	int src,dest,cost;
	bool operator < (const edge& n) const {
		return cost>n.cost;
	}
};

int main() {
	priority_queue<edge> q;
	edge e;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		cin>>e.src>>e.dest>>e.cost;
		q.push(e);
	}
	UF uf(n);
	int ans=0,count=0;
	while(1) {
		e = q.top();
		q.pop();
		if(uf.Find(e.src)!=uf.Find(e.dest)) {
			uf.Union(e.src,e.dest);
			ans += e.cost;
			if(++count == n-1) {
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
