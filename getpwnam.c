#include <pwd.h>     // definition of the passwd struct, getpwent, setpwent, endpwent
#include <string.h>  // for strcmp

struct passwd *getpwnam(const char *name) {
    static struct passwd *ret;

    setpwent();  // make sure we are at the beginning of the passwd file
    
    while ((ret = getpwent()) != NULL) { // cycle through all lines of the passwd file until EOF or error
        if (strcmp(ret->pw_name, name) == 0) { // check to see if this is the one we are looking for
            endpwent(); // close passwd file
            return ret;
        }
    }

    return NULL;    // if we get out of the loop then we have either not found the passwd entry or we have experienced an error
}
