#include<iostream>
/*����ⷨ�ñ������㷨�������Ҽ��㣬�Ƚ������뵽
�������Ǵ����濪ʼһֱ�ҵ���n��������������Ƕ���*/
using namespace std;

const int N = 1000;
int h[N];

int main() {
	int n,ans=0,area,height;
	cin>>n;
	ans = 0;
	for(int i=0;i<n;i++) {
		cin>>h[i];
	}
	for(int i=0;i<n;i++) {//��ѭ�� 
		height = h[i];
		for(int j = i;j<n;j++) {
			if(h[j]<height) {	 
				height = h[j];
			}
			area = (j-i+1)*height;
			if(area > ans) ans = area; 
		}
	}
	cout<<ans;
} 
