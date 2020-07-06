#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define PRINT(a)   cout << (a) << endl
#define RALL(v) rbegin(v), rend(v)

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
  int N;
  cin >> N;
  vvi t(N, vi());
  map<int,int> mp;

  REP(i,N){
    int k;
    cin >> k;
    REP(j,k){
      int tt;
      cin >> tt;
      t[i].eb(tt);
      mp[tt]=i;
    }
  }

  set<int> s1,s2;
  vi h(N);
  REP(i,N){
    s1.insert(t[i][0]);
    h[i]=1;
  }
  REP(i,N){
    if(t[i].size()>1){
      s2.insert(t[i][1]);
    }
  }

  int M;
  cin >> M;

  REP(i,M){
    int a;
    cin >> a;

    if(a==1 || s2.size()==0){
      int v = *(s1.rbegin());
      cout << v << endl;
      s1.erase(v);

      int idx = mp[v];

      if(h[idx] < t[idx].size()){
        s1.insert(t[idx][h[idx]]);
        s2.erase(t[idx][h[idx]]);
        h[idx]++;
      }
      if(h[idx] < t[idx].size()){
        s2.insert(t[idx][h[idx]]);
      }
    }else{
      int v1 = *(s1.rbegin());
      int v2 = *(s2.rbegin());

      cout << max(v1,v2) << endl;

      if(v1 > v2){
        s1.erase(v1);

        int idx = mp[v1];

        if(h[idx] < t[idx].size()){
          s1.insert(t[idx][h[idx]]);
          s2.erase(t[idx][h[idx]]);
          h[idx]++;
        }
        if(h[idx] < t[idx].size()){
          s2.insert(t[idx][h[idx]]);
        }
      }else{
        s2.erase(v2);

        int idx = mp[v2];

        h[idx]++;
        if(h[idx] < t[idx].size()){
          s2.insert(t[idx][h[idx]]);
        }
      }
    }

  }

}

