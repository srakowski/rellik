#ifndef _STATUS_H_
#define _STATUS_H_

typedef enum 
{
	RLK_INVALID = 0,
	RLK_SUCCESS,
	RLK_SDL_FAILURE
} RellikStatus;

#define getRellikStatusMsg(code) ((code) == RLK_SUCCESS ? "success" : \
	(code) == RLK_SDL_FAILURE ? "an SDL function failed" : \
	"undefined status code: " #code)

#endif
