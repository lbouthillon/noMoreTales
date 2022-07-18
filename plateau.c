#include <stdio.h>
#include "plateau.h"
#include "decor.h"
#include "bitmap.h"
#include <allegro.h>

NB_CASES_LARG = 15;
NB_CASES_LONG = 15;
DEFAULT_TILE_SIZE = 64;

PLATEAU * chambre = NULL;
PLATEAU p1;
PLATEAU * RDC = NULL;
PLATEAU p2;

PLATEAU changementPlateau1(PLATEAU plateauCourant, PERSONNAGE perso, BITMAP * page){
    if (perso.direction == 1 && plateauCourant.y == 180 && plateauCourant.x >= 70 && plateauCourant.x <= 105){
        for (int i = 0 ; i < 5 ; i++){
            perso.y = perso.y - 5;
            clear_bitmap(page);
            draw_plateau(plateauCourant,page);
            afficher_personnage(perso,page);
            blit(page,screen,0,0,0,0,800,600);
            rest(20);
        }

        perso.direction = 0;
        //allegro_message("sortie");
        RDC->x = plateauCourant.x;
        RDC->y = plateauCourant.y;
        return *RDC;
    }
    return plateauCourant;
}

PLATEAU changementPlateau2(PLATEAU plateauCourant, PERSONNAGE perso, BITMAP * page){
    return plateauCourant;
}

void draw_plateau(PLATEAU plateau, BITMAP * page){
    for (int i = 0 ; i < plateau.nbDecors ; i++){
        DECOR d = plateau.decors[i];
        afficher_decor(d,page,plateau.x,plateau.y);
    }
};

/*PLATEAU * deplacer_plateau(PLATEAU plateau, int deplacement_x, int deplacement_y){
    plateau.x = plateau.x + deplacement_x;
    plateau.y = plateau.y + deplacement_y;
    for (int i = 0 ; i < plateau.nbDecors ; i++){
        plateau.decors[i].x = plateau.decors[i].x + deplacement_x;
        plateau.decors[i].y = plateau.decors[i].y + deplacement_y;
    }
    return &plateau;
}*/

int collision_plateau(PLATEAU plateau, PERSONNAGE perso, int deplacement_max){
    int deplacement = deplacement_max;
    for (int i = 0 ; i < plateau.nbDecors ; i++){
        DECOR d = plateau.decors[i];
        deplacement = MIN(deplacement,collision(perso, &d, deplacement_max, plateau.x, plateau.y));
    }
    return deplacement;
}

void init_plateaux(){

    p1.nbDecors = 0;
    p1.x = 0;
    p1.y = 0;
    p1.xMin =  - 117;
    p1.xMax = 137;
    p1.yMin = -100;
    p1.yMax = 180;
    p1 = add_decor(p1, *fondBlancDecor);
    p1 = add_decor(p1, *murs2Decor);
    p1 = add_decor(p1, *litDecor);
    p1 = add_decor(p1, *porteSangDecor);
    p1 = add_decor(p1, *goutteSangDecor);
    p1.changementPlateau = changementPlateau1;
    chambre = &p1;

    p2.nbDecors = 0;
    p2.x = 0;
    p2.y = 0;
    p2.xMin =  - 117;
    p2.xMax = 137;
    p2.yMin = -100;
    p2.yMax = 180;
    p2 = add_decor(p2, *fondBlancDecor);
    p2 = add_decor(p2, *murs2Decor);
    p2 = add_decor(p2, *porteSangDecor);
    p2.changementPlateau = changementPlateau2;
    RDC = &p2;
};

PLATEAU add_decor(PLATEAU plateau, DECOR decor){
    plateau.decors[plateau.nbDecors] = decor;
    plateau.nbDecors = plateau.nbDecors + 1;
    return plateau;
};



/*BITMAP * init_page()
{
    rectfill(screen,200,100,100,200,makecol(0,255,0));
    BITMAP * page;
    BITMAP * sol;
    int x = 0;
    int y = 0;
    int width = NB_CASES_LARG * DEFAULT_TILE_SIZE;
    int length = NB_CASES_LONG * DEFAULT_TILE_SIZE;
    page = create_bitmap(length,width);
    sol = load_bitmap("SolBlanc.bmp",NULL);
    if (!sol)
    {
        allegro_message("prb allocation BITMAP sol");
        exit(EXIT_FAILURE);
    }
    for (int largeur = 0 ; largeur < NB_CASES_LARG; largeur++ )
    {
        for (int longueur = 0 ; longueur < NB_CASES_LONG; longueur++ )
        {
            draw_sprite(page,sol,x,y);
            x = x + 64;
        }
        y = y + 64;
        x = 0;
    }
    rectfill(screen,200,100,100,200,makecol(0,255,0));
    return page;
}*/
