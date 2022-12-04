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
  string s;
  cin >> s;

  if(s[0]=='1'){
    cout << "No" << endl;
    return 0;
  }

  vi a(7,0);

  if(s[6]=='1')a[0]=1;
  if(s[3]=='1')a[1]=1;
  if(s[1]=='1' || s[7]=='1')a[2]=1;

  if(s[4]=='1')a[3]=1;

  if(s[2]=='1' || s[8]=='1')a[4]=1;

  if(s[5]=='1')a[5]=1;
  if(s[9]=='1')a[6]=1;


  FOR(i,1,6){
    if(a[i]==1)continue;

    bool l=false;
    REP(j,i){
      if(a[j]==1)l=true;
    }
    bool r=false;

    FOR(j,i+1,7){
      if(a[j]==1)r=true;
    }
    if(l&r){
      cout << "Yes" << endl;
      return 0;
    }
  }



  cout << "No" << endl;
}

