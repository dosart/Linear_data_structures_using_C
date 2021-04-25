format:
	./.make_format.sh

docs: FORCE
	doxygen Doxyfile

FORCE:

SOURCE_DIRECTORY = ./linear_data_structures
BUILD_DIRECTORY = .

check_source_file:
	cppcheck --suppress=missingIncludeSystem -q --enable=all --inconclusive --check-config $(SOURCE_DIRECTORY) $(BUILD_DIRECTORY)
