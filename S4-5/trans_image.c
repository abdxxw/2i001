#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h"
#include "noyau.h"
#include <time.h> 


void echanger_elem_tab(int tab[], int i, int j)
	{
	int t = tab[i];
	tab[i] = tab[j];
	tab[j] = t;
	}

int partitionner(int tab[], int s, int n)
	{
      int p = s;
		for(int i=s+1;i<=n;i++){
			if(tab[i]<=tab[s]){
				p++;
				echanger_elem_tab(tab,i,p);
			}
		}
				echanger_elem_tab(tab,s,p);
      return p;
	}

void triRapideAmeliore(int tab[], int s, int n)
	{
	if(s>=n)return;

	int piv = partitionner(tab,s,n);
	triRapideAmeliore(tab,s,piv-1);
	triRapideAmeliore(tab,piv+1,n);

	

	}


image_t *negatif(image_t *src)
	{
	int i;
	image_t * img = copier_image(src);
	for(i=0;i<img->h*img->w;i++)
		img->buff[i]=255-img->buff[i];
	return img;
	}

image_t *rotation(image_t *src, int angle)
	{
	int i,j;
	image_t * img = copier_image(src);
	switch (angle){
		case 90 :
		img->h=src->w;
		img->w=src->h;
			for(i=0;i<img->h;i++)
				for(j=0;j<img->w;j++)
					VAL(img,i,j) = VAL(src,j,src->w-1-i);
			break;
		
		case 180 :

			for(i=0;i<img->h;i++)
				for(j=0;j<img->w;j++)
					VAL(img,i,j) = VAL(src,src->h-1-i,src->w-1-j);
			break;

		case 270 :
		img->h=src->w;
		img->w=src->h;
			for(i=0;i<img->h;i++)
				for(j=0;j<img->w;j++)
					VAL(img,i,j) = VAL(src,src->h-1-j,i);
			break;
		default :
			fprintf(stderr,"INVALID ANGLE\n");
	}
	return img;
	}

image_t *modifier_lumin(image_t *src, int pourcent)
	{
	double x = pourcent/100.0;
	int i,j;	
	image_t * img = copier_image(src);


		for(i=0;i<img->h;i++){
			for(j=0;j<img->w;j++){
				if(x>1){
					if(VAL(img,i,j)*x >255)
						VAL(img,i,j)=255;
					else
						VAL(img,i,j)*=x;
				}

				if(x<1){
					
					if(VAL(img,i,j)*x <0)
						VAL(img,i,j)=0;
					else
						VAL(img,i,j)*=x;
				}
				
			}
		}
	
	return img;
	}

image_t *bruiter_image(image_t *src, int pourcent)
	{
		image_t * img = copier_image(src);
		srand (time (NULL)); 
			for(int i=0;i<img->h;i++){
				for(int j=0;j<img->w;j++){			
					double nb = rand() % 100;
					if(nb<pourcent)
						VAL(img,i,j) = rand() % 256;
				}
			}

	return img;
	}

image_t *filtrer_median(image_t *src)
	{
	image_t * img = copier_image(src);
	int TEMP[21];
	int x,c,d;
	for(int i=0;i<img->h;i++){
		for(int j=0;j<img->w;j++){
			x=0;

			for(int k=-2;k<=2;k++){
				for(int l=-2;l<=2;l++){
					c=i+k; d=j+l;
					
					if(!(((k==-2)&&(l==-2))||((k==-2)&&(l==2))||((k==2)&&(l==-2))||((k==2)&&(l==2)))){
						if(c<0)
					 		c=0;
						if(d<0)
							d=0;
						if(c>img->h-1)
							c=img->h-1;
						if(d>img->w-1)
							d=img->w-1;
						TEMP[x++] = VAL(src,c,d);				
						//fprintf(stderr, " %d \n", x);	
					}

				}
			}
				triRapideAmeliore(TEMP,0,20);	
				VAL(img,i,j) = TEMP[9];
			

		}

	}
	return img;
	}

image_t *convoluer(image_t *src, noyau_t *pn)
	{
		image_t * img = copier_image(src);
		int a,b,c,d,s=0,total,demidim =pn->dim/2;
		for(int i=0;i<pn->dim;i++)
			for(int j=0;j<pn->dim;j++)
				s+=VAL_N(pn,i,j);

		if(s==0)
			s=1;
		
		
		for(int i=0;i<img->h;i++){
			for(int j=0;j<img->w;j++){
				a=0;total=0;
				//fprintf(stderr, "avant for k: %d limite: %d \n", -demidim, demidim);
				for(int k=-demidim;k<=demidim;k++){
					b=0;
					//fprintf(stderr, "k: %d limite: %d \n", k, pn->dim/2);
					for(int l=-demidim;l<=demidim;l++){
						c=i+k; d=j+l;
						if(c<0)
							c=0;
						if(d<0)
							d=0;
						if(c>img->h-1)
							c=img->h-1;
						if(d>img->w-1)
							d=img->w-1;

						total += VAL_N(pn,a,b)*VAL(src,c,d);   

					
						

						//fprintf(stderr,"VAL(i j): %d %d %d %d %d %d \n", a,b,c,d,  VAL_N(pn,a,b),VAL(img,c,d)) ;
						b++;
					}
					
					a++;	
				}
				//fprintf(stderr,"totale :%d\n",total);
				total=total/s;
				//fprintf(stderr,"ttl---------------------- %d\n",total);
				if(total<=255){
					if(total<0)
						VAL(img,i,j) = -total;
					else
						VAL(img,i,j) = total;

				}


			}

		}
		

	return img;
	}
