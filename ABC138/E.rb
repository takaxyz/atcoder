s=gets.chomp.split("")
t=gets.chomp.split("")

idx=Hash.new { |h, k| h[k] = [] }

s.each_with_index do |c,i|
  idx[c] << i
end
l = []
t.each do |c|
  if idx[c].size == 0
    puts -1
    exit
  end

  if l.size == 0
    prev = -1
  else
    prev = l[-1]
  end
  
  tmp = idx[c].bsearch {|x| x >  prev}
  if tmp == nil
    l << idx[c][0]
  else
    l << tmp
  end
end

prev=Float::INFINITY
cnt = 0
l.each do |v|
  if prev >= v
    cnt += 1
  end
  prev = v
end
puts s.size * (cnt-1) + l[-1] + 1