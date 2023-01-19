#ifndef GAME10_H
#define GAME10_H

#include "OurTypes.h"

void jokoaAurkeztu(void);
inline EGOERA jokatu(void);
int  jokoAmaierakoa(EGOERA egoera);
inline void sarreraMezuaIdatzi();
inline void textua(char materialak[]);
inline void kofree(char Kofre[]);
inline void inbentariomu(char kofre[]);

int JOKOA_jokalariaIrudiaSortu(int x, int y);
int fonduaSortu();
//void zirkuluaBistaratu(int xRef, int yRef);
void JOKOA_lerroHBatMargotu(int x, int y, int x1, int y1);
void JOKOA_lerroVBatMargotu(int x, int y, int x1, int y1);
EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa, int eszena);
//int  BUKAERA_menua(EGOERA egoera);
int BUKAERA_irudiaBistaratu();
inline int objetua_giltza(POSIZIOA posizioa, int eszena, int giltza);
inline void gauzakgorde(int eszena, char egurra[], char plastikoa[], char egurraKofre[]);



#endif