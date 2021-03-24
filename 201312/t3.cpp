#include<iostream>
#include<stack>
/*该算法的思路是将每个直方图的高度放入栈中，如果高度递增，则最大
面积可能是在最右面出现，当非递增的时候，弹出栈中比当前高的数，一直重复该过程
直到所有都进去了。但是小问题就是如果出现非连续，那么就需要重新设计该算法。
注意的是，这个方法计面积是从左往右，高的优先，所以就只按这种方法来看面积，不
再去找别的看面积的方法了。*/

using namespace std;

const int N = 1000;
int h[N+1];
int main() {
	int n,ans = 0,area, temp;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>h[i];
	}
	h[n]=0;
	stack<int> s;
	for(int i=0;i<=n;i++) {
		if(s.empty()||h[s.top()]<h[i]) {
			s.push(i);
		} else {
			temp = s.top();
			s.pop();
			area = h[temp]*(s.empty()?i:i-s.top()-1);
			if(area>ans) {
				ans = area;
			}
			--i;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
