#ifndef VIS_CWRAPPER_H
#define VIS_CWRAPPER_H

/* Gotta make it C89 compat */


/*
 * How to use this lib in C?
 * ---
 *  1). First compile this lib into an object
 *  (g++ -c parser.cpp -o parser.o)
 *  and
 *  (g++ -c cwrapper.cpp -o cwrapper.o)
 *  2). Then include this wrapper into your C code (#include "cwrapper.h")
 *  3). Use code in your C code
 *  4). Compile with C compiler (gcc -c main.c -o main.o)
 *  5). Compile again but with C++ compiler
 *  (g++ main.o cwrapper.o parser.h -o program)
 *  4). Profit
 * ---
 *  Or, just use CMake (:
 * ---
 *  If on arduino...
 */

#ifdef __cplusplus
extern "C" {
/* Declare a struct for C to use */
typedef struct VISParser VISParser;

/* Gets class as struct */
VISParser *getVISLParser();
void VISOpenFile(VISParser *parser, char *filename);
void VISCloseFile(VISParser *parser);
void delVISParser(VISParser *parser);
}
#endif

#endif /* VIS_CWRAPPER_H */
