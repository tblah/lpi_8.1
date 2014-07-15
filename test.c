#include <stdlib.h>		// for exit
#include "getpwnam.h"   // defines getpwnam
#include <pwd.h>        // defines passwd struct
#include <stdio.h>      // printf

int main(int argc, char* argv[])
{
    // test that the user root is found and that it has a user-id of 0.
    char reportString[] = "Testing that the user root is found with a user-id of 0...";

    struct passwd *root = getpwnam("root");
    if (root == NULL) {
        printf("%sFAILED\n", reportString); 
        return EXIT_FAILURE; 
    } 
    
    if (root->pw_uid == 0) 
        printf("%sPASSED\n", reportString);
    else {
        printf("%sFAILED\n", reportString);
        return EXIT_FAILURE;
    }

	return EXIT_SUCCESS;
}
