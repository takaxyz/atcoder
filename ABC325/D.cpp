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
  int n;
  cin >> n;
  vector<pair<ll,ll>> p(n); 
  REP(i,n){
    ll t,d;
    cin >> t >> d;
    p[i] = {t, t+d};
  }

  sort(ALL(p));

  ll now=0;
  int it = 0;
  priority_queue<ll, vector<ll>, greater<ll>> q;
  int ans=0;
  while(true){
    if(q.empty()){
      if(it==n)break;
      now = p[it].first;
    }


    while(it < n && p[it].first == now)q.push(p[it++].second);

    while(!q.empty() && q.top()<now)q.pop();

    if(!q.empty()){
      ans++;
      q.pop();
    }
    now++;
  } 

  cout << ans << endl;

}
