#include<iostream>
#include<cstring>

using namespace std;

const int N = 100;

bool flag[N+1][N+1];

int main() {
	int n,x1,y1,x2,y2,color=0;
	memset(flag,false,sizeof(flag));
	
	cin>>n;
	for(int i = 0;i<n;i++) {
		cin>>x1>>y1>>x2>>y2;
		color += (x2-x1)*(y2-y1);
		for(int j = x1;j<x2;j++) {
			for(int k=y1;k<y2;k++) {
				if(flag[j][k]) {
					color--;
				}
				flag[j][k]=true;
			}
		}
	}
	cout<<color<<endl;
	return 0;
}
