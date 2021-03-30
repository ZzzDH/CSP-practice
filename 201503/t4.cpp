#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
//һ���ڵ㵽��һ���ڵ�������� 

//dfs������ڵ�now�������ڵ�ľ��룬Ȼ���������dist�� 
void dfs(int now,int last,int d[],vector<int> tree[]) {
	int num,u;
	num = tree[now].size();
	for(int i=0;i<num;i++) {
		u = tree[now][i];
		if(u!=last) {
			d[u] = d[now]+1;
			dfs(u,now,d,tree);
		}
	}
}

int main() {
	int n,m;
	vector<int> tree[20002];
	int dist[20002];
	cin>>n>>m;
	int t;
	vector<int> a,b;

	for(int i=2;i<=n;i++) {	//�������� 
		cin>>t;
		tree[i].push_back(t);
		tree[t].push_back(i);
	}
	for(int i=1;i<=m;i++) {	//���Ե� 
		cin>>t;
		tree[i+n].push_back(t);
		tree[t].push_back(i+n);
	}
	memset(dist,0,sizeof(dist));
	dfs(1,0,dist,tree);
	int far=0;//�ҳ���ڵ�1��Զ�Ľڵ�far
	dist[far]=0;
	for(int i=1;i<m+n+2;i++) {
		if(dist[i]>dist[far]) {
			far = i;
		}
	}
	memset(dist,0,sizeof(dist));
	dfs(far,0,dist,tree);
	int end=0;	//�ҳ���far��Զ��end 
	for(int i=1;i<m+n+2;i++) {
		if(dist[i]>dist[end]) {
			end = i;
		}
	}
	cout<<dist[end]<<endl;
	return 0;
}
