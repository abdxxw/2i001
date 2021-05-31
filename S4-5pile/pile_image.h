#ifndef PILE_IMAGE
#define PILE_IMAGE

#include "image.h"

typedef struct pile_img * p_pile_img;
typedef struct pile_img{
    image_t * img;
    p_pile_img  suiv;
}pile_img;

p_pile_img pile_cree_cellule(image_t * img);
void pile_empiler_image(p_pile_img * P,image_t *img);
image_t * pile_depiler_image(p_pile_img * P);
void pile_detruire(p_pile_img * P);
void pile_new_image(image_t *new_image);
void pile_free_images();
void pile_undo();
void pile_redo();

#endif
