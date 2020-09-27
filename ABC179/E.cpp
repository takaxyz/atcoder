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
  ll n, x,m;
  ll en;
  cin >> n >> x >> m;

  set<int> st;
  st.insert(x);
  ll now=x;
  vector<ll> list;
  list.emplace_back(now);

  int cnt=1;
  for(ll i=0; i < n-1; i++){
    now = (now*now)%m;

    if(now==0){
      ll ans=0;
      REP(j,list.size()){
        ans += list[j];
      }
      cout << ans << endl;
      return 0;
    }

    if(st.count(now)){
      en = now;
      break;
    }
    st.insert(now);
    list.emplace_back(now);
  }

  ll ans=0;
  if(st.size() == n){
    REP(i,list.size()){
      ans += list[i];
    }
    cout << ans << endl;
  }else{
    // cout << list.size() << endl;

    // cout << en << endl;

    int p=0;
    while(list[p]!=en)p++;
    // cout << p << endl;
    REP(i,p)ans+=list[i];
    // cout << ans << endl;
    ll tmp=0;
    FOR(i,p,list.size())tmp+=list[i];
    // cout << tmp << endl;
    n -= p;
    ans += (tmp * (n/(list.size()-p)));
    REP(i,(n%(list.size()-p)))ans+=list[i+p];
    cout << ans << endl;
  }
}

