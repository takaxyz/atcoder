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

int cnt(string &x, string &y){
  int ret=0;
  REP(i,x.size()){
    if(x[i]==y[i])ret++;
    else break;
  }
  return ret;
}

bool ck(string t, string &t2, string &t3){
  if(t==t2)return true;

  if(t.size() + 1 == t2.size()){
    int sz = cnt(t,t2);
    reverse(ALL(t));
    sz += cnt(t,t3);
    return sz >= t.size();
  }
  if(t.size() - 1 == t2.size()){
    int sz = cnt(t2,t);
    reverse(ALL(t));
    sz += cnt(t3,t);
    //cout << t << " " << t2 <<  " " << sz << " " << t2.size() << endl;
    return sz >= t2.size();
  }

  if(t.size()==t2.size()){
    int sz = cnt(t,t2);
    reverse(ALL(t));
    sz += cnt(t,t3);
    return sz == t.size()-1;
  }

  return false;

}


int main(){
  int n;
  string t;
  cin >> n >> t;
  string t3 = t;
  reverse(ALL(t3));
  vi ans;
  REP(i,n){
    string s;
    cin >> s;
    if(ck(s,t,t3))ans.pb(i);
  }
  cout << ans.size() << endl;
  for(auto v: ans)cout << v + 1<< endl;
}

