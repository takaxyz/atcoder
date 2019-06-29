n=gets.to_i
l,r,x,u,d,y=[],[],[],[],[],[]
n.times do
  xx,yy,dd=gets.chomp.split;
  case dd
  when 'L'
    l << xx.to_i
    y << yy.to_i
  when 'R'
    r << xx.to_i
    y << yy.to_i
  when 'U'
    x << xx.to_i
    u << yy.to_i
  when 'D'
    x << xx.to_i
    d << yy.to_i
  end
end
l.sort!
l = [l[0],l[-1]] if l.size > 0
r.sort!
r = [r[0],r[-1]] if r.size > 0
x.sort!
x = [x[0],x[-1]] if x.size > 0
u.sort!
u = [u[0],u[-1]] if u.size > 0
d.sort!
d = [d[0],d[-1]] if d.size > 0
y.sort!
y = [y[0],y[-1]] if y.size > 0

t=[]
if(l[0]-x[0]>0) t << l[0]-x[0]
if(r[0]-l[0]>0) t << (r[0]-l[0])/2.0
if(x[1]-r[1]>0) t << x[1]-r[1]
if(l[1]-x[1]>0) t << x[1]-r[1]
    
if(d[0]-y[0]>0) t << d[0]-y[0]
if(u[0]-d[0]>0) t << (u[0]-d[0])/2.0
if(y[1]-u[1]>0) t << y[1]-u[1]