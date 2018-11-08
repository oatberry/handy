// some handy things I like

#include "handy.h"

void *
smalloc (size_t nmemb, size_t size) {

    void *ptr = calloc(nmemb, size);

    if ( ptr == NULL ) {
        error(1, errno, "malloc faled");
    }
    
    return ptr;
}

void *
srealloc (void *ptr, size_t nmemb, size_t size) {

    void *new_ptr = realloc(ptr, nmemb * size);

    if ( ptr == NULL ) {
        error(1, errno, "realloc failed");
    }

    return new_ptr;
}

FILE *
sfopen (const char *pathname, const char *mode) {
    // safe file open
    FILE *fp = fopen(pathname, mode);

    if ( fp == NULL ) {
        error(1, errno, "failed to open %s", pathname);
    }

    return fp;
}

// vim: set ts=4 sw=4 et:
