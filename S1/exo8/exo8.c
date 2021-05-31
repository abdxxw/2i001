#include <stdio.h>
#include <stdlib.h>
#define DIM 8
int i,j;
void afficher_lab(int lab[DIM][DIM], char palette[]){
   printf("+--------+\n");
   for(i=0;i<DIM;i++){
  printf("|");
	for(j=0;j<DIM;j++){
		printf("%c",palette[lab[i][j]]);

}
		printf("|\n");
}
   printf("+--------+\n");
}



int chercher_chemin_rec(int lab[DIM][DIM], int lc, int cc){



lab[lc][cc]=2;

if ((lab[lc+1][cc] != 0 )&&(lab[lc][cc+1] != 0)&&(lab[lc-1][cc] != 0)&&(lab[lc][cc-1] = 0))
	return 0;

if((lc == DIM-1)&& (cc == DIM-1))
 return 1;

if((lab[lc][cc+1] == 0)&&(cc+1<DIM))
 return chercher_chemin_rec(lab,lc,cc+1);
else if((lab[lc+1][cc] == 0)&&(lc+1<DIM))
 return chercher_chemin_rec(lab,lc+1,cc);
else if((lab[lc][cc-1] == 0)&&(cc-1>=0))
 return chercher_chemin_rec(lab,lc,cc-1);
else if((lab[lc-1][cc] == 0)&&(lc-1>=0))
 return chercher_chemin_rec(lab,lc-1,cc);
else {lab[lc][cc] = 3;


}
  return 0;

}






int chercher_chemin(int lab[DIM][DIM]){

return chercher_chemin_rec(lab,0,0);
}



int main(){

char palette[2] = {' ','*'};
int laby[DIM][DIM] = {{0,0,1,0,0,0,1,1},{1,0,0,1,1,0,1,0},{1,0,1,1,1,0,0,0},{1,0,0,1,0,0,1,1},{0,1,0,0,0,1,0,1},{0,0,0,1,0,1,0,1},{1,1,1,1,0,0,0,0},{1,0,1,1,0,0,0,0}};


afficher_lab(laby,palette);

printf("%d\n",chercher_chemin(laby));

int i,j;
for(i=0;i<DIM;i++){
	for(j=0;j<DIM;j++){
		printf("%d",laby[i][j]);
}
printf("\n");
}

return 0;
}

