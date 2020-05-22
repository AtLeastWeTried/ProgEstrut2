#include <stdlib.h>
#include <stdio.h>
#include "models/owner/owner.c"

int main() {
    struct owner _owner = stdReadOwner();
    writeOwner(_owner);
    struct owner newOwner = readOwner();
    stdWriteOwner(newOwner);
}