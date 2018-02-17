// some handy things I like

#include "handy.h"

// console output functions {{{
void
error (const char *msg, bool use_errno) {
    // print a red error
    if ( use_errno ) {
        char buf[512];
        snprintf(buf, sizeof(buf), RED "--> error:" RESET " %s", msg);
        perror(buf);
    } else {
        fprintf(stderr, RED "--> error:" RESET " %s.\n", msg);
    }
}

void
warn (const char *msg) {
    // print a yellow warning
    fprintf(stderr, YEL "--> warning:" RESET " %s!\n", msg);
}

void
msg (const char *msg) {
    // print a green message
    printf(GRN "--> " RESET "%s.\n", msg);
}
// }}}

// "safe" wrapper functions {{{
void *
smalloc (size_t nmemb, size_t size) {
    // safe malloc
    void *ptr = malloc(nmemb * size);

    if ( ptr == NULL ) {
        error("malloc", true);
        exit(EXIT_FAILURE);
    }
    
    return ptr;
}

void *
srealloc (void *ptr, size_t nmemb, size_t size) {
    // safe realloc
    void *new_ptr = realloc(ptr, nmemb * size);

    if ( ptr == NULL ) {
        error("realloc", true);
        exit(EXIT_FAILURE);
    }

    return new_ptr;
}

FILE *
sfopen (const char *pathname, const char *mode) {
    // safe file open
    FILE *fp = fopen(pathname, mode);

    if ( fp == NULL ) {
        error(pathname, true);
        exit(EXIT_FAILURE);
    }

    return fp;
}
// }}}

// vim: set ts=4 sw=4 fenc=utf-8 et:
