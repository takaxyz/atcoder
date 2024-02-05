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
const int MOD = 1e9 + 7;

int main(){
  int h,w,k;
  cin >> h >> w >> k;
  vector<string> s(h);
  REP(i,h)cin >> s[i];


  int ans=INF;
  REP(i,h){
    int c0=0;
    int c1=0;

    if(k > w)break;

    REP(j,k){
      if(s[i][j]=='o')c0++;
      else if(s[i][j]=='.')c1++;
    }
    if(c0+c1==k)chmin(ans,c1);

    REP(j,w-k){
      if(s[i][j]=='o')c0--;
      else if(s[i][j]=='.')c1--;

      if(s[i][k+j]=='o')c0++;
      else if(s[i][k+j]=='.')c1++;
  
      if(c0+c1==k)chmin(ans,c1);
    }
  }

  REP(i,w){
    int c0=0;
    int c1=0;

    if(k > h)break;

    REP(j,k){
      if(s[j][i]=='o')c0++;
      else if(s[j][i]=='.')c1++;
    }
    if(c0+c1==k)chmin(ans,c1);

    REP(j,h-k){
      if(s[j][i]=='o')c0--;
      else if(s[j][i]=='.')c1--;

      if(s[k+j][i]=='o')c0++;
      else if(s[k+j][i]=='.')c1++;
  
      if(c0+c1==k)chmin(ans,c1);
    }
  }

  cout << (ans == INF ? -1 : ans) << endl;
}

