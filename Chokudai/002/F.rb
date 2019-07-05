require 'set'
s=Set.new
N=gets.to_i
N.times do
  s.add(gets.chomp.split.map(&:to_i).sort)
end
puts s.size