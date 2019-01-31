#include "tensorflow/core/framework/op.h"
#include "tensorflow/core/framework/shape_inference.h"
#include "tensorflow/core/framework/op_kernel.h"
#include "hash.h"

using namespace tensorflow;

REGISTER_OP("PinoHashOp")
    .Input("input_str: string")
    .Attr("num_buckets: int = 1000")
    .Output("hash_value: int64");


class PinoHashOpKernel : public OpKernel {
public:
	explicit PinoHashOpKernel(OpKernelConstruction* context) : OpKernel(context) {
		OP_REQUIRES_OK(context, context->GetAttr("num_buckets", &num_buckets_));
		base_hash_seed = 1;
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
			int len_i = input_t.length();
			const char* head = input_t.c_str();
			size_t hash_value = test_hash::uniform_hash(head, len_i, base_hash_seed);
			hash_value_t(i) = hash_value % num_buckets_;
		}
	}
private:
	int base_hash_seed;
	int num_buckets_;

	~PinoHashOpKernel() override {}
};
REGISTER_KERNEL_BUILDER(Name("PinoHashOp").Device(DEVICE_CPU), PinoHashOpKernel);

