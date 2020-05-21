#include <stdlib.h>
#include "utils/colors.c"
#include "models/owner/owner.c"

int main() {
    struct owner *_owner = NULL;
    aloca_owner(&_owner, 1);
    readOwner(_owner);
    puts(_owner->nome);
}