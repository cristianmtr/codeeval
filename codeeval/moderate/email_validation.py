import sys
import string

def is_email(text):
	alpha_chars = list(string.ascii_lowercase)
	# print 'email = {}'.format(text)
	not_allowed = ['@', '"', '\\', '<', '>', ' ']
	for el in not_allowed:
		if el in text[:text.rfind('@')]:
			# print '\tfound {}'.format(el)
			return 'false'
	if text.find('@') in [0, -1, len(text)-1]:
		# print '\tfound {} at {}'.format('@', text.find('@'))
		return 'false'
		if text.rfind('.') in [0, -1, len(text)-1]:
			# print '\tfound {} at {}.'.format('.', text.rfind('.'))
			return 'false'
	if text.rfind('.') < text.find('@'):	
		# print '\tfound @ after last . '
		return 'false'
	for el in text[text.rfind('.')+1:]:
		if el not in alpha_chars:
			# print '\tfound not alpha_chars in dot section'
			return 'false'
	return 'true'

if __name__ == '__main__':
	with open(sys.argv[1]) as f:
		for line in f:
			print is_email(line[:-1])