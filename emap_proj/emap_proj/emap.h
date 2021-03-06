#ifndef _EMAP_H_
#define _EMAP_H_

#include <stdint.h>
#include "list.h"

//-----------------------------------------------------
// DATA STRUCTURE
//
// example :
// 0019   0000 0852    000B    0000 00B6   A3B1...  
//  (1)      (2)        (3)       (4)      (5)
//
// (1) Number of bytes defining the road (self included), cannot be under 12
// (2) LinkID of the road
// (3) Sizeof the roadname (can be 0 if the road doesn't have a name)
// (4) On the 4 following bytes, only the last byte is important, here B6
// 1011 0110
// The first bit is a flag name, to determine whether the road has a name
// the 3 following bits define the number of crossings
// the last 4 bytes are the IF class
// (5) Name (if any)
//-----------------------------------------------------

typedef struct road_s
{
	char		*name;
	uint16_t	length; // Can be 0
	uint32_t	link_id;
	uint8_t		if_class; // The 4 first bits will always be equal to 0
	uint8_t		crossings; // The 4 first bits will always be equal to 0
} road_t;

// COMPARISON FUNCTIONS
// Those functions are used when sorting the road list
int			cmp_link_id(void *data1, void *data2);
int			cmp_if_class(void *data1, void *data2);
int			cmp_crossings(void *data1, void *data2);
int			cmp_name(void *data1, void *data2);

// SEARCH FUNCTIONS
bool search_name(void *data, void *param);
bool search_link_id(void *data, void *param);
bool search_if_class(void *data, void *param);
bool search_crossings(void *data, void *param);
void		process_results(List *l);
void		log_resutls(List *l, const char *filename);

// MISC FUNCTIONS
void		road_print(void *data);


#endif // _EMAP_H_