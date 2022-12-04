#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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
  int n,m;
  cin >> n >> m;

  vvi val(m+1,vi());
  FOR(i,1,n+1){
    int a;
    cin >> a;
    if(a>n)continue;

    int l=1;
    if(a<0){
      l = (- a + i - 1)/i;
    }

    FOR(j,l,m+1){
      int v = a + j * i;
      if(v > n)break;
      val[j].emplace_back(v);
    }
  }

  // FOR(i,1,m+1){
  //   cout << i << endl;
  //   for(auto v: val[i]){
  //     cout << v << " ";
  //   }
  //   cout << endl;
  // }

  FOR(i,1,m+1){
    vector<bool> c(val[i].size()+1);
    for(auto v: val[i]){
      if(v <= val[i].size())c[v]=true;
    }

    REP(j,n+1){
      if(c[j]==false){
        cout << j << endl;
        break;
      }
    }
  }
}


