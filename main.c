#include <stdlib.h>
#include "utils/colors.c"
#include "models/owner/owner.c"

int main() {
    struct owner *_owner = NULL;
    alocaOwner(1, &_owner);
    readOwner(_owner);
    puts(_owner->nome);
    printf("Oi");
}