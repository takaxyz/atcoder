#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define RALL(a)     (a).rbegin(),(a).rend()
#define PRINT(a)   cout << (a) << endl

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second

#define debug(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n';

using ll = long long int;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;

int n,q;
bool edge[101][101];
bool used[101];

void dfs(int x, int p=-1){
  used[x]=true;
  REP(i,n){
    if(i==p)continue;
    if(edge[x][i] && !used[i]){
      dfs(i, x);
    }
  }

}

int main(){
  cin >> n >> q;
  
  REP(i,q){
    int t, u, v;
    cin >> t >> u >> v;
    u--; v--;
    if(t==1){
      edge[u][v] = !edge[u][v];
      edge[v][u] = edge[u][v];
    }else{
      REP(i,n)used[i]=false;
      dfs(u, -1);
      cout << (used[v] ? "Yes" : "No") << endl;
      
    }

  }



}


