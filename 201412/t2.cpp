#include<iostream>
#include<cstring>

using namespace std;

struct {
	int row;
	int col;
}direct[] = {{0,1},{1,-1},{1,0},{-1,1}};

const int N = 500;
int matrix[N][N];
int main() {
	memset(matrix,0,sizeof(matrix));
	int n;
	int r,c,d=0;
	r=0;
	c=0;
	cin>>n;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>matrix[i][j];
		}
	}
	for(int m = 0;m<n*n;m++) {
		cout<<matrix[r][c]<<" ";
		//Ȼ���ƶ�����Ҫȥ������ƶ��˳�ȥ��ô��������ֻ���ƶ�
		r+=direct[d].row;
		c+=direct[d].col;
		if(d==0 && r==0) {	//����ʱ 
			d = 1;
		}
		else if(d==0&&r==n-1) {
			d = 3;
		}
		else if(d==1&&r==n-1) {	//�����½�ʱ 
			d = 0;
		}
		else if(d==1&&c==0) {
			d = 2;
		}
		else if(d==2&&r==n-1) {		//����ʱ 
			d = 3;
		}
		else if(d==2&&c==0) {
			d = 3;
		}
		else if(d==2&&c==n-1) {
			d = 1;
		}
		else if(d==3&&c==n-1) {		//������ʱ 
			d = 2;
		}
		else if(d==3&&r==0) {
			d=0;
		} 
	}
	return 0;
}
