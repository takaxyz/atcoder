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
  int n,c;
  cin >> n >> c;
  map<int,int> mp1, mp2;
  REP(i,n){
    int a;
    cin >> a;
    if(i%2==0){
      mp1[a]++;
    }else{
      mp2[a]++;
    }
  }

  vector<P> cnt1, cnt2;
  for(auto v: mp1)cnt1.emplace_back(make_pair(v.second, v.first));
  for(auto v: mp2)cnt2.emplace_back(make_pair(v.second, v.first));
  cnt1.emplace_back(make_pair(0,0));
  cnt2.emplace_back(make_pair(0,0));
  sort(RALL(cnt1));
  sort(RALL(cnt2));

  int ans = 0;
  if(cnt1[0].second == cnt2[0].second){
    if((n+1)/2 - cnt1[1].first > n/2 - cnt2[1].first){
      ans += ((n+1)/2 - cnt1[0].first)*c;
      ans += (n/2 - cnt2[1].first) * c;
    }else{
      ans += ((n+1)/2 - cnt1[1].first)*c;
      ans += (n/2 - cnt2[0].first) * c;
    }
  }else{
    ans += ((n+1)/2 - cnt1[0].first)*c;
    ans += (n/2 - cnt2[0].first)*c;
  }
  cout << ans << endl;
}

