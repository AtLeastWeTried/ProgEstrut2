#include <stdlib.h>
#include <stdio.h>
#include "models/owner/owner.c"

int main() {
    struct owner *_owner = NULL;
    aloca_owner(&_owner, 1);
    _owner->sAddress = stdReadAddress();
    _owner->sCasa = stdReadHouse();
    stdReadOwner(_owner);
}