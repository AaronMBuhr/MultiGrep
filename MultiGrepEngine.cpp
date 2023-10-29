#include "MultiGrepEngine.h"


MultiGrepEngine::MultiGrepEngine(size_t file_buffer_size) {
	file_buffer_size_ = file_buffer_size;
	file_buffer_ = make_unique<char[]>(file_buffer_size);
}

Result MultiGrepEngine::addSearchPhrase(string phrase) {
	matched_position_.push_back(0);
	searchPhrases.push_back(phrase);
	return Result(RESULT_SUCCESS);
}

Result MultiGrepEngine::searchFile(string filename, iostream output_stream) {

	FILE* input_file;
	fopen_s(&input_file, filename.c_str(), "r");
	if (!input_file) {
		return Result(RESULT_ABORT, "could not open file %s", filename.c_str());
	}
	size_t bytes_read;
	for (fread(file_buffer_.get(), sizeof(char), file_buffer_size_, input_file); bytes_read > 0;
		fread(file_buffer_.get(), sizeof(char), file_buffer_size_, input_file)) {
		for (int p = 0; p < bytes_read; ++p) {
			char c = file_buffer_[p];
			for (string phrase : searchPhrases) {

			}
		}
	}
}
