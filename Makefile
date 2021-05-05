
check_memory_vector: build_exist test_vector
	cd ./linear_data_structures/vector/build && valgrind --leak-check=full --leak-resolution=med -s ./test

build_exist:
	if [ ! -d "./linear_data_structures/vector/build" ]; then mkdir "./linear_data_structures/vector/build"; fi

test_vector: build_exist
	cd linear_data_structures/vector && make test && ./build/test

check_source_file:
	cppcheck --suppress=missingIncludeSystem -q --enable=all --inconclusive --check-config ./linear_data_structures .

format:
	./.make_format.sh

docs: FORCE
	doxygen Doxyfile

FORCE:
