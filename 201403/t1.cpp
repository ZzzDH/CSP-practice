#include<iostream>
#include<cstring>
using namespace std;

const int N = 500;
int an[N+1];

int main() {
	memset(an,0,sizeof(an));
	int n,ans=0,plus;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>an[i];
	}
	
	for(int i=0;i<n-1;i++) {
		for(int j=i;j<n;j++) {
			plus = an[i]+an[j];
			if(plus == 0) {
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
