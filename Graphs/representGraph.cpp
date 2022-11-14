#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,i,j;
	int adj[n+1][m+1];
	cin>>n>>m;
	for(i=0;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[v][u]=1;
		adj[u][v]=1;
	}
	
}
