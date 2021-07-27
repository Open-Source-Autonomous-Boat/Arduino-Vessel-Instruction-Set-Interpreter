#ifndef VIS_CWRAPPER_H
#define VIS_CWRAPPER_H
#include <string.h>

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
#endif
/* Declare a struct for C to use */

/* Gets parser class as struct */
VISParser *getVISParser();

/*
 * Gets file class as struct
 * @param[in] a_path: Path to file
 */
VISFile *getVISFile(char *a_path);
/*
 * C wrapper to VISParser::OpenFile(std::string path)
 * @param[in,out] a_parser: The C compat(?) struct
 * @param[in] a_path: The path to file
 */
void VISParserOpenFile(VISParser *a_parser, VISFile *a_file);
/*
 * C wrapper to VISParser::CloseFile()
 * @param[in] a_parser: The C compat(?) struct
 */
void VISParserCloseFile(VISParser *a_parser);
/*
 * C function to delete struct/class
 * @param[in] a_parser: The C compat(?) struct
 */
void delVISParser(VISParser *a_parser);

/*
 * Gets file object, C can do this right?
 * @param[in] a_file: The C compat(?) struct
 */
void *VISFileGetObject(VISFile *a_file);

/*
 * Gets file path
 * @param[in] a_file: The C compat(?) struct
 */
char *VISFileGetPath(VISFile *a_file);
#ifdef __cplusplus
}
#endif
#endif /* VIS_CWRAPPER_H */
