#include<iostream>

using namespace std;

const int N = 1000;

int matrix[N][N];

int main() {
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>matrix[i][j];
		}
	}
	for(int j = 0;j<m;j++) {
		for(int i=0;i<n;i++) {
			if(i!=0) {
				cout<<" ";
			}
			cout<<matrix[i][m-j-1];
		}
		cout<<endl;
	}
	return 0;
} 
