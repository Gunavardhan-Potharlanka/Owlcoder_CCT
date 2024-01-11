#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> prime(1e6+1, 1);
void Generate_Seive(){
	prime[0]=0;
	prime[1]=0;
	for(int i=2;i*i<1e6+1;i++) if(prime[i]) for(int j=i*i;j<1e6+1;j+=i) prime[j]=0;
}
int main(){
	Generate_Seive();
	cout<<prime[7];
}