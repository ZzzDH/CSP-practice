#include<iostream>
#include<cstring>
using namespace std;

const int N = 1000;
int an[N+1];

int main() {
	int n,t;
	int section=0;
	memset(an,0,sizeof(an));
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>an[i];
		if(i!=0) {
			if(an[i]!=an[i-1]) {
				section++;
			}
		} else{
			section++;
		}
	}
	cout<<section<<endl;
	return 0;
}
