#include <bits/stdc++.h>
using namespace std;

void fmaxcmax(vector<int> a,int l,int r,int &max1,int &max2){
	if(l==r){
		max1=a[l];
		max2=INT_MIN;
		return;
	}
	if(l+1==r){
		max1=max(a[l],a[r]);
		max2=min(a[l],a[r]);
		return;
	}
	else{
		int m1,m2,mid;
		mid=(l+r)/2;
		fmaxcmax(a,l,mid,max1,max2);
		fmaxcmax(a,mid+1,r,m1,m2);
		max2=max(min(max1,m1),max(max2,m2));
		max1=max(max1,m1);
		return;
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	int max1,max2;
	fmaxcmax(a,0,n-1,max1,max2);
	cout<<max1<<" "<<max2;
	return 0;
}

