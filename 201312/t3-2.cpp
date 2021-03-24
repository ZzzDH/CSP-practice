#include<iostream>
/*这个解法用暴力计算法，从左到右计算，比较容易想到
这样就是从左面开始一直找到第n个，看最大的面积是多少*/
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
	for(int i=0;i<n;i++) {//大循环 
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
