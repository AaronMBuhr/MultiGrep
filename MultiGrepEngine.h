#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "Result.h"

using namespace std;

class MultiGrepEngine {
public: 
	MultiGrepEngine(size_t file_buffer_size);
	Result addSearchPhrase(string phrase);
	Result searchFile(string filename, iostream output_stream);

private:
	size_t file_buffer_size_;
	unique_ptr<char[]> file_buffer_;
	vector<string> searchPhrases;
	vector<int> matched_position_;
};