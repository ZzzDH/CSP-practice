#include<iostream>

using namespace std;

int monthdays[2][13]= {{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,
30,31,31,30,31,30,31}};
int isleapyear(int year) {
	return ((year%4==0)&&(year%100!=0)||(year%400==0))?1:0;
}

int main() {
	int y,d;
	int m=1;
	cin>>y>>d;
	while(d>monthdays[isleapyear(y)][m]){
		d-=monthdays[isleapyear(y)][m];
		m++;
	}
	cout<<m<<endl<<d<<endl;
	return 0;
	
}
