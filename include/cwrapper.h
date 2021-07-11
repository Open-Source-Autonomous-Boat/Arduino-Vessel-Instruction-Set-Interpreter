#ifndef VIS_CWRAPPER_H
#define VIS_CWRAPPER_H

/* Gotta make it C89 compat */

#ifdef __cplusplus
extern "C" {
/* Declare a struct for C to use */
typedef struct VISLParser VISLParser;

/* Gets class as struct */
VISLParser *getVISLParser();
void VISLOpenFile(VISLParser *parser, char *filename);
void VISLCloseFile(VISLParser *parser);
}
#endif

#endif /* VIS_CWRAPPER_H */
/* vim: ft=c */
