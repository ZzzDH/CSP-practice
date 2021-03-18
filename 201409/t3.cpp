#include<iostream>
#include<cctype>
#include<string>

using namespace std;

int main() {
	string s,low,input,tinput;
	int mode,n=0;
	cin>>s>>mode>>n;
	low=s;
	for(int i=0;i<(int)low.size();i++) {
		if(isupper(low[i])) {
			low[i]=tolower(low[i]);
		}
	}
	for(int i=0;i<n;i++) {
		cin>>input;
		if(mode==0) {
			tinput=input;
			for(int j=0;j<(int)tinput.size();j++) {
				if(isupper(tinput[j])) {
					tinput[j]=tolower(tinput[j]);
				}
			}
			int pos = 0;
			pos = tinput.find(low);
			if(pos>=0) {
				cout<<input<<endl;
			}
		} else {
			int pos = input.find(s);
			if(pos>=0) {
				cout<<input<<endl;
			}
		}
	}
	return 0;
} 
