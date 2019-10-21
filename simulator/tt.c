#include <ctype.h>
#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../multipass/interface.h"

void tele_tr(uint8_t i, int16_t v) {
    printf("TR  i:%" PRIu8 " v:%" PRId16, i, v);
    printf("\n");
}

void tele_cv(uint8_t i, int16_t v, uint8_t s) {
    printf("CV  i:%" PRIu8 " v:%" PRId16 " s:%" PRIu8, i, v, s);
    printf("\n");
}

void tele_cv_off(uint8_t i, int16_t v) {
    printf("CV_OFF  i:%" PRIu8 " v:%" PRId16, i, v);
    printf("\n");
}

int main() {
    char *in;
    time_t t;
    int i;

    srand((unsigned)time(&t));

    in = malloc(256);

    printf("teletype. (blank line quits)\n\n");
    printf("CV Output Count  i:%" PRIu8, get_cv_output_count());

    do {
        printf("> ");
        fgets(in, 256, stdin);

        i = 0;
        while (in[i]) {
            in[i] = toupper(in[i]);
            i++;
        }

        printf("\n");
    } while (in[0] != 10);

    free(in);

    printf("(teletype exit.)\n");
}
