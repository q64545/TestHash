# -*- coding:utf-8 -*-
from __future__ import absolute_import  # absolute import
from __future__ import division         # accurate div
from __future__ import print_function   # new print func


from tensorflow.python.framework.load_library import load_op_library
from tensorflow.python.framework import ops
from tensorflow.python.client.session import Session

so_file = "pino_hash_method/pino_hash_op.so"
my_add_module = load_op_library(so_file)

def pino_hash_op(input, num_buckets, name='test'):
	with ops.name_scope(name, "pino_hash_op", [input]):
		return my_add_module.pino_hash_op(input, num_buckets=num_buckets)

# def unit_test():
# 	input_raw = ["sfwefsdfsdfsdfsd"]*100
# 	num_buckets = 2**29
# 	hash_value = pino_hash_op(input_raw, num_buckets, 'test')
# 	sess = Session()
# 	print(sess.run(hash_value))
#
#
# if __name__ == "__main__":
# 	unit_test()