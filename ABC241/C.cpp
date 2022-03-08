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
  int n;
  cin >> n;
  vector<string> s(n);
  REP(i,n)cin >> s[i];

  // 横向き
  REP(i,n)REP(j,n-5){
    int c=0;
    REP(k,6)if(s[i][j+k]=='#')c++;
    if(c>3){
      cout << "Yes" << endl;
      return 0;
    }

  }
  // 縦向き
  REP(i,n-5)REP(j,n){
    int c=0;
    REP(k,6)if(s[i+k][j]=='#')c++;
    if(c>3){
      cout << "Yes" << endl;
      return 0;
    }    
  }
  REP(i,n)REP(j,n){
    int c=0;
    REP(k,6){
      if(i+k >= n || j+k >= n){
        c=0;
        break;
      }
      if(s[i+k][j+k]=='#')c++;
    }
    if(c>3){
      cout << "Yes" << endl;
      return 0;
    }    
  }
  REP(i,n)REP(j,n){
    int c=0;
    REP(k,6){
      if(i+k >= n || j-k < 0){
        c=0;
        break;
      }
      if(s[i+k][j-k]=='#')c++;
    }
    if(c>3){
      cout << "Yes" << endl;
      return 0;
    }    
  }
  cout << "No" << endl;
}

