#ifndef _ECOSSYS_H_
#define _ECOSYS_H_

#define SIZE_X 20
#define SIZE_Y 20

typedef struct _animal{
  int x;
  int y;
  int dir[2]; // direction courante sous la forme (dx, dy)
  float energie;
  struct _animal *precedent;
  struct _animal *suivant;
} Animal;

extern float p_ch_dir;
extern float d_proie;
extern float d_predateur;
extern float p_manger;
extern float p_reproduce;
extern float energie;

Animal *creer_animal(int x, int y, float energie);

Animal *ajouter_en_tete_animal(Animal *liste, Animal *animal);

void ajouter_animal(int x, int y, Animal **liste_animal);

void enlever_animal(Animal **liste, Animal *animal);

unsigned int compte_animal_rec(Animal *la);

unsigned int compte_animal_it(Animal *la);

void bouger_animaux(Animal *la);

Animal *animal_en_XY(Animal *l, int x, int y);

void rafraichir_predateurs(Animal **liste_predateur, Animal **liste_proie);

void rafraichir_proies(Animal **liste_proie);

void afficher_ecosys(Animal *liste_predateur, Animal *liste_proie);

void clear_screen();

void liberer_liste_animaux(Animal * liste);
#endif
