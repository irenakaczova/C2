#include<stdio.h>

char *bonus(char *text, char *podretezec){
    char *vysledek=NULL;
    for(int i=0;*(text+i)!='\0';i++){                               //prechadzame prvky textu do konca retezca
        if(*(text+i)==*podretezec){                                 //porovnavame s prvym prvkom podretezca        
            for(int j=0;*(podretezec+j)!='\0';j++){                 //testujeme ci sa prvky textu od daneho indexu rovnaju prvkom podretezca
                if(*(text+i+j)!=*(podretezec+j)){                   //ak najdeme rozdielne prvky
                    vysledek=NULL;bonus(text+i+j,podretezec);}      //nastavime hodnotu vysledku na NULL a rekurzivne zavolame fci na text od daneho indexu
                else vysledek=text+i;}                              //ak sa rovnaju, vysledek ukazuje na prvek textu o indexu i,na ktorom sme zacali test a pokracujeme
            if(vysledek!=NULL) return vysledek;}}                   //ak sme dokoncili cyklus a vsetky prvky sa rovnaju, skoncime a vratime vysledok
return vysledek;}                                                   //ak text neobsahuje podretezec vratime NULL

int main(){
/*  char r1[]="ahoj sveter";
    char r2[]="svete";
    
   printf("%p\n",bonus(r1,r2));
   printf("%c\n",*bonus(r1,r2)); */
    return 0;}
