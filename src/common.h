/*
	common.h

	Global definitions/forward declarations such as variables, constants, and types go here
*/
#ifndef COMMON_H
	#define COMMON_H

	#include <gb/gb.h>
	#include <rand.h>
	#include <stdint.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	
	#include "defs.h"


typedef int8_t   int8;
typedef int16_t  int16;
typedef uint8_t  byte;
typedef uint16_t word;


enum
{
	X,
	Y,
};

enum
{
	WIDTH,
	HEIGHT,
};


typedef union 
{
	int8 v[2];
	struct {
		int8 x;
		int8 y;
	};
	struct {
		int8 w;
		int8 h;
	};
}
Vec2;

typedef union 
{
	byte v[2];
	struct {
		byte x;
		byte y;
	};
	struct {
		byte w;
		byte h;
	};
}
UVec2;


typedef struct GameState GameState;
typedef struct Actor     Actor;


#endif
