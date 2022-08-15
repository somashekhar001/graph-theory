#include<bits/stdc++.h>

using namespace std;

#define ll long long int 

#define vi vector<ll>

vi out[500000];//out going edges

vi in[500000];//incoming edges

vi order;//storing in which order dfs2 will run

vi condensedgraph(500000,-1);//storing condensed graph by components

vector<bool> vis;

void dfs(ll v){
    vis[v]=true;
    for(auto c:out[v]){
        if(!vis[c])dfs(c);
    }
    order.push_back(v);
}
void dfs1(ll v,ll i){
    condensedgraph[v]=i;
    for(auto c:in[v]){
        if(condensedgraph[c]==-1)dfs1(c,i);
    }
}

int main(){
    ll n,m;cin>>n>>m; // n number of vetices and m number of edges

    for(int i=0;i<m;i++){
        ll a,b;cin>>a>>b;  // a->b input 
        out[a].push_back(b);//out going edges from a will be pushed a->b 
        in[b].push_back(a);//in going edges to b from a will be pushed a->b 
       
    } 
    vis.assign(n+1,0);
 
     for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
     }
     reverse(order.begin(),order.end());
      ll i=0;
     for(auto x:order){
        if(condensedgraph[x]==-1){
             i++;              // increment for number of components 
            dfs1(x,i);         // checking which are vertices belongs to ith component and mark it
        }
     }  

    // print number of strongly connected component
    
    cout<<i<<"\n"; 

    // print vertices(as index starting from 1) and which component it belongs to 
    
    for(int i=1;i<=n;i++)cout<<condensedgraph[i]<<" "; 
    
    cout<<"\n";

  return 0;
}