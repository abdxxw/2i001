#include <gtk/gtk.h>
#include <stdlib.h>
#include "image.h"
#include "pile_image.h"

extern GtkWidget *pLabel_Nomf;
extern GtkWidget *pLabel_Res;
extern GtkWidget *pDA;


p_pile_img pile_future = NULL;
p_pile_img pile_passe = NULL;
image_t *cur_image;

p_pile_img pile_cree_cellule(image_t img)
    {
        p_pile_img temp = malloc(sizeof(pile_img));
        temp->img = img;
        temp->suiv = NULL;

        return temp;
    }

void pile_empiler_image(p_pile_img * P,image_t img)
    {
        p_pile_img temp = pile_cree_cellule(img);
        temp->suiv = (*P);
        (*P)->suiv = temp;
        temp = NULL;

    }
image_t pile_depiler_image(p_pile_img * P)
    {
        image_t x = (*P)->img;
        p_pile_img temp = (*P);
        (*P) = (*P)->suiv;
        free(temp);
        return x;

    }

void pile_detruire(p_pile_img * P)
    {
        p_pile_img temp = (*P);
        while(temp){
            (*P)=(*P)->suiv;
            detruire_image(&temp->img);
            free(temp);
            temp = (*P);
        }

    }
void pile_new_image(image_t *new_image)
	{
	char str_res[32];

    pile_empiler_image(&pile_passe, (*cur_image));
	cur_image = new_image;
	gtk_label_set_text (GTK_LABEL (pLabel_Nomf), cur_image->path);
	snprintf(str_res, 32, "%ldx%ld", cur_image->w, cur_image->h);
	gtk_label_set_text (GTK_LABEL (pLabel_Res), str_res);
	gtk_widget_queue_draw_area(pDA, 0, 0, pDA->allocation.width, pDA->allocation.height);
	}

void pile_free_images()
	{

    pile_empiler_image(&pile_passe, (*cur_image));
	gtk_label_set_text (GTK_LABEL (pLabel_Nomf), "Pas d image chargee");
	gtk_label_set_text (GTK_LABEL (pLabel_Res), "Resolution Image");
	cur_image = NULL;
	gtk_widget_queue_draw_area(pDA, 0, 0, 0, 0);
	gtk_widget_queue_draw_area(pDA, 0, 0, pDA->allocation.width, pDA->allocation.height);
	}

void pile_undo()
	{
	    char str_res[32];

        image_t temp = pile_depiler_image(&pile_passe);
        pile_empiler_image(&pile_future,temp);
        cur_image = &temp;
	    gtk_label_set_text (GTK_LABEL (pLabel_Nomf), cur_image->path);
    	snprintf(str_res, 32, "%ldx%ld", cur_image->w, cur_image->h);
	    gtk_label_set_text (GTK_LABEL (pLabel_Res), str_res);
	    gtk_widget_queue_draw_area(pDA, 0, 0, pDA->allocation.width, pDA->allocation.height);
	
	}

void pile_redo()
	{
	    char str_res[32];
        
        image_t temp = pile_depiler_image(&pile_future);
        pile_empiler_image(&pile_passe,temp);
        cur_image = &temp;
	    gtk_label_set_text (GTK_LABEL (pLabel_Nomf), cur_image->path);
    	snprintf(str_res, 32, "%ldx%ld", cur_image->w, cur_image->h);
	    gtk_label_set_text (GTK_LABEL (pLabel_Res), str_res);
	    gtk_widget_queue_draw_area(pDA, 0, 0, pDA->allocation.width, pDA->allocation.height);
	
	}
