#include "hash.h"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[]) {
	string a(argv[2]);
	int seed = atoi(argv[1]);

	const char* head = a.c_str();
	int len = a.length();
	cout << "a: " << a << endl;
	cout << "seed: " << seed << endl;
	cout << "head: " << *head << endl;
	cout << "len: " << len << endl;
	size_t hash_v = test_hash::uniform_hash(head, len, seed);
	cout << "hash_value: " << hash_v << endl;
	return 0;
}
