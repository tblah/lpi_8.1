#include <pwd.h>     // definition of th passwd struct

struct passwd *getpwnam(const char *name) {
    static struct passwd *ret;

    // do stuff

    return ret;
}
