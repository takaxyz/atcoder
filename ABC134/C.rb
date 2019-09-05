N=gets.to_i
a=[]
N.times {a << gets.to_i}
b=a.sort
a.each do |v|
  if b[-1] == v
    puts b[-2]
  else
    puts b[-1]
  end
end