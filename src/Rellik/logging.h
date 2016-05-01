#ifndef _LOGGING_H_
#define _LOGGING_H_

#include <stdarg.h>

typedef enum {
	LOGGING_LEVEL_INVALID = 0,
	LOGGING_LEVEL_TRACE,
	LOGGING_LEVEL_DEBUG,
	LOGGING_LEVEL_INFO,
	LOGGING_LEVEL_WARNING,
	LOGGING_LEVEL_ERROR,
	LOGGING_LEVEL_FATAL
} LoggingLevel;

void _log(const char *module, const int line_number, LoggingLevel level, const char *format, ...);

#define tlog(format, ...) _log(__FILE__, __LINE__, LOGGING_LEVEL_TRACE, format, __VA_ARGS__);

#define dlog(format, ...) _log(__FILE__, __LINE__, LOGGING_LEVEL_DEBUG, format, __VA_ARGS__);

#define ilog(format, ...) _log(__FILE__, __LINE__, LOGGING_LEVEL_INFO, format, __VA_ARGS__);

#define wlog(format, ...) _log(__FILE__, __LINE__, LOGGING_LEVEL_WARNING, format, __VA_ARGS__);

#define elog(format, ...) _log(__FILE__, __LINE__, LOGGING_LEVEL_ERROR, format, __VA_ARGS__);

#define flog(format, ...) _log(__FILE__, __LINE__, LOGGING_LEVEL_FATAL, format, __VA_ARGS__);

#endif
