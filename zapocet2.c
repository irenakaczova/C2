#include<stdio.h>
#include<stdlib.h>
#define MAX_JMENO 10
#define MAX_PRIJIMENI 20

typedef struct{
    char jmeno[MAX_JMENO+1];                                                                         //oprava velikost pole
    char prijimeni[MAX_PRIJIMENI+1];                                                                 //tady taky
    int vek;                                                                          
}clovek;

void vypis_pole(clovek *pole,int pocet){
    int i;
    for(i=0;i<pocet;i++)
        printf("%s %s %i\n",pole[i].jmeno,pole[i].prijimeni,pole[i].vek);}

//fce nacte soubor do pole strukturovaneho datoveho typu clovek
clovek* nacti_csv(char *soubor, int *pocet){
    clovek *vysledek=(clovek*)malloc(sizeof(clovek));
    if(vysledek==NULL){                                                                             //oprava kontrola alokace
        printf("chyba pri alokaci");return NULL;}                               
    FILE *fr;
    char c='s';
    int i;*pocet=0;                                                                                //oprava pocet na 0
   
   if((fr=fopen(soubor,"rt"))==NULL){
        printf("soubor .csv se nepodarilo otevrit\n");free(vysledek);                             //oprava uvolneni pamete
        return NULL;}

    while(c!=EOF){
        while(((c=getc(fr))!='\n')&&c!=EOF){
            i=0;
            while(c!=';'){
                vysledek[*pocet].jmeno[i]=c;
                c=getc(fr);i++;}
            vysledek[*pocet].jmeno[i]='\0';i=0;
            while((c=getc(fr))!=';'){
               vysledek[*pocet].prijimeni[i]=c;i++;}
            vysledek[*pocet].prijimeni[i]='\0';
            fscanf(fr,"%i",&vysledek[*pocet].vek);}
            *pocet=*pocet+1;
            vysledek=realloc(vysledek,sizeof(clovek)*(*pocet+1));
            if(vysledek==NULL){                                                                   //oprava kontrola alokace
                printf("chyba pri alokaci");return NULL;}}
    
    if(fclose(fr)==EOF)
        printf("soubor .csv se nepodarilo zavrit\n");

    return vysledek;}

int main(){
    char soubor[]="data_mensi.csv";
    int pocet=0,*p_pocet;
    p_pocet=&pocet;
    clovek *vysledek=(nacti_csv(soubor,p_pocet));

    vypis_pole(vysledek,pocet);
    free(vysledek);

    return 0;}