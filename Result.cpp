#include "Result.h"
#include <stdio.h>
#include <string>

using namespace std;

Result::Result(ResultStatusEnum result_status, const char* format, ...) : status_(result_status) { 
	char msg_buf[RESULT_MAX_MESSAGE_SIZE];
	va_list args;
	va_start(args, format);
	int num_chars = vsnprintf_s(
		msg_buf,
		sizeof(msg_buf),
		_TRUNCATE,
		format,
		args
	);
	va_end(args);

	message_ = string(const_cast<char*>(msg_buf));
}

