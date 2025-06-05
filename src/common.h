/*
	common.h

	Global definitions/forward declarations such as variables, constants, and types go here
*/
#ifndef COMMON_H
	#define COMMON_H

	#include <gb/gb.h>
	#include <rand.h>
	#include <stdbool.h>
	#include <stdint.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	
	#include "defs.h"


/****************
	T Y P E S
****************/

typedef int8_t   int8;
typedef int16_t  int16;
typedef uint8_t  byte;
typedef uint16_t word;


enum
{
	X,
	Y,
	WIDTH,
	HEIGHT,
};

enum
{
	POSITION,
	DIMENSION
};

enum
{
	LEFT,
	RIGHT
};


typedef union 
{
	int8 v[2];
	struct {
		int8 
			x,
			y;
	};
	struct {
		int8 
			w,
			h;
	};
}
Vec2;

typedef union 
{
	byte v[2];
	struct {
		byte 
			x,
			y;
	};
	struct {
		byte 
			w,
			h;
	};
}
UVec2;

typedef union
{
	byte  r[4];
	UVec2 v[2];
	struct {
		union {
			byte  pos[2];
			UVec2 position;
			struct {
				byte 
					x,
					y;
			};
			struct {
				byte
					x1,
					y1;
			};
		};
		union {
			byte  dim[2];
			UVec2 dimension;
			struct {
				byte 
					w,
					h;
			};
			UVec2 position2;
			struct {
				byte
					x2,
					y2;
			};
		};
	};
}
Rectangle;


typedef struct GameState GameState;
typedef struct Actor     Actor;


/********************
	M E T H O D S
********************/

inline byte
randRange(byte Min, byte Max)
{
	byte difference = Max - Min;
	return (rand() % difference) + Min;
} /* randRange */

inline bool
isInRect(byte x, byte y, Rectangle *r) {
	if (r==NULL) return false;
	return IS_IN_BOUNDS(x, r->x1, r->x2)
		&& IS_IN_BOUNDS(y, r->y1, r->y2);
} /* isInRect */


#endif /* COMMON_H */
