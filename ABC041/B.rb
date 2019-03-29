MOD=10**9+7
A,B,C=gets.chomp.split.map{ |i|i.to_i%MOD}
puts (A*B*C)%MOD
