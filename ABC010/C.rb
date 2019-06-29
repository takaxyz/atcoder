txa,tya,txb,tyb,t,v=gets.chomp.split.map(&:to_i)
n=gets.to_i
n.times do
    x,y=gets.chomp.split.map(&:to_i)
    if (Math.sqrt((txa-x)**2 + (tya-y)**2) + Math.sqrt((txb-x)**2 + (tyb-y)**2)) <= t * v
        puts "YES"
        exit
    end
end
puts "NO"
