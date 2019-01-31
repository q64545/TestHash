"""
Test the performance of different hash method
methods:
	@hash_method0 tf.string_to_hash_bucket_fast
	@hash_method1 tf.string_to_hash_bucket_strong
	@hash_method2 pino_hash_op
	@hash_method2 basic_hash_op include BKDRHash,SDBMHash,RSHash,APHash,JSHash,DEKHash,FNVHash,DJBHash,DJB2Hash,PJWHash,ELFHash,JAVAHash
Considered:
	@time
	@conflict rate
"""
from __future__ import absolute_import  # absolute import
from __future__ import division         # accurate div
from __future__ import print_function   # new print func

from tensorflow.python.ops.gen_string_ops import string_to_hash_bucket_fast, string_to_hash_bucket_strong
from tensorflow.python.client.session import Session
from tensorflow.python.ops.array_ops import placeholder
from tensorflow.python.framework.dtypes import string as tf_string
from pino_hash_method import pino_hash_op
from basic_hash_methods import basic_hash_op
import argparse
import time


RANDOM_STRING_FILE = "random_str/ascii_random_str"
HASH_SIZE = 2**20
BATCH_SIZE = 200


def hash_method0(*args, **kwargs):
	return string_to_hash_bucket_fast(*args, **kwargs)

def hash_method1(*args, **kwargs):
	return string_to_hash_bucket_strong(key=[131,242356345], *args, **kwargs)

def hash_method2(*args, **kwargs):
	return pino_hash_op(*args, **kwargs)

def hash_method3(*args, **kwargs):
	return basic_hash_op(*args, **kwargs)

def test_hash(hash_func):
	# random_str = generate_random_ascii_str()
	random_str = []
	with open(RANDOM_STRING_FILE, 'rb') as f:
		for line in f:
			random_str.append(line.strip())
	nums = len(random_str)
	num_batches = int(nums / BATCH_SIZE)

	# result = hash_method(input=random_str, num_buckets=HASH_SIZE, name="test_hash")
	print("Num of random string is {}".format(len(random_str)))
	print("Hash size is {}".format(HASH_SIZE))
	print("HASH_SIZE / NUMS_RANDOM_STR is {}".format(HASH_SIZE / nums))

	x_input_str = placeholder(dtype=tf_string, shape=[None, ], name='input_str')
	result = hash_func(input=x_input_str, num_buckets=HASH_SIZE, name="test_hash")

	RESULT = []
	sess = Session()
	t0 = time.time()
	for i in xrange(num_batches):
		if i != num_batches - 1:
			batch_i = random_str[i*BATCH_SIZE: (i+1)*BATCH_SIZE]
		else:
			batch_i = random_str[i * BATCH_SIZE:]
		result_i = sess.run(result, feed_dict={x_input_str: batch_i})
		RESULT += result_i.tolist()

	cost_t = time.time() - t0
	conflict_nums = len(RESULT) - len(set(RESULT))
	print("Calculate time is {}s".format(cost_t))
	print("Conflict nums is {}".format(conflict_nums))
	print("Conflict rate is {}".format(conflict_nums / len(RESULT)))
	sess.close()



def main():
	parser = argparse.ArgumentParser()
	parser.add_argument('-f', '--hashFunc', type=int, default=0)
	args = parser.parse_args()
	hash_func_type = args.hashFunc
	hash_func = None
	if hash_func_type == 0:
		print("Using tf.string_to_hash_bucket_fast")
		hash_func = hash_method0
	elif hash_func_type == 1:
		print("Using tf.string_to_hash_bucket_strong")
		hash_func = hash_method1
	elif hash_func_type == 2:
		print("Using pino_hash_op")
		hash_func = hash_method2
	elif hash_func_type == 3:
		print("Using basic_hash_op")
		hash_func = hash_method3
	else:
		print("Hash function not found!")

	test_hash(hash_func)



if __name__ == "__main__":
	main()