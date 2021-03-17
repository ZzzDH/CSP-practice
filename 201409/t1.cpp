#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1000;

int a[N+1];

int main() {
	int n,count=0;
	memset(a,0,sizeof(a));
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=n;i>0;i--) {
		if(((a[i]-a[i-1])==1)||((a[i]-a[i-1])==-1)) {
			count++;
		}
	}
	cout<<count;
}
/* another solution~

const int N = 10000;
bool flag[N+2];
int main() {
	int n,t,count;
	memset(flag,false,sizeof(flag));
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>t;
		flag[t] = true;
		if(flag[t-1]||flag[t+1]) {
			count++;
		}
	}
	cout<<count;
} 
*/

