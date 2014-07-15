#ifndef GETPWNAM_H
#define GETPWNAM_H

#include <pwd.h>     // defines the structure passwd

struct passwd *getpwnam(const char *name);

#endif
