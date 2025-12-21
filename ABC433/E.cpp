#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
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

using mint = modint1000000007;
// using mint = modint998244353;

void solve()
{
  int n,m;
  cin >> n >> m;
  vi x(n),y(m);
  REP(i,n)cin >> x[i];
  REP(i,m)cin >> y[i];

  set<int> usedx,usedy;
  
  vi px(n*m+1,-1),py(n*m+1,-1);

  REP(i,n)px[x[i]]=i;
  REP(i,m)py[y[i]]=i;

  vvi a(n,vi(m,-1));

  for(int i = n*m; i > 0; i--){
    if(px[i]!=-1&&py[i]!=-1){
      if(a[px[i]][py[i]] != -1){
        cout << "No" << endl;
        return;
      }
      a[px[i]][py[i]] = i;

      usedx.insert(px[i]);
      usedy.insert(py[i]);
    }else if(px[i]!=-1){
      bool ok=false;
      for(auto v: usedy){
        if(a[px[i]][v] == -1){
          a[px[i]][v] = i;
          ok=true;
          break;
        }
      }
      if(!ok){
        cout << "No" << endl;
        return;
      }

      usedx.insert(px[i]);
    }else if(py[i]!=-1){
      bool ok=false;
      for(auto v: usedx){
        if(a[v][py[i]] == -1){
          a[v][py[i]] = i;
          ok=true;
          break;
        }
      }
      if(!ok){
        cout << "No" << endl;
        return;
      }

      usedy.insert(py[i]);
    }else{
      bool ok=false;
      for(auto ux: usedx){
        for(auto uy: usedy){
          if(a[ux][uy]==-1){
            a[ux][uy] = i;
            ok=true;
            break;
          }
        }
        if(ok)break;
      }
      if(!ok){
        cout << "No" << endl;
        return;
      }
   }
  }

  cout << "Yes" << endl;

  REP(i, n){
    REP(j,m){
      cout << a[i][j] << (j==m-1 ?  "\n" : " ");
    }
  }

}

int main(){
  int q;
  cin >> q;
  REP(_,q)solve();
}

