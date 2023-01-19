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

#define JOKOA_PLAYER "..\\img\\prota.bmp"
#define JOKOA_NPC "..\\img\\mendizalea.bmp"
#define JOKOA_GILTZA "..\\img\\giltza.bmp"
#define JOKOA_FONDO1 "..\\img\\fondo1.bmp"
#define JOKOA_FONDO2 "..\\img\\fondo2.bmp"
#define JOKOA_FONDO3 "..\\img\\fondo3.bmp"
#define JOKOA_FONDO4 "..\\img\\fondo4.bmp"
#define JOKOA_FONDO4B "..\\img\\fondo4Irekita.bmp"
#define JOKOA_FONDO5 "..\\img\\fondo5.bmp"
#define JOKOA_FONDO6 "..\\img\\fondo6.bmp"
#define JOKOA_FONDO6B "..\\img\\fondo6Zuhaitzak.bmp"
#define JOKOA_FONDO7 "..\\img\\fondo7.bmp"
#define JOKOA_FONDO8 "..\\img\\fondo8.bmp"
#define JOKOA_FONDO8B "..\\img\\fondo8Zuhaitzak.bmp"
#define JOKOA_FONDO9 "..\\img\\fondo9.bmp"
#define JOKOA_FONDO9B "..\\img\\fondo9Konponduta.bmp"
#define JOKOA_FONDO10 "..\\img\\fondo10.bmp"
#define JOKOA_EGURRA "..\\img\\egurra.bmp"
#define JOKOA_PLASTIKOA "..\\img\\plastikoa.bmp"
#define JOKOA_INBENTARIOA "..\\img\\inventario.bmp"

//fonduak
int JOKOA_fondo1()
{
    int martzianoId = -1;
    martzianoId = irudiaKargatu(JOKOA_FONDO1);
    irudiaMugitu(martzianoId, 0, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();

    return martzianoId;

}
int JOKOA_fondo3()
{
    int martzianoId = -1;
    martzianoId = irudiaKargatu(JOKOA_FONDO3);
    irudiaMugitu(martzianoId, 0, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();

    return martzianoId;

}
int JOKOA_fondo2()
{
    int martzianoId = -1;
    martzianoId = irudiaKargatu(JOKOA_FONDO2);
    irudiaMugitu(martzianoId, 0, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();

    return martzianoId;

}
int JOKOA_objetua()
{
    int martzianoId = -1;
    martzianoId = irudiaKargatu(JOKOA_GILTZA);
    irudiaMugitu(martzianoId, 50, 45);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return martzianoId;

}
int JOKOA_fondo4() {
    int martzianoId = -1;
    martzianoId = irudiaKargatu(JOKOA_FONDO4);
    irudiaMugitu(martzianoId, 0, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return martzianoId;
}
int JOKOA_fondo4B() {
    int martzianoId = -1;
    martzianoId = irudiaKargatu(JOKOA_FONDO4B);
    irudiaMugitu(martzianoId, 0, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return martzianoId;
}
int JOKOA_fondo5() {
    int martzianoId = -1;
    martzianoId = irudiaKargatu(JOKOA_FONDO5);
    irudiaMugitu(martzianoId, 0, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return martzianoId;
}
int JOKOA_fondo6() {
    int martzianoId = -1;
    martzianoId = irudiaKargatu(JOKOA_FONDO6);
    irudiaMugitu(martzianoId, 0, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return martzianoId;
}
int JOKOA_fondo6B() {
    int martzianoId = -1;
    martzianoId = irudiaKargatu(JOKOA_FONDO6B);
    irudiaMugitu(martzianoId, 0, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return martzianoId;
}
int JOKOA_fondo7() {
    int martzianoId = -1;
    martzianoId = irudiaKargatu(JOKOA_FONDO7);
    irudiaMugitu(martzianoId, 0, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return martzianoId;
}
int JOKOA_fondo8() {
    int martzianoId = -1;
    martzianoId = irudiaKargatu(JOKOA_FONDO8);
    irudiaMugitu(martzianoId, 0, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return martzianoId;
}
int JOKOA_fondo8B() {
    int martzianoId = -1;
    martzianoId = irudiaKargatu(JOKOA_FONDO8B);
    irudiaMugitu(martzianoId, 0, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return martzianoId;
}
int JOKOA_fondo9() {
    int martzianoId = -1;
    martzianoId = irudiaKargatu(JOKOA_FONDO9);
    irudiaMugitu(martzianoId, 0, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return martzianoId;
}
int JOKOA_fondo9B() {
    int martzianoId = -1;
    martzianoId = irudiaKargatu(JOKOA_FONDO9B);
    irudiaMugitu(martzianoId, 0, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return martzianoId;
}
int JOKOA_fondo10() {
    int martzianoId = -1;
    martzianoId = irudiaKargatu(JOKOA_FONDO10);
    irudiaMugitu(martzianoId, 0, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return martzianoId;
}
//materialak
int JOKOA_egurra1() {
    int egurra = -1;
    egurra = irudiaKargatu(JOKOA_EGURRA);
    irudiaMugitu(egurra, 190, 160);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return egurra;
}
int JOKOA_egurra2() {
    int egurra = -1;
    egurra = irudiaKargatu(JOKOA_EGURRA);
    irudiaMugitu(egurra, 400, 230);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return egurra;
}
int JOKOA_egurra3() {
    int egurra = -1;
    egurra = irudiaKargatu(JOKOA_EGURRA);
    irudiaMugitu(egurra, 400, 90);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return egurra;
}
int JOKOA_egurra4() {
    int egurra = -1;
    egurra = irudiaKargatu(JOKOA_EGURRA);
    irudiaMugitu(egurra, 190, 160);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return egurra;
}
int JOKOA_egurra5() {
    int egurra = -1;
    egurra = irudiaKargatu(JOKOA_EGURRA);
    irudiaMugitu(egurra, 400, 230);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return egurra;
}
int JOKOA_egurra6() {
    int egurra = -1;
    egurra = irudiaKargatu(JOKOA_EGURRA);
    irudiaMugitu(egurra, 400, 90);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return egurra;
}
int JOKOA_plastikoa1() {
    int plastikoa = -1;
    plastikoa = irudiaKargatu(JOKOA_PLASTIKOA);
    irudiaMugitu(plastikoa, 400, 120);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return plastikoa;
}
int JOKOA_plastikoa2() {
    int plastikoa = -1;
    plastikoa = irudiaKargatu(JOKOA_PLASTIKOA);
    irudiaMugitu(plastikoa, 200, 220);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return plastikoa;
}
int JOKOA_plastikoa3() {
    int plastikoa = -1;
    plastikoa = irudiaKargatu(JOKOA_PLASTIKOA);
    irudiaMugitu(plastikoa, 400, 120);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return plastikoa;
}
int JOKOA_plastikoa4() {
    int plastikoa = -1;
    plastikoa = irudiaKargatu(JOKOA_PLASTIKOA);
    irudiaMugitu(plastikoa, 400, 120);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return plastikoa;
}
//pertsonaiak
int JOKOA_jokalariaIrudiaSortu(int x, int y)
{
    int martzianoId = -1;
    pantailaGarbitu();
    martzianoId = irudiaKargatu(JOKOA_PLAYER);
    irudiaMugitu(martzianoId, x, y);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return martzianoId;

}
int JOKOA_npc()
{
    int martzianoId = -1;
    pantailaGarbitu();
    martzianoId = irudiaKargatu(JOKOA_NPC);
    irudiaMugitu(martzianoId, 450, 130);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return martzianoId;
}
//inbentario
int JOKOA_motxila()
{
    int martzianoId = -1;
    pantailaGarbitu();
    martzianoId = irudiaKargatu(JOKOA_INBENTARIOA);
    irudiaMugitu(martzianoId, 525, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return martzianoId;
}

