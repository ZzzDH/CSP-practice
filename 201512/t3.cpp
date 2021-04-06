#include<iostream>
#include<cstring>

using namespace std;

const int N=100;

char paint[N+1][N+1];
const int DIRECTSIZE = 4;
struct direct {
	int dx,dy;
}direct[DIRECTSIZE]={{-1,0},{1,0},{0,-1},{0,1}};

void fill(int x,int y,char c,int m,int n) {
	int nx,ny;
	paint[y][x]=c;
	for(int i=0;i<DIRECTSIZE;i++) {
		nx=x+direct[i].dx;
		ny=y+direct[i].dy;
		if(0<=nx&&nx<m&&0<=ny&&ny<n&paint[ny][nx]!='-'&&paint[ny][nx]!='+'&&paint[ny][nx]!='|'&&paint[ny][nx]!=c) {
			fill(nx,ny,c,m,n);
		}
	}
}

int main() {
	int m,n,q;
	int option=-1;
	int x1,x2,y1,y2;
	int start,end;
	char c;
	memset(paint,'.',sizeof(paint));
	cin>>m>>n>>q;
	for(int i=0;i<q;i++) {
		cin>>option;
		if(option==0) {
			cin>>x1>>y1>>x2>>y2;
			if(x1==x2) {	//竖着一列 
				start = min(y1,y2);
				end = max(y1,y2);
				for(int j=start;j<=end;j++) {
					if(paint[j][x1]=='-'||paint[j][x1]=='|') {
						paint[j][x1]='+';
					}
					else {
						paint[j][x1]='|';
					}
				}
			}
			else if(y1==y2) {	//横着一排 
				start = min(x1,x2);
				end = max(x1,x2);
				for(int j=start;j<=end;j++) {
					if(paint[y1][j]=='-'||paint[y1][j]=='|') {
						paint[y1][j]='+';
					}
					else {
						paint[y1][j]='-';
					}
				}
			}
		}
		else if(option == 1) {
			cin>>x1>>y1>>c;
			fill(x1,y1,c,m,n);
		}
	}
	for(int i=n-1;i>=0;i--) {
		for(int j=0;j<m;j++) {
			cout<<paint[i][j];
		}
		cout<<endl;
	}
	return 0;
}
