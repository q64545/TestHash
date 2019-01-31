import random
import argparse
import os


if not os.path.exists("random_str"):
	os.mkdir("random_str")

MAX_LEN_STR = 24
MAX_ITERATION = 10000000



def generate_random_ascii_str(codeType="ascii"):
	RAND_STR = []
	for i in xrange(MAX_ITERATION):
		rand_len = random.randint(1, MAX_LEN_STR)
		rand_str = ''.join([chr(random.randint(32, 126)) for i in xrange(rand_len)])
		RAND_STR.append(rand_str)
	RAND_STR = list(set(RAND_STR))
	print("Generated {} unique strings".format(len(RAND_STR)))
	with open("random_str/" + codeType + "_random_str", "w") as f:
		for line in RAND_STR:
			f.write(line + '\n')



def main():
	parser = argparse.ArgumentParser()
	parser.add_argument('-c', '--codeType', type=str, default="ascii")
	args = parser.parse_args()
	codeType = args.codeType
	if codeType == "ascii":
		generate_random_ascii_str(codeType)

if __name__ == "__main__":
	main()