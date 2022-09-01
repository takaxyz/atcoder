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
  int h,w;
  cin >> h >> w;
  vector<string> g(h);
  REP(i,h)cin >> g[i];

  vvi v(h,vi(w,0));
  int i = 0;
  int j = 0;

  bool ok=true;
  while(ok){
    if(v[i][j]){
      cout << -1 << endl;
      return 0;
    }else{
      v[i][j]=1;
    }

    switch (g[i][j])
    {
    case 'U':
      if(i==0){
        ok=false;
      }else{
        i--;
      }
      break;
    
    case 'D':
      if(i==h-1){
        ok=false;
      }else{
        i++;
      }
      break;

    case 'L':
      if(j==0){
        ok=false;
      }else{
        j--;
      }
      break;

    case 'R':
      if(j==w-1){
        ok=false;
      }else{
        j++;
      }
      break;
    }
  }
  cout << i+1 << " " << j+1 << endl;
}

