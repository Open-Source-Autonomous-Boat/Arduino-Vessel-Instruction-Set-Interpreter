#ifndef VIS_CWRAPPER_H
#define VIS_CWRAPPER_H
#include "VISParser.h"

/* Gotta make it C89 compat */

/*
 * How to use this lib in C?
 * ---
 *  1). First compile this lib into a static library
 *  (make makedir)
 *  (make)
 *  and
 *  2). Then include this wrapper into your C code (#include "VISCWrapper.h")
 *  3). Use code in your C code
 *  5). Compile
 *  (gcc main.c -I<folder to vis lib> -libVIS -o main)
 *  4). Profit
 * ---
 *  Or, just use CMake (:
 * ---
 *  If on arduino...
 */

#ifdef __cplusplus
extern "C" {
/* Declare a struct for C to use */

/* Gets class as struct */
extern VISParser *getVISParser();
/*
 * C wrapper to VISParser::OpenFile(std::string path)
 * @param[in,out] parser The C compat(?) struct
 * @param[in] path The path to file
 */
extern void VISOpenFile(VISParser *parser, char *path);
/*
 * C wrapper to VISParser::CloseFile()
 */
extern void VISCloseFile(VISParser *parser);
/*
 * C function to delete struct/class
 * @param[in] parser Deletes it
 */
extern void delVISParser(VISParser *parser);
}
#endif

#endif /* VIS_CWRAPPER_H */
