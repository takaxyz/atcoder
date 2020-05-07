#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);

void dfs(vector<vector<int>> edge, vector<int> &dist, int n, int d){
  stack<int> st;
  dist[n] = d;
  st.push(n);

  while(!st.empty()){
    int m = st.top(); st.pop();
    REP(i,edge[m].size()){
      if(dist[edge[m][i]]!=-1)continue;
      dist[edge[m][i]] = dist[m] + 1;
      st.push(edge[m][i]);
    }
  }
}

int main(){
  int N;
  cin >> N;

  vector<vector<int>> edge(N);
  REP(i,N-1){
    int a,b;
    cin >> a >> b;
    a--; b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  vector<int> dist1(N,-1);
  vector<int> dist2(N,-1);

  dfs(edge, dist1, 0, 1);
  dfs(edge, dist2, N-1, 1);


  int cnt_b=0;;
  int cnt_w=0;
  REP(i,N){
    if(dist1[i] <= dist2[i]){
      cnt_b++;
    }else{
      cnt_w++;
    }
  }
  if(cnt_b>cnt_w){
    cout << "Fennec" << endl;
  }else{
    cout << "Snuke" << endl;
  }
}

