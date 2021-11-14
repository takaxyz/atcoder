#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define RALL(a)     (a).rbegin(),(a).rend()
#define PRINT(a)   cout << (a) << endl

#define pb push_back
#define eb emplace_back

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
  int m;
  cin >> m;

  vvi e(10);
  REP(i,m){
    int u,v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }

  string s = "999999999";
  REP(i,8){
    int p;
    cin >> p;
    s[p-1] = (char)('0' + i + 1);
  }

  map<string, int> mp;
  mp[s] = 0;
  queue<string> q;
  q.push(s);
  while(!q.empty()){
    string v = q.front(); 
    q.pop();

    int p;
    REP(i,9)if(v[i] == '9')p=i+1;

    for(auto pp: e[p]){
      string w = v;
      swap(w[pp-1], w[p-1]);
      if(mp.count(w))continue;
      mp[w] = mp[v] + 1;
      q.push(w);
    }

  }
  if(mp.count("123456789")==0){
    cout << -1 << endl;
    return 0;
  }
  cout << mp["123456789"] << endl;
}

