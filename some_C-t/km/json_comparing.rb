require 'json'

if JSON.parse(File.read(ARGV[0].to_s)) == JSON.parse(File.read(ARGV[1].to_s))
	puts 1
else
	puts 0
end