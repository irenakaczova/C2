#include<stdio.h>
#include<stdarg.h>

void my_pritnf(char *retezec,...){
    va_list parametry;
    va_start(parametry,retezec);

    for(int i=0;retezec[i]!='\0';i++){
        if(retezec[i]!='*'){
            printf("%c",retezec[i]);continue;}
        else i++;
        if(retezec[i]=='i')
            printf("%i",va_arg(parametry,int));
        else if(retezec[i]=='c')
            printf("%c",(char)va_arg(parametry,int));
        else printf("%f",va_arg(parametry,double));}
        va_end(parametry);}

int main(int argc,char *argv[]){
    int cislo1=2;
    int cislo2=11;
    int cislo3=4;
    int cislo4=2021;
    int znak=',';
    double desetinne_cislo=1.234567;

    my_pritnf("Bonusovy ukol *i*c *i.*i.*i (*f)",
        cislo1,znak,cislo2,cislo3,cislo4,desetinne_cislo);

return 0;}