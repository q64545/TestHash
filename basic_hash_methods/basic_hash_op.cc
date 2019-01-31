#include "tensorflow/core/framework/op.h"
#include "tensorflow/core/framework/shape_inference.h"
#include "tensorflow/core/framework/op_kernel.h"
#include <string>
#include "basic_hash.h"
#include "basic_hash_op.h"

using namespace tensorflow;


REGISTER_OP("BasicHashOp")
	.Attr("hash_func_name: string =''")
	.Attr("num_buckets: int = 1000")
    .Input("input_str: string")
    .Output("hash_value: int64");


class BasicHahOpKernel : public OpKernel {
public:
	explicit BasicHahOpKernel(OpKernelConstruction* context) : OpKernel(context) {
		OP_REQUIRES_OK(context, context->GetAttr("hash_func_name", &hash_func_name_));
		OP_REQUIRES_OK(context, context->GetAttr("num_buckets", &num_buckets_));
		// chose the right hash func
		// // debug: start
		// std::cout << "hash_func_name: " << hash_func_name_ << ", num_buckets: " << num_buckets_ << std::endl;
		// // debug: end
		char const* name_hash_f = hash_func_name_.c_str();
		switch(hash_(name_hash_f)) {
			case "BKDRHash"_hash: {
				// // debug: start
				// std::cout << "hash_func_ is BKDRHash" << std::endl;
				// // debug: end
				hash_func_ = basic_hash_ns::BKDRHash;
				break;
			}
			case "SDBMHash"_hash: {
				// // debug: start
				// std::cout << "hash_func_ is SDBMHash" << std::endl;
				// // debug: end
				hash_func_ = basic_hash_ns::SDBMHash;
				break;
			}
			case "RSHash"_hash: {
				// // debug: start
				// std::cout << "hash_func_ is RSHash" << std::endl;
				// // debug: end
				hash_func_ = basic_hash_ns::RSHash;
				break;
			}
			case "APHash"_hash: {
				// // debug: start
				// std::cout << "hash_func_ is APHash" << std::endl;
				// // debug: end
				hash_func_ = basic_hash_ns::APHash;
				break;
			}
			case "JSHash"_hash: {
				// // debug: start
				// std::cout << "hash_func_ is JSHash" << std::endl;
				// // debug: end
				hash_func_ = basic_hash_ns::JSHash;
				break;
			}
			case "DEKHash"_hash: {
				// // debug: start
				// std::cout << "hash_func_ is DEKHash" << std::endl;
				// // debug: end
				hash_func_ = basic_hash_ns::DEKHash;
				break;
			}
			case "FNVHash"_hash: {
				// // debug: start
				// std::cout << "hash_func_ is FNVHash" << std::endl;
				// // debug: end
				hash_func_ = basic_hash_ns::FNVHash;
				break;
			}
			case "DJBHash"_hash: {
				// // debug: start
				// std::cout << "hash_func_ is DJBHash" << std::endl;
				// // debug: end
				hash_func_ = basic_hash_ns::DJBHash;
				break;
			}
			case "DJB2Hash"_hash: {
				// // debug: start
				// std::cout << "hash_func_ is DJB2Hash" << std::endl;
				// // debug: end
				hash_func_ = basic_hash_ns::DJB2Hash;
				break;
			}
			case "PJWHash"_hash: {
				// // debug: start
				// std::cout << "hash_func_ is PJWHash" << std::endl;
				// // debug: end
				hash_func_ = basic_hash_ns::PJWHash;
				break;
			}
			case "ELFHash"_hash: {
				// // debug: start
				// std::cout << "hash_func_ is ELFHash" << std::endl;
				// // debug: end
				hash_func_ = basic_hash_ns::ELFHash;
				break;
			}
			case "JAVAHash"_hash: {
				// // debug: start
				// std::cout << "hash_func_ is JAVAHash" << std::endl;
				// // debug: end
				hash_func_ = basic_hash_ns::JAVAHash;
				break;
			}
			default: {
				hash_func_ = basic_hash_ns::BKDRHash;
			}
		}
	}

	void Compute(OpKernelContext* context) override {
		const Tensor& input_tensor = context->input(0);
		auto input = input_tensor.flat<string>();
		const int num_lines = input.size();

		Tensor* hash_value = NULL;
		OP_REQUIRES_OK(context, context->allocate_output(0, {num_lines}, &hash_value));
		auto hash_value_t = hash_value->flat<int64>();

		for (int i = 0; i < num_lines; ++i) {
			const std::string& input_t = input(i);
			const char* head = input_t.c_str();
			size_t hash_value = hash_func_(head);
			hash_value_t(i) = hash_value % num_buckets_;
		}
	}
private:
	std::string hash_func_name_;
	size_t (*hash_func_)(const char* );
	int num_buckets_;

	~BasicHahOpKernel() override {}
};

REGISTER_KERNEL_BUILDER(Name("BasicHashOp").Device(DEVICE_CPU), BasicHahOpKernel);


















