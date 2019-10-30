#ifndef __RAPTOR_UTIL_LOG__
#define __RAPTOR_UTIL_LOG__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum raptor_log_level {
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_ERROR
} raptor_log_level;


const char* raptor_log_level_string(raptor_log_level s);
void raptor_log_message(const char* file, int line,
                        raptor_log_level s, const char* message);

int raptor_should_log(raptor_log_level s);

void raptor_log_init(void);
void raptor_set_log_level(raptor_log_level s);


typedef struct raptor_log_func_args {
    const char* file;
    int line;
    raptor_log_level level;
    const char* message;
} raptor_log_func_args;

typedef void (*raptor_log_func)(raptor_log_func_args*);
void raptor_set_log_function(raptor_log_func func);
void raptor_log_restore_default();

#ifdef __cplusplus
}
#endif

#endif  // __RAPTOR_UTIL_LOG__
