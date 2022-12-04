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
  int n;
  cin >> n;
  bool flag=true;
  set<string> st;
  REP(i,n){
    string s;
    cin >> s;

    if(s[0]!='H' && s[0]!='D' && s[0]!='C' && s[0]!='S')flag=false;
    if(s[1]!='A' && s[1]!='2' && s[1]!='3' && s[1]!='4' && s[1]!='5' && s[1]!='6' && s[1]!='7' && s[1]!='8' && s[1]!='9'
      && s[1]!='T' && s[1]!='J' && s[1]!='Q'&& s[1]!='K')flag=false;
    if(st.count(s))flag=false;
    st.insert(s);
  }

  cout << (flag ? "Yes" : "No") << endl;
}

