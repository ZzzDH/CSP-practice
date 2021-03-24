#include<iostream>
#include<cstring>

using namespace std;

const int N = 10000;
int num[N+1];

int main() {
	memset(num,0,sizeof(num));
	int n,input,count,maxcount=0;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>input;
		num[input]++;
	}
	for(int i=1;i<=N;i++) {
		if(num[i]>maxcount) {
			count = i;
			maxcount = num[i];
		}
	}
	cout<<count;
	return 0;
}
