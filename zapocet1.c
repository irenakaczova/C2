#include<stdio.h>
#include<stdlib.h>
int delka_retezce(char*);
void otoc(char*);
char *vetsi_cislo(char*,char*,int,int,int);
int spravnost_retezce(char*);
int spravnost_znaku(char*);
int spravnost_znaku_1(char *);
char *secti_cisla(char*,char*);

//delka retezce
int delka_retezce(char *retezec){
    int delka=0;
    for(int i=0;*(retezec+i)!='\0';i++){
        delka+=1;}
return delka;}

//otoceni retezce
void otoc(char *retezec){
    int delka=delka_retezce(retezec);
    int p;
    for(int i=0,j=delka-1;i<delka/2;i++,j--){
        p=*(retezec+i);
        *(retezec+i)=*(retezec+j);
        *(retezec+j)=p;}}

//porovnani abs. hodnot dvou cisel zadanych text.r.
char *vetsi_cislo(char *cislo1,char *cislo2,int delka1,int delka2,int delka){                                          
    char *vysledek=cislo1,*pomocnik_posun1=NULL,*pomocnik_posun2=NULL;
    if(delka1>delka2){return vysledek;}
    else if(delka1<delka2){return cislo2;}
    if(*cislo1=='-'){pomocnik_posun1=cislo1+1;}   
    if(*cislo2=='-'){pomocnik_posun2=cislo2+1;}  
    if(pomocnik_posun1!=NULL){cislo1=pomocnik_posun1;}
    if(pomocnik_posun2!=NULL){cislo2=pomocnik_posun2;}

    for(int i=0;i<delka;i++){
        if((*(cislo1+i)-'0')>(*(cislo2+i)-'0')){
            if(cislo1==pomocnik_posun1){vysledek=cislo1-1;}
            else{vysledek=cislo1;}
            break;}
        else if ((*(cislo1+i)-'0')<(*(cislo2+i)-'0')){
            if(cislo2==pomocnik_posun2){vysledek=cislo2-1;}
            else{vysledek=cislo2;}
            break;}}    
return vysledek;}       

//overeni spravnosti znaku v retezci od indexu 1 po konec retezce
int spravnost_retezce(char *retezec){
    int vysledek=0;
    char cisla[]="0123456789";
    for(int i=1;*(retezec+i)!='\0';i++){
        vysledek=0;
        for(int j=0;cisla[j]!='\0';j++){
            if(retezec[i]==cisla[j]){
               vysledek=1;break;}}
        if(vysledek==0)break;}
return vysledek;}

//overeni spravnosti znaku v delsim retezci na pozici 0 
int spravnost_znaku(char *retezec){
    int vysledek=0;
    char povolene[]="-123456789";
    for(int j=0;povolene[j]!='\0';j++){
        if(*retezec==povolene[j]){
        vysledek=1;break;}}
return vysledek;}

//overeni spravnosti znaku v retezci s delkou 1 na pozici 0
int spravnost_znaku_1(char *retezec){
    int vysledek=0;
    char povolene[]="0123456789";
    for(int j=0;povolene[j]!='\0';j++){
        if(*retezec==povolene[j]){
        vysledek=1;break;}}
return vysledek;}

//soucet dvou cisel zadanych text.r.
char *secti_cisla(char *cislo1,char *cislo2){
    int delka1=delka_retezce(cislo1);
    int delka2=delka_retezce(cislo2);
    int delka_souctu,delsi,kratsi,velikost;
    char *delsi_retezec,*pomocny_retezec;

    //testy na vstupy
    if((delka1>1)&&((spravnost_znaku(cislo1)==0)||(spravnost_retezce(cislo1)==0))) return NULL;
    else if((delka1<=1)&&(spravnost_znaku_1(cislo1)==0)) return NULL;

    if((delka2>1)&&((spravnost_znaku(cislo2)==0)||(spravnost_retezce(cislo2)==0))) return NULL;
    else if((delka2<=1)&&(spravnost_znaku_1(cislo2)==0)) return NULL;

    if(*cislo1=='-'){
        if(*(cislo1+1)=='0') return NULL;
        else delka1--;}

    if(*cislo2=='-'){
        if(*(cislo2+1)=='0') return NULL;
        else delka2--;}

    //porovnani delky a hodnot retezcu, urceni cisla s vetsi abs.hodnotou
    if(delka1>delka2){delsi=delka1;kratsi=delka2;delsi_retezec=cislo1;}
    else{delsi=delka2;kratsi=delka1;delsi_retezec=cislo2;}

    if((*cislo1=='-')||(*cislo2=='-')){
        pomocny_retezec=cislo1;
        cislo1=vetsi_cislo(cislo1,cislo2,delka1,delka2,kratsi);
        if(cislo1==cislo2){
            cislo2=pomocny_retezec;}
        else if(cislo1==NULL) cislo1=pomocny_retezec;}

    velikost=delsi+2;
    char *soucet=(char *)malloc(sizeof(char)*velikost);

    //soucet jednotlivych cisel
    if(((*cislo1!='-')&&(*cislo2!='-'))||((*cislo1=='-')&&(*cislo2=='-'))){
        otoc(cislo1);
        otoc(cislo2);
        int zbytek=0;
    
        for(int i=0;i<delsi;i++){
            if(i>=kratsi){
                 *(soucet+i)=(((*(delsi_retezec+i)-'0')+zbytek)%10)+'0';
                 zbytek=((*(delsi_retezec+i)-'0')+zbytek)/10;}
             else{*(soucet+i)=(((*(cislo1+i)-'0')+(*(cislo2+i)-'0')+zbytek)%10)+'0';
                 zbytek=((*(cislo1+i)-'0')+(*(cislo2+i)-'0')+zbytek)/10;}}
    
    if(zbytek!=0){*(soucet+delsi)=zbytek%10+'0';*(soucet+delsi+1)='\0';}
    else*(soucet+delsi)='\0';}

    //nebo rozdil jednotlivych cisel 
    else{
        otoc(cislo1);
        otoc(cislo2);
        int zbytek=0,i=0;
        int mezivysledek;

        for(i=0;i<delsi;i++){
            if(i>=kratsi){
                 mezivysledek=(((*(delsi_retezec+i)-'0')+zbytek)%10)+'0';
                 zbytek=((*(delsi_retezec+i)-'0')+zbytek)/10;}
            else{
                mezivysledek=(((*(cislo1+i)-'0')-(*(cislo2+i)-'0')+zbytek)%10)+'0'; 
                zbytek=((*(cislo1+i)-'0')-(*(cislo2+i)-'0')+zbytek)/10;}
            if(mezivysledek<'0'){
                *(soucet+i)=mezivysledek+10;
                zbytek--;}
            else{*(soucet+i)=mezivysledek;}}
    
    if(zbytek!=0){*(soucet+i)=zbytek%10+'0';*(soucet+i+1)='\0';}
    else*(soucet+i)='\0';}

    //finalni upravy
    otoc(cislo1);
    otoc(cislo2);
    otoc(soucet);
    delka_souctu=delka_retezce(soucet);

    if((delka_souctu==1)&&(*soucet=='0')) return soucet;

    for(int i=0;i<=delka_souctu;i++){
        if(*(soucet+i)=='0')
            soucet=soucet+1;
        else break;}

    delka_souctu=delka_retezce(soucet);
    if((delka_souctu==1)&&(*soucet=='0')) return soucet;
    
    //pridani znaku minus
    if(*cislo1=='-'){
        if(*soucet=='0'){
            *soucet='-';}
        else{*(soucet-1)='-';
            soucet=soucet-1;}}

    //odstraneni nuly na zacatku pri kladnem vysledku
    if(*soucet=='0'){
        soucet=soucet+1;}
    
    return soucet;}

int main(){
    char cislo1[]="000012";
    char cislo2[]="-9"; 
    char *vysledek;

    vysledek=secti_cisla(cislo1,cislo2);
    printf("%s + %s = %s\n",cislo1,cislo2,vysledek);
    free(vysledek);                                

return 0;}