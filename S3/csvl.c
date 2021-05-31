#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int compte_mots_chaine(char *chaine) {
	int i=0,x=0,len=strlen(chaine);
	while(i<len){

		while(chaine[i] == ' ')
			i++;
		if(chaine[i] != ' '){
			x++;
		while(chaine[i] != ' ')
			i++;
		
		}
	
	}
		if(chaine[len-1] == ' ')
			x--;
return x;
}


int compte_mots(char **ptab_mots)
{
	int x=0;
	char ** p = ptab_mots;
	while(*p != NULL){
		x++;
		p+=1;
	

	}
	return x;
	
}

void affiche_tab_mots(char **ptab_mots)
{

	char ** p = ptab_mots;
	while(*p != NULL){
		printf("%s\n",*p);
		p+=1;
	
	}
}

char **detruit_tab_mots(char **ptab_mots)
{

	int i;

	for(i=0;i<compte_mots(ptab_mots);i++){
		free(ptab_mots[i]);
	}
        free(ptab_mots);

	return ptab_mots;
}

char **decompose_chaine(char *chaine)
{
	int i=0,j=0,x=0;
	if(compte_mots_chaine(chaine) == 0)
		return NULL;
	else{
	char ** tMots = malloc((compte_mots_chaine(chaine)+1)*sizeof(char*));	
	i=0;

	while(i<strlen(chaine)){
		while((chaine[i] != ' ')&&(i<strlen(chaine))){
			x++;
			i++;	
		}

			if(x!=0){
				tMots[j] = malloc((x+1)*sizeof(char));
				memcpy(tMots[j],chaine+i-x,x);
				tMots[j][x]= '\0';
				j++;
				x=0;
			}
		i++;
	}
	
  		tMots[j] = NULL;
  		return tMots;
	}

}

char *compose_chaine(char **ptab_mots)
{
	char * c = malloc(compte_mots(ptab_mots)*10*sizeof(char));
	char ** p = ptab_mots;

	
	strcpy(c,*p);
	while(*(p+1) != NULL){	
	strcat(c," ");
	strcat(c,*(p+1));
	p+=1;
	}
	return c;
}


		




char **reduit_tab_mots(char **ptab_mots)
{
	char ** p = ptab_mots,**q;
	while(*p != NULL){
		q=p+1;
		while(*q!=NULL){
			if(!strcmp(*p,*q)){
				free(*q);
				*q = *p;
			}	
			q+=1;		
		}
			p+=1;
	}	
	return ptab_mots;
}
