#include<iostream>

using namespace std;

int mdays[2][13] {{0,31,28,31,30,31,30,31,31,30,31,30,31},
				{0,31,29,31,30,31,30,31,31,30,31,30,31}};
				
int leapyear(int year) {
	return ((year%4==0 && year%100!=0)||year%400==0)?1:0;
}

int main() {
	int a,b,c,y1,y2,weekd,d,y;
	cin>>a>>b>>c>>y1>>y2;
	int days = 0;
	for(int i=1850;i<y1;i++) {
		days += 365+leapyear(i);
	}
	for(int i=y1;i<=y2;i++) {
		y=leapyear(i);
		int days2 = days;
		for(int i=1;i<a;i++) {
			days2+=mdays[y][i];
		} 
		weekd=1+days2%7;
		d=(b-1)*7+((weekd>=c)?(c+7-weekd):(c-weekd));
		if(d>mdays[y][a]) {
			cout<<"none"<<endl;
		}
		else {
			cout<<i<<"/";
			if(a<10) {
				cout<<"0";
			}
			cout<<a<<"/";
			if(d<10) {
				cout<<"0";
			}
			cout<<d<<endl;
		}
		days+=365+leapyear(i);
	}
	return 0;
}
