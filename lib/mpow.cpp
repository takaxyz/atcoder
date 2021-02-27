ll mpow(ll x, ll n, ll mod){
  ll y=1;
  while(n){
    if(n & 1)y = (y * x) % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return y % mod;
}

