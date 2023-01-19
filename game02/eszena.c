#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game02.h"
#include "../main_menu/irudiak.h"
#include "../main_menu/graphics.h"
#include "../main_menu/ebentuak.h"
#include "../main_menu/textua.h"
#include "../main_menu/audio.h"
#include "kolisioak.h"
#include "marrazkiak.h"
#include "game02.h"
#include "OurTypes.h"

EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa, int eszena) {
    EGOERA  ret = JOLASTEN;
    if (eszena == 1) {
        if (jokalaria.pos.x > 320 && jokalaria.pos.x < 361 && jokalaria.pos.y > 180 && jokalaria.pos.y < 270) {
            ret = 11;
        }
        if (jokalaria.pos.x < 10) {
            ret = 13;
        }
    }
    if (eszena == 2) {
        if (jokalaria.pos.x > -11 && jokalaria.pos.x < 11 && jokalaria.pos.y > -20 && jokalaria.pos.y < 130) {
            ret = 12;
        }
        if (jokalaria.pos.x > 11 && jokalaria.pos.x < 100 && jokalaria.pos.y > 0 && jokalaria.pos.y < 20) {
            ret = 12;
        }
    }
    if (eszena == 3) {
        if (jokalaria.pos.x > 600) {
            ret = 12;
        }
        if (jokalaria.pos.x < 10) {
            ret = 14;
        }
        if (jokalaria.pos.y < 10) {
            ret = 16;
        }
    }
    if (eszena == 4) {
        if (jokalaria.pos.x > 600) {
            ret = 13;
        }
        if (jokalaria.pos.x < 0) {
            ret = 15;
        }
        if (jokalaria.pos.y < 0) {
            ret = 17;
        }
    }
    if (eszena == 5) {
        if (jokalaria.pos.x > 600) {
            ret = 14;
        }
    }
    if (eszena == 6) {
        if (jokalaria.pos.y > 440) {
            ret = 13;
        }
        if (jokalaria.pos.x < 10) {
            ret = 17;
        }
        if (jokalaria.pos.y < 0) {
            ret = 18;
        }
    }
    if (eszena == 7) {
        if (jokalaria.pos.y > 450) {
            ret = 14;
        }
        if (jokalaria.pos.y < 0) {
            ret = 19;
        }
        if (jokalaria.pos.x > 600) {
            ret = 16;
        }
    }
    if (eszena == 8) {
        if (jokalaria.pos.x < 10) {
            ret = 19;
        }
        if (jokalaria.pos.y > 440) {
            ret = 16;
        }
    }
    if (eszena == 9) {
        if (jokalaria.pos.y > 450) {
            ret = 17;
        }
        if (jokalaria.pos.x > 600) {
            ret = 18;
        }
        if (jokalaria.pos.x > 70 && jokalaria.pos.x < 90 && jokalaria.pos.y > 0 && jokalaria.pos.y < 100) {
            ret = 20;
        }
    }
    if (eszena == 10) {
        if (jokalaria.pos.x > 390 && jokalaria.pos.x < 410 && jokalaria.pos.y > 180 && jokalaria.pos.y < 290) {
            ret = 19;
        }
    }
    return ret;
}