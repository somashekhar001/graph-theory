#include<bits/stdc++.h>

using namespace std;

#define ll long long int 

#define vi vector<ll>

vi out[500000];//out going edges

vi in[500000];//incoming edges

vi topo,topo1;//stores vertices in topological order

vector<bool> vis,vis1;

void dfs(ll v){
    vis[v]=true;
    for(auto c:out[v]){
        if(!vis[c])dfs(c);
    }
    topo.push_back(v);
}

int main(){
    ll n,m;cin>>n>>m; // n number of vetices and m number of edges

       vi cnt(n+1,0);

    for(int i=0;i<m;i++){
        ll a,b;cin>>a>>b;  // a->b input 
        out[a].push_back(b);//out going edges from a will be pushed a->b 
        in[b].push_back(a);//in going edges to b from a will be pushed a->b 
        cnt[b]++;
    } 
    vis.assign(n+1,0);
//--- 1st method using dfs --- (O(n+m))
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    reverse(topo.begin(),topo.end());
    for(auto x:topo){
        cout<<x<<" ";
    }
    cout<<"\n";
    
 //if graph "donot have cycle" use "1st method" which gives you topo vector which is topological order of given directed acyclic graph
 //if graph "can have cycle" use "2nd method" which gives you topo vector which is topological order of given graph if it has cycle it will detect cycle.    
// --- 2nd method using cnt array of incoming edges ---(O(n+m)(kahn's algorithm))
     vis1.assign(n+1,0);
    for(int i=1;i<=n;i++){
        if(cnt[i]==0 && !vis1[i]){
             
         queue<ll>q;
         q.push(i);
         while(!q.empty()){ 
          ll x=q.front();
          vis1[x]=true;
          topo1.push_back(x);
          q.pop();
          for(auto c:out[x]){
            cnt[c]--;
            if(cnt[c]==0)q.push(c);
          }
         
         }
        }
    }
    if(topo1.size()==n){  
    for(auto c:topo1)cout<<c<<" ";
     cout<<endl;
    }
    else{
        cout<<"FOUND CYCLE NO TOPOLOGICAL SORTING POSSIBLE"<<endl;// we found cycle in given graph 
    }


  return 0;
}
