#pragma once

#include <errno.h>
#include <error.h>
#include <stdio.h>
#include <stdlib.h>

void *smalloc  (size_t nmemb, size_t size);
void *srealloc (void *ptr, size_t nmemb, size_t size);
FILE *sfopen   (const char *pathname, const char *mode);

// vim: set ts=4 sw=4 et:
