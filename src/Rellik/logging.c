#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include "logging.h"

void _log(const char *module, const int line_number, LoggingLevel level, const char *format, ...)
{
	time_t rawtime;
	struct tm *timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	char buffer[64] = { '\0' };
	strftime(buffer, sizeof(buffer) - 1, "%Y-%m-%d %H:%M:%S", timeinfo);

	va_list vargs;
	va_start(vargs, format);
		
	const char *file_name = strrchr(module, '\\');
	if (!file_name)
		file_name = module;
	else
		file_name += 1;

	printf("%s|%s|%d|%s|", buffer, file_name, line_number,
		level == LOGGING_LEVEL_TRACE ? "TRACE" :
		level == LOGGING_LEVEL_DEBUG ? "DEBUG" :
		level == LOGGING_LEVEL_INFO ? "INFO" :
		level == LOGGING_LEVEL_WARNING ? "WARNING" :
		level == LOGGING_LEVEL_ERROR ? "ERROR" :
		level == LOGGING_LEVEL_FATAL ? "FATAL" :
		"LOG");

	vprintf(format, vargs);
	
	printf("\n");

	va_end(vargs);
}

