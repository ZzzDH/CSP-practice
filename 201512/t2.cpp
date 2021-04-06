#include<iostream>

using namespace std;

inline int myabs(int x) {
	return (x>=0)?x:-x;
}
int main() {
	int n,m;
	cin>>n>>m;
	int matrix[n][m];
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>matrix[i][j];
		}
	}
	 
	for(int i=0;i<n;i++) {
		for(int j=0;j<m-2;j++) {
			if(myabs(matrix[i][j])==myabs(matrix[i][j+1])&&myabs(matrix[i][j+1])==myabs(matrix[i][j+2])) {
				if(matrix[i][j]>0) {
					matrix[i][j]=-matrix[i][j];
				}
				if(matrix[i][j+1]>0) {
					matrix[i][j+1]=-matrix[i][j+1];
				}
				if(matrix[i][j+2]>0) {
					matrix[i][j+2]=-matrix[i][j+2];
				} 
			}
		}
	}
	//对列进行标记
	for(int j=0;j<m;j++) {
		for(int i=0;i<n-2;i++) {
			if(myabs(matrix[i][j])==myabs(matrix[i+1][j])&&myabs(matrix[i+1][j])==myabs(matrix[i+2][j])) {
				if(matrix[i][j]>0) {
					matrix[i][j] = -matrix[i][j];
				}
				if(matrix[i+1][j]>0) {
					matrix[i+1][j] = -matrix[i+1][j];
				}
				if(matrix[i+2][j]>0) {
					matrix[i+2][j] = -matrix[i+2][j];
				}
			}
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(matrix[i][j]<0) {
				matrix[i][j]=0;
			}
			if(j!=0) cout<<" ";
			cout<<matrix[i][j];
		}
		cout<<endl;
	}
	return 0;
	 
}
