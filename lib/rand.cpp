  random_device seed_gen;
  mt19937_64 rnd(seed_gen());

  uniform_int_distribution<ll> d(1, (1LL<<60));

  REP(_,100)cout << d(rnd) << endl;
