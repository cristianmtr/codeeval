import sys

def reverse(nr):
	nr = str(nr)
	return int(nr[::-1])

def reverse_and_add(nr):
	i = 1
	while reverse(nr) + nr !=  reverse(reverse(nr) + nr):
		i += 1
		nr += reverse(nr)
		# print 'i = {}; nr = {}'.format(i, nr)
	return '{} {}'.format(i, reverse(nr) + nr)

if __name__ == '__main__':
	with open(sys.argv[1]) as f:
		for line in f:
			nr = int(line)
			print reverse_and_add(nr)