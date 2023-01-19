#include "game02.h"
#include "../main_menu/irudiak.h"
#include "../main_menu/graphics.h"
#include "../main_menu/ebentuak.h"
#include "../main_menu/textua.h"
#include "../main_menu/audio.h"
#include "kolisioak.h"
#include "marrazkiak.h"
#include "eszena.h"
#include "materialak.h"
#include <stdio.h>
#include <windows.h>

#define ONGI_ETORRI_MEZUA "Sakatu return hasteko..."
#define ONGI_ETORRI_MEZUA2 "Sakatu return itzultzeko..."
#define TEXTUA "KAIZO"
#define TEXTUA2 "apa"





void jokoaAurkeztu(void)
{
  int ebentu = 0;
  sarreraMezuaIdatzi();
  do
  {
    ebentu = ebentuaJasoGertatuBada();
  } while (ebentu != TECLA_RETURN);
  pantailaGarbitu();
  pantailaBerriztu();
}

void inbentariomu(char kofre[])
{
    int ebentu = 0;
    kofree(kofre);

    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);
    pantailaGarbitu();
    pantailaBerriztu();
}

void textua(char materialak[]) {
    int tokila;
    char egurra[50], plastikoa[50], motxila[50];
    tokila = 5;


    sprintf(motxila, "Motxila: %d/%d", materialak[0], tokila);
    sprintf(egurra, "Egurra: %d", materialak[1]);
    sprintf(plastikoa, "Plastikoa: %d", materialak[2]);
    pantailaGarbitu();
    textuaIdatzi(225, 200, egurra);
    textuaIdatzi(225, 240, plastikoa);
    textuaIdatzi(225, 160, motxila);
    textuaIdatzi(450, 400, ONGI_ETORRI_MEZUA2);
    pantailaBerriztu();
}
void kofree(char Kofre[]) {
    char egurra[50], plastikoa[50];


    sprintf(egurra, "Egurra: %d", Kofre[1]);
    sprintf(plastikoa, "Plastikoa: %d", Kofre[2]);
    pantailaGarbitu();
    textuaIdatzi(225, 200, egurra);
    textuaIdatzi(225, 240, plastikoa);
    textuaIdatzi(450, 400, ONGI_ETORRI_MEZUA2);
    pantailaBerriztu();
}
void sarreraMezuaIdatzi()
{
  pantailaGarbitu();
  textuaIdatzi(225, 200, ONGI_ETORRI_MEZUA);
  pantailaBerriztu();
}

EGOERA jokatu(void) 
{
  int mugituw = 0; 
  int mugitus = 0; 
  int mugitua = 0; 
  int mugitud = 0; 
  int noa = 0, eszena = 1, non = 1, giltza = 0, sortu = 0, motxila = 5, zerdo = 0, ireki = 0;
  int aldatu = 0, zubia = 0, dirua = 0;
  char egurra[50], Kofre[50], plastikoa[50], motxilaa[50];

  Kofre[1] = 0;//egurra
  Kofre[2] = 0;//plastikoa

  egurra[0] = 0; //dakazun egurra
  plastikoa[0] = 0;
  //egur bakoitza kentzeko
  egurra[1] = 0;
  egurra[2] = 0;
  egurra[3] = 0;
  egurra[4] = 0;
  egurra[5] = 0;
  egurra[6] = 0;
  plastikoa[1] = 0;
  plastikoa[2] = 0;
  plastikoa[3] = 0;
  plastikoa[4] = 0;
  plastikoa[5] = 0;


  EGOERA  egoera = JOLASTEN;
  int ebentu = 0;
  JOKO_ELEMENTUA zirkulua, jokalaria, fondo, giltza1, mina;
  POSIZIOA aux;
  zirkulua.pos.x = 600;
  zirkulua.pos.y = 200;
  //Uint32 time01 = SDL_GetTicks(), time02;

  jokalaria.pos.x = 20;
  jokalaria.pos.y = 240;


  audioInit();
  playMusic();
  fondo.id = JOKOA_fondo1();

  jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
  fondo.id = JOKOA_motxila();


  do {
      do {
          if (ebentu == TECLA_e) {
              if (jokalaria.pos.x > 500 && jokalaria.pos.y > 0 && jokalaria.pos.x < 600 && jokalaria.pos.y < 50) {
                  gauzakgorde(eszena, egurra, plastikoa, Kofre);
                  inbentariomu(Kofre);
                  zerdo = 0;
              }

          }
          //giltza eta atea
          if (giltza == 1) {
              fondo.id = JOKOA_fondo10();
              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
              giltza = 2;
          }
          if (ebentu == TECLA_e) {
              if (giltza == 2) {
                  if (eszena == 4) {
                      if (jokalaria.pos.x < 110) {
                          fondo.id = JOKOA_fondo4B();
                          jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
                          ireki = 1;
                      }
                  }
              }
          }
          //objetuak hartu
          if (ebentu == TECLA_e) {
              if (eszena == 8) {
                  if (jokalaria.pos.x > 170 && jokalaria.pos.x < 210 && jokalaria.pos.y > 130 && jokalaria.pos.y < 190) {
                      if (egurra[4] == 0) {
                          if (zerdo + 2 <= motxila) {
                              egurra[4] = 1;
                              fondo.id = JOKOA_fondo8();
                              if (egurra[5] == 0) {
                                  fondo.id = JOKOA_egurra5();
                              }
                              if (egurra[6] == 0) {
                                  fondo.id = JOKOA_egurra6();
                              }
                              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
                              fondo.id = JOKOA_fondo8B();
                              zerdo += 2;
                              egurra[0]++;
                          }
                      }
                  }
                  if (jokalaria.pos.x > 380 && jokalaria.pos.x < 420 && jokalaria.pos.y > 60 && jokalaria.pos.y < 120) {
                      if (egurra[6] == 0) {
                          if (zerdo + 2 <= motxila) {
                              egurra[6] = 1;

                              fondo.id = JOKOA_fondo8();
                              if (egurra[4] == 0) {
                                  fondo.id = JOKOA_egurra4();
                              }
                              if (egurra[5] == 0) {
                                  fondo.id = JOKOA_egurra5();
                              }
                              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
                              fondo.id = JOKOA_fondo8B();
                              zerdo += 2;
                              egurra[0]++;
                          }
                      }
                  }
              }
              if (eszena == 6) {
                  if (jokalaria.pos.x > 170 && jokalaria.pos.x < 210 && jokalaria.pos.y > 130 && jokalaria.pos.y < 190) {
                      if (egurra[1] == 0) {
                          if (zerdo + 2 <= motxila) {
                              egurra[1] = 1;
                              fondo.id = JOKOA_fondo6();
                              if (egurra[2] == 0) {
                                  fondo.id = JOKOA_egurra2();
                              }
                              if (egurra[3] == 0) {
                                  fondo.id = JOKOA_egurra3();
                              }
                              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
                              fondo.id = JOKOA_fondo6B();
                              zerdo += 2;
                              egurra[0]++;
                          }
                      }
                  }
                  if (jokalaria.pos.x > 380 && jokalaria.pos.x < 420 && jokalaria.pos.y > 200 && jokalaria.pos.y < 260) {
                      if (egurra[2] == 0) {
                          if (zerdo + 2 <= motxila) {
                              egurra[2] = 1;
                              fondo.id = JOKOA_fondo6();
                              if (egurra[1] == 0) {
                                  fondo.id = JOKOA_egurra1();
                              }
                              if (egurra[3] == 0) {
                                  fondo.id = JOKOA_egurra3();
                              }
                              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
                              fondo.id = JOKOA_fondo6B();
                              zerdo += 2;
                              egurra[0]++;
                          }
                      }
                  }
                  if (jokalaria.pos.x > 380 && jokalaria.pos.x < 420 && jokalaria.pos.y > 60 && jokalaria.pos.y < 120) {
                      if (egurra[3] == 0) {
                          if (zerdo + 2 <= motxila) {
                              egurra[3] = 1;
                              fondo.id = JOKOA_fondo6();
                              if (egurra[1] == 0) {
                                  fondo.id = JOKOA_egurra1();
                              }
                              if (egurra[2] == 0) {
                                  fondo.id = JOKOA_egurra2();
                              }
                              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
                              fondo.id = JOKOA_fondo6B();
                              zerdo += 2;
                              egurra[0]++;
                          }
                      }
                  }
              }
              if (eszena == 7) {
                  if (jokalaria.pos.x > 380 && jokalaria.pos.x < 420 && jokalaria.pos.y > 110 && jokalaria.pos.y < 150) {
                      if (plastikoa[1] == 0) {
                          if (zerdo + 3 <= motxila) {
                              plastikoa[1] = 1;
                              fondo.id = JOKOA_fondo7();
                              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
                              zerdo += 3;
                              plastikoa[0]++;
                          }
                      }
                  }
                  if (jokalaria.pos.x > 380 && jokalaria.pos.x < 420 && jokalaria.pos.y > 110 && jokalaria.pos.y < 150) {
                      if (plastikoa[2] == 0) {
                          if (zerdo + 3 <= motxila) {
                              plastikoa[1] = 1;
                              fondo.id = JOKOA_fondo7();
                              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
                              zerdo += 3;
                              plastikoa[0]++;
                          }
                      }
                  }
              }
          }
          //zubia konpondu
          if (zubia != 1) {
              if (ebentu == TECLA_e) {
                  if (eszena == 9) {
                      if (Kofre[1] >= 2 || egurra[0] >= 2) {
                          if (jokalaria.pos.y > 150 && jokalaria.pos.y < 220 && jokalaria.pos.x >380 && jokalaria.pos.x < 440) {
                              fondo.id = JOKOA_fondo9B();
                              fondo.id = JOKOA_npc();
                              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
                              zubia = 1;
                              if (egurra[0] >= 2) {
                                  egurra[0] -= 2;
                              }
                              else if (Kofre[1] >= 2) {
                                  Kofre[1] -= 2;
                              }
                              zerdo -= 4;
                          }
                      }
                  }
              }
          }
          Sleep(0);
          aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos, noa, eszena, ireki, zubia);
          pantailaGarbitu();
          irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
          irudiakMarraztu();
          pantailaBerriztu();
          ebentu = ebentuaJasoGertatuBada();
          //inbetario
          if (ebentu == TECLA_q) {
              motxilaa[0] = zerdo;
              motxilaa[1] = egurra[0];
              motxilaa[2] = plastikoa[0];
              
          }
          //mugitu 1
          if (ebentu == TECLA_w)
          {
              noa = 4;
              aldatu = 1;
          }
          if (ebentu == TECLA_s)
          {
              noa = 3;
              aldatu = 1;
          }
          if (ebentu == TECLA_a)
          {
              noa = 2;
              aldatu = 1;
          }
          if (ebentu == TECLA_d)
          {
              noa = 1;
              aldatu = 1;
          }
          //OBJETUAK
          if (ebentu == TECLA_e) {
              if (giltza == 0) {
                  giltza = objetua_giltza(jokalaria.pos, eszena, giltza);
              }
          }
          //MUGITU 2

          if (noa!=0) {
              aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos, noa, eszena, ireki, zubia);
              jokalaria.pos.y = aux.y;
              jokalaria.pos.x = aux.x;
              noa = 0;
          }
          //MAPA
          egoera = JOKOA_egoera(jokalaria, zirkulua, eszena);
          if (egoera == 11) {
              eszena = 2;
          }
          if (egoera == 12) {
              eszena = 1;
          }
          if (egoera == 13) {
              eszena = 3;
          }
          if (egoera == 14) {
              eszena = 4;
          }
          if (egoera == 15) {
              eszena = 5;
          }
          if (egoera == 16) {
              eszena = 6;
          }
          if (egoera == 17) {
              eszena = 7;
          }
          if (egoera == 18) {
              eszena = 8;
          }
          if (egoera == 19) {
              eszena = 9;
          }
          if (egoera == 20) {
              eszena = 10;
          }
      } while (egoera == JOLASTEN);
      if (eszena == 1) {
          if (non == 2) {
              fondo.id = JOKOA_fondo1();
              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
              non = 1;
              jokalaria.pos.x = 290;
              jokalaria.pos.y = 210;
              egoera = JOLASTEN;
          }
          if (non == 3) {
              fondo.id = JOKOA_fondo1();
              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
              non = 1;
              jokalaria.pos.x = 10;
              egoera = JOLASTEN;
          }
      }
      if (eszena == 3) {
          if (non == 1) {
              fondo.id = JOKOA_fondo3();
              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
              jokalaria.pos.x = 589;
              non = 3;
              egoera = JOLASTEN;
          }
          if (non == 4) {
              fondo.id = JOKOA_fondo3();
              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
              jokalaria.pos.x = 10;
              non = 3;
              egoera = JOLASTEN;
          }
          if (non == 6) {
              fondo.id = JOKOA_fondo3();
              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
              jokalaria.pos.y = 20;
              non = 3;
              egoera = JOLASTEN;
          }
      }
      if (eszena == 2) {
          fondo.id = JOKOA_fondo2();
          jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
          jokalaria.pos.x = 30;
          jokalaria.pos.y = 40;
          non = 2;
          egoera = JOLASTEN;
      }
      if (eszena == 4) {
          if (non == 3) {
              if (ireki == 0) {
                  fondo.id = JOKOA_fondo4();
              }
              else {
                  fondo.id = JOKOA_fondo4B();
              }
              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
              jokalaria.pos.x = 589;
              non = 4;
              egoera = JOLASTEN;
          }
          if (non == 5) {
              if (ireki == 0) {
                  fondo.id = JOKOA_fondo4();
              }
              else {
                  fondo.id = JOKOA_fondo4B();
              }
              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
              jokalaria.pos.x = 10;
              non = 4;
              egoera = JOLASTEN;
          }
          if (non == 7) {
              if (ireki == 0) {
                  fondo.id = JOKOA_fondo4();
              }
              else {
                  fondo.id = JOKOA_fondo4B();
              }
              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
              jokalaria.pos.y = 10;
              non = 4;
              egoera = JOLASTEN;
          }
      }
      if (eszena == 5) {
          if (non == 4) {
              fondo.id = JOKOA_fondo5();
              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
              jokalaria.pos.x = 589;
              non = 5;
              egoera = JOLASTEN;
          }
      }
      if (eszena == 6) {
          if (non == 3) {
              fondo.id = JOKOA_fondo6();
              if (egurra[1] == 0) {
                  fondo.id = JOKOA_egurra1();
              }
              if (egurra[2] == 0) {
                  fondo.id = JOKOA_egurra2();
              }
              if (egurra[3] == 0) {
                  fondo.id = JOKOA_egurra3();
              }
              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
              fondo.id = JOKOA_fondo6B();
              jokalaria.pos.y = 430;
              non = 6;
              egoera = JOLASTEN;
          }
          if (non == 7) {
              fondo.id = JOKOA_fondo6();
              if (egurra[1] == 0) {
                  fondo.id = JOKOA_egurra1();
              }
              if (egurra[2] == 0) {
                  fondo.id = JOKOA_egurra2();
              }
              if (egurra[3] == 0) {
                  fondo.id = JOKOA_egurra3();
              }
              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
              fondo.id = JOKOA_fondo6B();
              jokalaria.pos.x = 20;
              non = 6;
              egoera = JOLASTEN;
          }
          if (non == 8) {
              fondo.id = JOKOA_fondo6();
              if (egurra[1] == 0) {
                  fondo.id = JOKOA_egurra1();
              }
              if (egurra[2] == 0) {
                  fondo.id = JOKOA_egurra2();
              }
              if (egurra[3] == 0) {
                  fondo.id = JOKOA_egurra3();
              }
              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
              fondo.id = JOKOA_fondo6B();
              jokalaria.pos.y = 10;
              non = 6;
              egoera = JOLASTEN;
          }
      }
      if (eszena == 7) {
          if (non == 4) {
              fondo.id = JOKOA_fondo7();
              if (plastikoa[1] == 0) {
                  fondo.id = JOKOA_plastikoa1();
              }
              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
              jokalaria.pos.y = 430;
              non = 7;
              egoera = JOLASTEN;
          }
          if (non == 6) {
              fondo.id = JOKOA_fondo7();
              if (plastikoa[1] == 0) {
                  fondo.id = JOKOA_plastikoa1();
              }
              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
              jokalaria.pos.x = 589;
              non = 7;
              egoera = JOLASTEN;
          }
          if (non == 9) {
              fondo.id = JOKOA_fondo7();
              if (plastikoa[1] == 0) {
                  fondo.id = JOKOA_plastikoa1();
              }
              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
              jokalaria.pos.y = 10;
              non = 7;
              egoera = JOLASTEN;
          }
      }
      if (eszena == 8) {
          if (non == 6) {
              fondo.id = JOKOA_fondo8();
              if (egurra[4] == 0) {
                  fondo.id = JOKOA_egurra4();
              }
              if (egurra[6] == 0) {
                  fondo.id = JOKOA_egurra6();
              }
              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
              fondo.id = JOKOA_fondo8B();
              jokalaria.pos.y = 430;
              non = 8;
              egoera = JOLASTEN;
          }
          if (non == 9) {
              fondo.id = JOKOA_fondo8();
              if (egurra[4] == 0) {
                  fondo.id = JOKOA_egurra4();
              }
              if (egurra[6] == 0) {
                  fondo.id = JOKOA_egurra6();
              }
              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
              fondo.id = JOKOA_fondo8B();
              jokalaria.pos.x = 20;
              non = 8;
              egoera = JOLASTEN;
          }
      }
      if (eszena == 9) {
          if (non == 7) {
              if (zubia == 0) {
                  fondo.id = JOKOA_fondo9();
              }
              else {
                  fondo.id = JOKOA_fondo9B();
              }
              fondo.id = JOKOA_npc();
              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
              jokalaria.pos.y = 430;
              non = 9;
              egoera = JOLASTEN;
          }
          if (non == 8) {
              if (zubia == 0) {
                  fondo.id = JOKOA_fondo9();
              }
              else {
                  fondo.id = JOKOA_fondo9B();
              }
              fondo.id = JOKOA_npc();
              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
              jokalaria.pos.x = 589;
              non = 9;
              egoera = JOLASTEN;
          }
          if (non == 10) {
              if (zubia == 0) {
                  fondo.id = JOKOA_fondo9();
              }
              else {
                  fondo.id = JOKOA_fondo9B();
              }       
              fondo.id = JOKOA_npc();
              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
              jokalaria.pos.x = 100;
              jokalaria.pos.y = 50;
              non = 9;
              egoera = JOLASTEN;
          }
      }
      if (eszena == 10) {
          if (non == 9) {
              fondo.id = JOKOA_fondo10();
              if (giltza == 0) {
                  giltza1.id = JOKOA_objetua();
              }
              jokalaria.id = JOKOA_jokalariaIrudiaSortu(jokalaria.pos.x, jokalaria.pos.y);
              jokalaria.pos.x = 380;
              jokalaria.pos.y = 230;
              non = 10;
              egoera = JOLASTEN;
          }
      }
      fondo.id = JOKOA_motxila();
  } while (egoera == JOLASTEN);
  irudiaKendu(jokalaria.id);
  toggleMusic();
  audioTerminate();
  pantailaGarbitu();
  pantailaBerriztu();
  return egoera;
}

int objetua_giltza(POSIZIOA posizioa, int eszena, int giltza) {
    if (eszena == 10) {
        if (posizioa.x > 40 && posizioa.y > 10 && posizioa.x < 100 && posizioa.y < 80) {
            giltza = 1;
        }
    }
    return giltza;
}
void gauzakgorde(int eszena, char egurra[], char plastikoa[], char Kofre[]) {
    if (eszena == 2) {
        Kofre[1] = Kofre[1] + egurra[0];
        Kofre[2] = Kofre[2] + plastikoa[0];
        egurra[0] = 0;
        plastikoa[0] = 0;
    }
}