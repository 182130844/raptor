#include <stdarg.h>
#include <stdlib.h>
#include "log.h"
#include "alloc.h"

void raptor_default_log(raptor_log_func_args* args);

// TODO: add atomic
static intptr_t g_log_func = (intptr_t)raptor_default_log;
static intptr_t g_min_level_to_print = -1;

const char* raptor_log_level_string(raptor_log_level s) {
    switch (s) {
    case LOG_LEVEL_DEBUG:
        return "D";
    case LOG_LEVEL_INFO:
        return "I";
    case LOG_LEVEL_ERROR:
        return "E";
    }
    return "UNKNOWN";
}

void raptor_log_message(const char* file, int line,
                        raptor_log_level s, const char* message) {
    raptor_log_func_args args;
    memset(&args, 0, sizeof(args));
    args.file = file;
    args.line = line;
    args.level = s;
    args.message = message;
    ((raptor_log_func)g_log_func)(&args);
}

int raptor_should_log(raptor_log_level s) {
    if ((intptr_t)s >= g_min_level_to_print) {
        return 1;
    }
    return 0;
}

void raptor_log_init(void) {
    // get info from env
    char* level = nullptr;
    raptor_getenv("RAPTOR_VERBOSITY", &level);

    if (level != nullptr) {
        if (strcmp(level, "DEBUG") == 0) {
            g_min_level_to_print = (intptr_t)LOG_LEVEL_DEBUG;
        } else if (strcmp(level, "INFO") == 0) {
            g_min_level_to_print = (intptr_t)LOG_LEVEL_INFO;
        } else if (strcmp(level, "ERROR") == 0) {
            g_min_level_to_print = (intptr_t)LOG_LEVEL_ERROR;
        }
        raptor_free(level);
    }
    if ((intptr_t)g_min_level_to_print == -1) {
        g_min_level_to_print = (intptr_t)LOG_LEVEL_ERROR;
    }
}

void raptor_set_log_level(raptor_log_level s) {
    g_min_level_to_print = s;
}

void raptor_set_log_function(raptor_log_func func) {
    g_log_func = func;
}

void raptor_log_restore_default() {
    g_log_func = (intptr_t)raptor_default_log;
}
