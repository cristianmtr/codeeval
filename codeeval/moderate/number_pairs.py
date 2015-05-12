import sys

def number_pairs(numbers, sum):
	# print 'numbers are {}.'.format(numbers)
	# print 'sum is {}.'.format(sum)
	ret = []
	pr = ''
	for i in range(0, len(numbers)):
		# print 'i = {}'.format(numbers[i])
		for j in range(len(numbers)-1, -1, -1):
			# print '\tj = {}'.format(numbers[j])
			if numbers[i] + numbers[j] == sum and numbers[i] != numbers[j]:
				# print '\t\tfound {},{}'.format(numbers[i],numbers[j])
				if (numbers[i], numbers[j]) not in ret and numbers[i] < numbers[j]:
					ret.append((numbers[i],numbers[j]))
	if ret == []:
		pr = 'NULLL'
	else:
		for ans in ret:
			pr += '{},{};'.format(ans[0],ans[1]) 
	return pr[:-1]
	
if __name__ == '__main__':
	with open(sys.argv[1]) as f:
		for line in f:
			numbers = line.split(';')[0]
			numbers = [int(nr) for nr in numbers.split(',')]
			sum = int(line.split(';')[1])
			print number_pairs(numbers, sum)