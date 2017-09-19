require 'json'

jeisan1 = JSON.parse(File.read(ARGV[0].to_s))

a=jeisan1['a'].to_f.round(2)
b=jeisan1['b'].to_f.round(2)
c=jeisan1['c'].to_f.round(2)
 
d=b*b-(4*a*c)
if d >= 0
x1=(-b+Math.sqrt(d))/(2*a)
x2=(-b-Math.sqrt(d))/(2*a)
else puts "FUCK YOU" end
hash = Hash.new
hash['x1'] = x1.to_f.round(2)
hash['x2'] = x2.to_f.round(2)
hash['D'] = d.to_f.round(2)
puts hash.to_json
