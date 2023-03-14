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
  int n,q;
  string s;
  cin >> n >> s >> q;

  vector<fenwick_tree<int>> fws(26, fenwick_tree<int>(n));

  REP(i,s.size()){
    int x = s[i]-'a';
    fws[x].add(i,1);
  }


  REP(_,q){
    int t;
    cin >> t;
    if(t==1){
      int x;
      char c;
      cin >> x >> c;
      x--;
      fws[s[x]-'a'].add(x,-1);
      fws[c-'a'].add(x,1);
      s[x]=c;
    }else{
      int l,r;
      cin >> l >> r;
      l--; r--;
      bool ok=true;
      for(int i = s[l]-'a'+1; i < s[r]-'a'; i++){
        if(fws[i].sum(0,n) != fws[i].sum(l,r+1))ok=false;
      }

      if(!ok){
        cout << "No" << endl;
        continue;
      }

      int l2=l;
      REP(i,26){
        int cnt = fws[i].sum(l2,r+1);
        if(cnt != fws[i].sum(l2, l2+cnt)){
          ok=false;
          break;
        }
        l2 += cnt;
      }

      cout << (ok ? "Yes" : "No") << endl;
    }
  }
}

