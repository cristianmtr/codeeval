import sys
import string

def missing_letters(text):
	# print 'text = {}'.format(text)
	alphabet = list(string.ascii_lowercase)
	ret = ''
	for char in alphabet:
		if char not in text:
			ret += char
	if ret == '':
		return 'NULL'
	else:
		return ret

with open(sys.argv[1]) as f:
	for line in f:
		if line[len(line)-1] == '\n':
			print missing_letters(line[:-1].lower())
		else:
			print missing_letters(line.lower())