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
  int n,k;
  cin >> n >> k;

  map<string, int> mp;
  REP(i,n){
    string s;
    cin >> s;
    mp[s]++;
  }

  vector<pair<int, string>> v;
  for(auto &x: mp){
    v.emplace_back(x.second, x.first);
  }
  v.emplace_back(-1,"");
  v.emplace_back(INF,"");
  sort(ALL(v));
  reverse(ALL(v));

  if(v[k-1].first != v[k].first && v[k].first != v[k+1].first){
    cout << v[k].second << endl;
  }else{
    cout << "AMBIGUOUS" << endl;
  }

}

