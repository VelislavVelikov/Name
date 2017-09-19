a= ARGV[0].to_f
b = ARGV[1].to_f
c = ARGV[2].to_f
D = b*b-4*a*c


if D == 0 then
	x1 = (-b/(2*a))
	if(a!=0 or b!=0 or c!=0)
		puts x1.round(2)
	else puts "#" end
end

if D > 0 

	x1 = ((-b + Math.sqrt(D))/(2*a))
	x2 = ((-b - Math.sqrt(D))/(2*a))
	
	if (x1*100)%10 != 0 
		x1 = x1.round(2) end
	if (x1*10)%10 != 0 and (x1*100)%10 == 0
		x1 = x1.round(1) end
	if (x1*10)%10 == 0 and (x1*100)%10 == 0
		x1 = x1.to_i end
	
	if (x2*100)%10 != 0 
		x2 = x2.round(2) end
	if (x2*10)%10 != 0 and (x2*100)%10 == 0
		x2 = x2.round(1) end
	if (x2*10)%10 == 0 and (x2*100)%10 == 0
		x2 = x2.to_i end
	
	if x1<x2 
		puts x1.to_s + ", " + x2.to_s
	else
		puts x2.to_s + ", " + x1.to_s end
end