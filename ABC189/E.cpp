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

vector<vector<ll>> a={{0,1,0},{-1,0,0},{0,0,1}};
vector<vector<ll>> b={{0,-1,0},{1,0,0},{0,0,1}};

vector<vector<ll>> c={{-1,0,0},{0,1,0},{0,0,1}};
vector<vector<ll>> d={{1,0,0},{0,-1,0},{0,0,1}};


vector<vector<ll>> ff(vector<vector<ll>> &x, vector<vector<ll>> &y){

  vector<vector<ll>> z(3, vector<ll>(3,0));
  REP(i,3)REP(j,3)REP(k,3){
     z[i][j] += x[i][k] * y[k][j]; 
  }
  return z;

}

int main(){
  int n;
  cin >> n;
  vector<ll> x(n), y(n);
  REP(i,n)cin >> x[i] >> y[i];


  int m;
  cin >> m;

  vector<vector<vector<ll>>> z(m+1);
  z[0] = {{1,0,0},{0,1,0},{0,0,1}};

  REP(i,m){
    int op;
    int p;
    cin >> op;
    switch(op){
      case 1:
        z[i+1] = ff(a, z[i]);
      break;
      case 2:
        z[i+1] = ff(b, z[i]);
      break;
      case 3:
        cin >> p;
        c[0][2] = 2*p;
        z[i+1] = ff(c, z[i]);
      break;
      case 4:
        cin >> p;
        d[1][2] = 2*p;
        z[i+1] = ff(d,z[i]);
      break;
    }
  }

  // REP(i,m+1){
  //   REP(j,3)REP(k,3){
  //     cout << z[i][j][k] << " ";
  //     if(k==2)cout << endl;
  //   }
  //   cout << endl;
  // }

  int q;
  cin >> q;
  REP(i,q){
    int a,b;
    cin >> a >> b;
    b--;
    vector<ll> s = {x[b], y[b], 1};
    vector<ll> t(3,0);
    REP(j,3)REP(k,3){
      t[j] += z[a][j][k] * s[k];
    }
    cout << t[0] << " " << t[1] << endl;

  }

}

