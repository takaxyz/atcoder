xa,ya,xb,yb,xc,yc=gets.chomp.split.map(&:to_i)
xb -= xa
xc -= xa
yb -= ya
yc -= ya
puts 0.5*(xb*yc-xc*yb).abs