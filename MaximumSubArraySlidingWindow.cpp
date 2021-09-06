#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int k;
	cin>>k;
	int i=0,j=0,sum=0,maxs=-12345;
	while(j<n){
		sum+=a[j];
		if(j-i+1<k){
			j++;
		}
		else if(j-i+1==k){
			maxs=max(sum,maxs);
			sum=sum-a[i];
			i++;
			j++;
		}

	}
	cout<<maxs;

	return 0;
}