#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "image.h"
#define TMP_STR_SIZE 256

image_t *charger_image_pgm(char *nom_fichier)
	{
	
	enum format {BIN, ASCII} pgm_form;
	int i;
	unsigned int nb_niveaux_gris;
	char ligne_lue[TMP_STR_SIZE],*pc;
	image_t *img;
	FILE *f = fopen(nom_fichier,"r");
	if(f == NULL)
		return NULL;
	else{
		img = creer_image();

		do{
			pc = fgets(ligne_lue,TMP_STR_SIZE,f);
		}while((pc !=NULL)&&(ligne_lue[0] == '#'));

		if(pc !=NULL){

			if(strncmp(ligne_lue,"P2",2) != 0){
				if(strncmp(ligne_lue,"P5",2) != 0){
					fprintf(stderr,"ERREUR FORMAT\n");

				}else{
					pgm_form = BIN;
					do{
					pc = fgets(ligne_lue,TMP_STR_SIZE,f);
					}while((pc !=NULL)&&(ligne_lue[0] == '#'));

					if(pc !=NULL){
						sscanf(ligne_lue,"%lu %lu\n",&img->w,&img->h);
			
						img->path = strdup(nom_fichier);
						img->buff = malloc(img->w*img->h*sizeof(unsigned char));
			
						do{
						pc = fgets(ligne_lue,TMP_STR_SIZE,f);
						}while((pc !=NULL)&&(ligne_lue[0] == '#'));

						if(pc !=NULL){
							sscanf(ligne_lue,"%u\n",&nb_niveaux_gris);
	
							if(nb_niveaux_gris != 255){
								detruire_image(img);
								return NULL;
							}else{  //verif comments late maybe.

								fread(img->buff,sizeof(unsigned char),img->h*img->w,f);
				

							}

						}
							
					}
				}
			}else{
				pgm_form = ASCII;
					do{
					pc = fgets(ligne_lue,TMP_STR_SIZE,f);
					}while((pc !=NULL)&&(ligne_lue[0] == '#'));
					if(pc !=NULL){
						sscanf(ligne_lue,"%lu %lu\n",&img->w,&img->h);
			
						img->path = strdup(nom_fichier);
						img->buff = malloc(img->w*img->h*sizeof(unsigned char));
		
						do{
						pc = fgets(ligne_lue,TMP_STR_SIZE,f);
						}while((pc !=NULL)&&(ligne_lue[0] == '#'));

						if(pc !=NULL){
						sscanf(ligne_lue,"%u\n",&nb_niveaux_gris);
	
							if(nb_niveaux_gris != 255){
								detruire_image(img);
								return NULL;
							}else{  //verif comments late maybe.

								for(i=0;i<img->h*img->w;i++)
									fscanf(f,"%hhu ",&img->buff[i]);

				

							}
						}
					}
				}
			
			}
		}
	
	fclose(f);
	return img;
	}

int sauver_image_pgm(char *nom_fichier, image_t *img)
	{

	int i;
	FILE *f = fopen(nom_fichier,"w");
	if(f == NULL){
		fprintf(stderr,"FICHIER NON OUVERT\n");
		return 0;
	}else{
		if(img == NULL){
			fprintf(stderr,"ERROR WITH IMAGE\n");
			return 0;
		}else{
			img->path = strdup(nom_fichier);
			fprintf(f,"P2\n");
			fprintf(f,"%lu %lu\n",img->w,img->h);		
			fprintf(f,"255\n");
			if(img->buff == NULL){
				fprintf(stderr,"BUFF EMPTY\n");
				return 0;
			}else{
				for(i=0;i<img->h*img->w;i++)
					fprintf(f,"%hhu ",img->buff[i]);
				fclose(f);	
				return 1;
				
			}
		}
				
	}	
	}

