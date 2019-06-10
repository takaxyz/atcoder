require 'set'

n,q=gets.chomp.split.map(&:to_i)

stx = []
n.times do
  s,t,x = gets.chomp.split.map(&:to_i)
  s -= x
  t -= x
  stx << [s,x]
  stx << [t,-x]
end
stx.sort!
ans = Set.new
i = 0
q.times do
  d = gets.to_i
  while(stx[i][0] <= d)
    if stx[i][1] > 0
      ans.add(stx[i][1])
    else
      ans.delete(-stx[i][1])
    end
    i += 1
    break if i == 2*n
  end

  puts ans.min != nil ? ans.min : -1
end