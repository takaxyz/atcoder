n=gets.to_i
score={}
n.times do |i|
  s,p=gets.chomp.split
  p = p.to_i
  if !score.has_key?(s)
    score[s] = []
  end
  score[s] << [p,i+1]
end
score.keys.sort.each do |k|
  score[k].sort {|a,b| a[0] <=> b[0]}.reverse.each do |ss,pp|
    puts pp
  end
end