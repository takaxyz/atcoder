#include <bits/stdc++.h>
/* S.size() s.substr(l,r=s.size()-l) -> l文字目からr文字分
__gcd()　lower_bound(a+l,a+r,x)-a でindex
// 配列  -> min/max({}) 
// vector-> *min_element(a+l,a+r)  *忘れず lとrで[l,r) 
//reverse(a+l,a+r)   配列aの[l,r)を逆順に strはreverse(all(s))
//sort(a+l,a+r,greater <int>()) 配列aの[l,r)昇順sort,大きい順はgreater<type>()
//vectorならall(v)
clock()/CLOCKS_PER_SEC で秒数
vector v.push_back(x),v.pop_back()
q.push(x),front()で先頭を返す,pop()で削除, size(),empty()
<deque>(push/pop)_(front/back)/fornt/back/insert/
priority_queue 宣言は priority_queue< Type, vector<Type>, greater<Type>> Q1; 
// pq.push(x),top()で参照 pop()で削除   greaterで最小 lessで最大がtopに*/
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define print(i) std::cout << (i) << '\n'
#define rrep(i,n) for(int (i)=(n)-1;(i)!=-1;(i)--)
#define vep(i,v) for(auto (i)=v.begin();(i)<(v.end());(i)++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
inline long long ceildiv(long long a, long long  b) { return (a+b-1)/b; }
typedef pair<long long,long long> P;
typedef pair<int,int> PI;
typedef std::vector<int> vi;
typedef std::vector<long long> VI;
using Graph = std::vector<std::vector<int> >;
const long long inf = 10e17;
const long long mod = 1000000007;
//int |x|<=2*10**9     long |x|<= 9*10**18
//printf(".(小数点以下の桁数)lf(double時、float ならf)")
#define ll long long
#define ull unsigned long long
#define ld long double
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define vvc vector<vector<char>>
#define vc vector<char>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define pque priority_queue
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define rall(x) (x).rbegin(),(x).rend()

string dfs(string s){
    string res;
    rep(i,s.size()){
        if (s[i]!='(')res+=s[i];
        else{
            string temp;
            ll cnt=1ll;
            i++;
            for (;i<s.size();i++){
                if (s[i]=='(')cnt++;
                else{if (s[i]==')')cnt--;
                if (cnt==0)break;}
                temp+=s[i];
        }
    temp=dfs(temp);
    res+=temp;
    reverse(all(temp));
    res+=temp;}
}
return res;}
int main(){
    string s;
    cin>>s;
    print(dfs(s));
}

