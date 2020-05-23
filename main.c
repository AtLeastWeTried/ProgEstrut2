#include <stdlib.h>
#include <stdio.h>
#include "models/owner/owner.c"

int main() {
    int i;
    struct owner _owner = stdWriteOwner();
    writeOwner(_owner);
    printf("%d", countOwners());
    for (i = 1; i <= countOwners(); i++) {
        printf("oi");
        struct owner readingOwner = readOwner(i);
        stdReadOwner(readingOwner);
    }
}