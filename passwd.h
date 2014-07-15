#ifndef PASSWD_H
#define PASSWD_H

#include <unistd.h>     // for uid_t and gid_t

struct passwd {
    char *pw_name;      // username
    char *pw_passwd;    // hashed password
    uid_t pw_uid;       // user-id
    gid_t pw_gid;       // group-id
    char *pw_gecos;     // Comment
    char *pw_dir;       // Home Directory
    char *pw_shell;     // Login shell
};

#endif
