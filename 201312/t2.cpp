#include<iostream>
#include<string>
//��Ŀ�����������Ӧ���õ�string�࣬���������ַ�Ҫ���ȿ���stirng����ȥ��char[] 
using namespace std;

int main() {
	string s;
	cin>>s;
	int sum=0,j=1;
	for(int i=0;i<(int)s.length()-1;i++) {
		if(s[i]!='-') {
			sum+=(s[i]-'0')*j++;
		}
	}
	char c;
	c = sum%11;
	if(c==10) {
		c='X';
	} else {
		c = c+'0';
	}
	if(c==s[s.length()-1]) {
		cout<<"Right"<<endl;
	} else {
		s[s.length()-1] = c;
		cout<<s<<endl;
	} 
}
