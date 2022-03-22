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

int main(){
  int n, m;
  cin >> n >> m;

  vvi d(n, vi(n,INF));

  REP(i,n)d[i][i]=0;
  vector<tuple<int,int,int>> edge;

  REP(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    d[a][b]=c;
    d[b][a]=c;
    edge.emplace_back(c,a,b);
  }
  sort(ALL(edge));
  reverse(ALL(edge));

  REP(k,n)REP(i,n)REP(j,n){
    if(d[i][j] > d[i][k] + d[k][j]){
      d[i][j] = d[i][k] + d[k][j];
    }
  }

  int ans=0;
  for(auto v: edge){
    int c = get<0>(v);
    int a = get<1>(v);
    int b = get<2>(v);

    if(d[a][b]<c){
      ans++;
      continue;
    }

    REP(i, n){
      if(i==a || i == b)continue;
      if(d[a][i] + d[i][b] == d[a][b]){
        //cout << a << " " << b << endl;
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
}

