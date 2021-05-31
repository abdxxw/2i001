#include<stdlib.h>
#include<string.h>
#include "image.h"

image_t *creer_image()
	{
	image_t * temp;
	temp = malloc(sizeof(image_t));
	temp->w = 0;
	temp->h = 0;
	temp->path = NULL;
	temp->buff = NULL;
	return temp;
	}

image_t *copier_image(image_t *src)
	{
	if(src == NULL)
		return NULL;
	else{
		image_t * temp = creer_image();
		temp->w = src->w;
		temp->h = src->h;
		temp->path = strdup(src->path);
		temp->buff = malloc(src->w*src->h*sizeof(unsigned char));
		memcpy(temp->buff,src->buff,src->w*src->h);
		return temp;	
	}
	}

void detruire_image(image_t *p)
	{
	if(p != NULL){
		if(p->path !=NULL)
			free(p->path);
		if(p->buff != NULL)
			free(p->buff);
		free(p);	
	}
	}
