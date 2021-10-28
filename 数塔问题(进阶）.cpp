#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	long long a[2*n-1][2*n-1];
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++)
		cin>>a[i][j];
		
		for(long long i=n;i<2*n-1;i++)
			for(long long j=0;j<(2*n-1-i);j++)
			cin>>a[i][j];
	long long b[2*n-1][2*n-1];
	memset(b,0,sizeof(b));
	
	//下半部分 
	b[2*n-2][0]=a[2*n-2][0];
	for(long long i=2*n-3;i>=n-1;i--){
		for(long long j=0;j<(2*n-1-i);j++){
		if(j==0){
			b[i][j]=a[i][j]+b[i+1][j];
		}else if(j==(2*n-2-i)){
			b[i][j]=a[i][j]+b[i+1][j-1];	
		}
		else {
			b[i][j]=a[i][j]+max(b[i+1][j-1],b[i+1][j]);
		}
	}
	}  
	
	//上半部分 
	for(long long i=n-2;i>=0;i--){
		for(long long j=0;j<=i;j++){
			b[i][j]=a[i][j]+max(b[i+1][j],b[i+1][j+1]);
		}
	}
	cout<<b[0][0];
}
