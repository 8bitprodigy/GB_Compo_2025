/*
	defs.h

	#defines for constants and macros go here
*/
#ifndef DEFS_H
	#define DEFS_H

	#define VEC2( _x, _y) ((Vec2 ){.x = (_x), .y = (_y)})
	#define UVEC2(_x, _y) ((UVec2){.x = (_x), .y = (_y)})

	#define GET_BUTTON_AXIS( Positive, Negative ) ((int8)(Positive) - (int8)(Negative))
	#define GET_BUTTON_VEC2( X_Positive, X_Negative, Y_Positive, Y_Negative ) \
		(Vec2){ \
			.x = GET_BUTTON_AXIS( X_Positive, X_Negative ), \
			.y = GET_BUTTON_AXIS( Y_Positive, Y_Negative )  \
		}
		
	/* Minimum value */
	#define MIN( a, b ) (((a)<(b))?(a):(b))
	/* Maximum value */
	#define MAX( a, b ) (((b)<(a))?(a):(b))
	/* Clamp value to range */
	#define CLAMP( value, min, max ) ((value)<(min)?(min):((value)>(max)?(max):(value)))
	/* Get sign between two numbers */
	#define SIGN_BETWEEN( a, b ) (((a)<(b))-((b)<(a)))
	/* Check if a number is between two others */
	#define IS_IN_BOUNDS( a, b, c ) ((b)<=(a)&&(a)<=(c))


	/* Global constants */
	#define SCREEN_WIDTH_IN_TILES  20
	#define SCREEN_HEIGHT_IN_TILES 18
	
	#define MAX_LEVEL_SIZE  255
	#define SECTOR_SIZE_INC 32
	#define MAX_NUM_SECTORS 32
	#define MIN_SECTOR_SIZE 8
	#define MIN_ROOM_SIZE   4
	

#endif /* DEFS_H */
