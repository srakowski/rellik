#ifndef _STATUS_H_
#define _STATUS_H_

typedef enum 
{
	RELLIK_STATUS_INVALID = 0,
	RELLIK_STATUS_SUCCESS
} RellikStatus;

#define getRellikStatusMsg(code) ((code) == RELLIK_STATUS_SUCCESS ? "success" : \
	"undefined status code: " #code)

#endif
