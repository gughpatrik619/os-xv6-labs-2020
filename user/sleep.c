//
// Created by gughpatrik on 9/23/20.
//

/*
 * Naimplementujte UNIXový program sleep pre xv6;
 * vaša implementácia programu sleep by sa mala
 * pozastaviť na užívateľom definovaný počet tikov.
 * Jeden tik je definovaný jadrom xv6 ako čas medzi
 * dvoma prerušeniami časovacieho čipu.
 * Svoje riešenie uložte do user/sleep.c.
 */

#include "../kernel/types.h"
#include "../kernel/fcntl.h"
#include "user.h"

int main(int argc, char* argv[]) {

    if (argc <= 1) {
        fprintf(1, "Usage: sleep <ticks>\n");
        exit(1);
    }

    int ticks = atoi(argv[1]);

    sleep(ticks);

    exit(0);
}
