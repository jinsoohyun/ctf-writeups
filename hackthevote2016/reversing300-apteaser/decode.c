#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main() {
    uint32_t i, j, ta, tb;
    uint32_t seeds[] = {
        1460329071, 1460329074, 1460329077, 1460329080, 1460329084, 1460329084, 1460329087, 1460329090, 1460329091, 1460329093, 1460329096, 1460329100, 1460329102, 1460329105, 1460329109, 1460329111,
        1460329112, 1460329114, 1460329115, 1460329117, 1460329121, 1460329121, 1460329123, 1460329125, 1460329128, 1460329131, 1460329133, 1460329135, 1460329136, 1460329140, 1460329141, 1460329142,
        1460329145, 1460329148, 1460329150, 1460329154, 1460329154, 1460329154, 1460329158, 1460329158, 1460329160, 1460329161, 1460329161, 1460329165, 1460329165, 1460329167, 1460329168, 1460329170,
        1460329171, 1460329172, 1460329173};

    FILE* f;
    FILE* of;
    uint32_t buf;
    
    f = fopen("leakedimage", "rb");
    of = fopen("decoded.jpg", "wb");
    
    for (i = 0; i < sizeof(seeds)/sizeof(seeds[0]) ; i++) {
        srand(seeds[i]);

        for (j = 0; j < 0x800; j += 4) {
            fread(&buf, 4, 1, f);
            buf ^= rand();
            fwrite(&buf, 4, 1, of);
        }
    }
        
    fclose(of);
    fclose(f);
}
