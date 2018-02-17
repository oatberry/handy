#ifndef HANDY_H
#define HANDY_H

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED   "\x1B[1;31m"
#define GRN   "\x1B[1;32m"
#define YEL   "\x1B[1;33m"
#define BLU   "\x1B[1;34m"
#define MAG   "\x1B[1;35m"
#define CYN   "\x1B[1;36m"
#define WHT   "\x1B[1;37m"
#define RESET "\x1B[0m"


void error  (const char *msg, bool use_errno);
void warn   (const char *msg);
void msg    (const char *msg);

void *smalloc  (size_t nmemb, size_t size);
void *srealloc (void *ptr, size_t nmemb, size_t size);
FILE *sfopen   (const char *pathname, const char *mode);

#endif

// vim: set ts=4 sw=4 fenc=utf-8 et:
