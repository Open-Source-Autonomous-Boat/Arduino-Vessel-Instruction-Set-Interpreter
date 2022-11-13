#define VISL_LINE_ENDING ';'
#define VISL_COMMENT '#'

/* Export to LIB */
#if defined(_WIN32 ) || defined(__CYGWIN__)
    #if defined(_MSC_VER)
    #define EXPORT __declspec(dllexport) 
    #elif defined(__GNUC__)
    #define EXPORT __attribute__(dllexport)
    #endif
#else
    #define EXPORT __attribute__((visibility("default"))) __attribute__((used))
#endif