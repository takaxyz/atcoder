A,B,C=gets.chomp.split.map(&:to_i)
puts A<C && C<B || B<C && C<A ? "Yes" : "No"
