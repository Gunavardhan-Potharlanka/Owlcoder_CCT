#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<vector<int>> s(n, vector<int>(32, 0));
    for(int i=0;i<32;i++) s[0][i]=((v[0]&(1<<i))>0);
    for(int i=1;i<n;i++) for(int j=0;j<32;j++) s[i][j]=s[i-1][j]+((v[i]&(1<<j))>0);
    	for(int i=0;i<n;i++){
        for(int j=0;j<32;j++) cout<<s[i][j]<<" ";
        cout<<endl;
    }
    int t=0;
    int l, r; cin>>l>>r;
    if(l==r) t=v[l];
    else if(l==0){
        if(r==n-1){
        	for(int i=0;i<32;i++) if((s[n-1][i])>0) t=(t|(1<<i));
        	// cout<<"Case 1"<<endl;
        }
        else{
        	for(int i=0;i<32;i++) if((s[r][i])>0) t=(t|(1<<i));
        	// cout<<"Case 2"<<endl;
        }
    }
    else{
    	for(int i=0;i<32;i++) if((s[r][i]-s[l-1][i])+1>0) t=(t|(1<<i));
        // cout<<"Case 3"<<endl;
    }
    cout<<t;
}