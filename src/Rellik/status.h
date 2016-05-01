#ifndef _STATUS_H_
#define _STATUS_H_

typedef enum 
{
	RLK_INVALID = 0,
	RLK_SUCCESS,
	RLK_SDL_FAILURE,
	RLK_CREATE_FAILURE
} RellikStatus;

#define getRellikStatusMsg(code) ((code) == RLK_SUCCESS ? "success" : \
	(code) == RLK_SDL_FAILURE ? "an SDL function failed" : \
	(code) == RLK_CREATE_FAILURE ? "failed to create object" : \
	"undefined status code: " #code)

#endif
