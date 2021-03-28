#include<iostream>
#include<stack>
/*������ҵ��뷨��Ūһ���ṹ���������ڣ�Ȼ����ݴ��µ��ϵ�˳������ջ��Ȼ����֮��
ͨ����ջ�ķ�ʽ��¼�ǵ㵽���ĸ�����*/

using namespace std;
typedef struct Window {
	int x1;
	int x2;
	int y1;
	int y2;
	int number;
}Window;


int main() {
	int n,m=0;
	int x1,x2,y1,y2,top,x,y=0;
	top=-1;
	cin>>n>>m;
	stack<Window> s1,s2;
	for(int i=0;i<n;i++) {
		Window w1;
		cin>>w1.x1>>w1.y1>>w1.x2>>w1.y2;
		w1.number = i+1;
		s1.push(w1);
	}
	for(int i=0;i<m;i++) {
		top = -1;
		cin>>x>>y;
		while(!s1.empty()) {
			Window temp = s1.top();
			s1.pop();
			if((temp.x1<=x)&&(temp.x2>=x)) {
				if((temp.y1<=y)&&(temp.y2>=y)) {
					top = temp.number;
					while(!s2.empty()) {
						Window temp2 = s2.top();
						s2.pop();
						s1.push(temp2);
					}
					s1.push(temp);
					break;
				}
			}
			s2.push(temp);
		}
		if(top == -1) {
			cout<<"IGNORED"<<endl;
		} else {
			cout<<top<<endl;
		}
	}
	return 0;
} 
