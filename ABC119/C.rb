N,A,B,C=gets.chomp.split.map(&:to_i)
l=[]

N.times { l << gets.to_i }
ans = Float::INFINITY
1.upto(4**N-1) do |i|
  t=i
  a,b,c=0,0,0
  a_cnt,b_cnt,c_cnt=0,0,0
  N.times do |j|
    case t&3
    when 0
    when 1
      a += l[j]
      a_cnt+=1
    when 2
      b += l[j]
      b_cnt+=1
    when 3
      c += l[j]
      c_cnt+=1
    end
    t = t >> 2
  end
  if [a,b,c].min > 0
    tmp = (A-a).abs + (a_cnt-1)*10 + (B-b).abs + (b_cnt-1)*10 + (C-c).abs + (c_cnt-1)*10
    ans = tmp if ans > tmp
  end
end

puts ans