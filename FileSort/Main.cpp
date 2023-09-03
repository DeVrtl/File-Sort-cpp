#include <iostream>
#include <string>
#include <fstream>
#include "storage.h"
#include "sort.h"

namespace 
{
	enum Arguments
	{
		SORT_ARGUMENT = 1,
		SORT_MODE,
		INPUT_FILE_NAME,
		OUTPUT_FILE_NAME,

		COUNT
	};
}

int main(int argc, char* argv[])
{
	if (argc <= COUNT)
	{
		return EXIT_FAILURE;
	}

	const char sortArgument = argv[SORT_ARGUMENT][SORT_ARGUMENT];
	const char sortModeArgument = argv[SORT_ARGUMENT][SORT_MODE];

	std::string inputFileName = argv[INPUT_FILE_NAME];
	std::string outputFileName = argv[OUTPUT_FILE_NAME];

	storage::Storage* content = storage::Allocate(1024);
	SortMode sortMode;

	switch (sortModeArgument)
	{
	case 'a':
		sortMode = ASC;
		break;

	case 'd':
		sortMode = DESC;
		break;

	default:
		std::cout << "Wrong type" << std::endl;
		storage::Free(content);
		return EXIT_FAILURE;
	}

	switch (sortArgument)
	{
	case 's':

		break;

	case 'i':

		break;

	case 'f':
		
		break;

	default:
		std::cout << "Wrong type" << std::endl;
		storage::Free(content);
		return EXIT_FAILURE;
	}

	std::ofstream outputFile(outputFileName);
	if (!outputFile)
	{
		std::cout << "Failed to open file" << std::endl;
		storage::Free(content);
		return EXIT_FAILURE;
	}

	for (int i = 0; i < content->count; ++i)
	{
		outputFile << content->pointerChars[i] << std::endl;
	}

	outputFile.close();


	storage::Free(content);

	return EXIT_SUCCESS;
}