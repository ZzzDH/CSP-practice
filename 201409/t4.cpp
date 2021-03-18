#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
const int N = 1000;
const int DIRECTSIZE = 4;	//移动方向 
struct direct {	//移动 
	int drow,dcol;
}direct[DIRECTSIZE]={{-1,0},{1,0},{0,-1},{0,1}};

struct node {
	int row,col,step;
	node(){}
	node(int r,int c, int s) {
		row = r,col=c,step = s;
	}
}; 
queue<node> q;
int buyercount = 0;
long long ans = 0;
int buyer[N+1][N+1];
int visited[N+1][N+1];
 
void bfs(int n) {
	node front,v;
	while(!q.empty()) {
		front = q.front();
		q.pop();
		for(int i=0;i<DIRECTSIZE;i++) {
			v.row = front.row+direct[i].drow;
			v.col = front.col+direct[i].dcol;
			v.step = front.step+1;
			if(v.row<1||v.row>n||v.col<1||v.col>n) {
				continue;
			}
			if(visited[v.row][v.col]==1) {
				continue;
			}
			if(buyer[v.row][v.col]>0) {
				visited[v.row][v.col]=1;
				ans += buyer[v.row][v.col]*v.step;
				if(--buyercount == 0)
					return;
			}
			visited[v.row][v.col] = 1;
			q.push(v);
		}
	}
}
int main() {
	int n,m,k,d,xi,yi,ci=0;
	memset(buyer,0,sizeof(buyer));
	memset(visited,0,sizeof(visited));
	cin>>n>>m>>k>>d;
	for(int i=0;i<m;i++) {
		cin>>xi>>yi;
		q.push(node(xi,yi,0));
		visited[xi][yi]=1;
	}
	for(int i=0;i<k;i++) {
		cin>>xi>>yi;
		cin>>ci;
		if(buyer[xi][yi]==0) {
			buyercount++;
		}
		buyer[xi][yi]+=ci;
	}
	for(int i=0;i<d;i++) {
		cin>>xi>>yi;
		visited[xi][yi]=1;
	}
	bfs(n);
	cout<<ans<<endl;
	
	return 0;
}
