#pragma once

#include <cstdarg>>
#include <stdarg.h>

#define RESULT_MAX_MESSAGE_SIZE 16000

#define RESULT_SUCCESS 0
#define RESULT_ABORT 1
#define RESULT_FAILED 2
#define RESULT_FATAL 3

class Result{
public:
	//enum class ResultStatusEnum { SUCCESS, ABORT, FAILED, FATAL};
	Result(int result_status) : status_(result_status) {}
	Result(int result_status, const char* format, ...);
	int getResult() { return status_; }
	string getMessage() { return message_; }

private:
	int status_;
	string message_;
}