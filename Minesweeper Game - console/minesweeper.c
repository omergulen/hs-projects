#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void menu(void);
int olustur(int[20][20],int);
void yaz(char[20][20],int,int);
void ac(int[20][20],char[20][20],int,int);

int main()
{
    int tarla[20][20] = {0},secim,f,o,bir=0,iki=0,yon=0,say1=0,say2=0,knz,sag=0,asagi=0;

    char goster[20][20];

    srand(time(NULL));
    
    FILE *dosya;
    
    for(f=0;f<20;f++){
       for(o=0;o<20;o++){
          goster[f][o] = 37;

       }
    }
                       
    while(secim != 3){

    menu();

    scanf("%d",&secim);

    switch(secim){
    			  case 2:
						dosya = fopen("C:/Users/CubuKKrakeR/Documents/M.Tarlasi.txt","r");
						
						fscanf(dosya,"%s",goster);
						
						for(f=0;f<20;f++){
                           for(o=0;o<20;o++){
                              fscanf(dosya,"%d",&tarla[f][o]);
                              tarla[f][o] = (tarla[f][o]/5-6100)/85-2;
                           }
                        }
                        
                        fscanf(dosya,"%d",&say1);
						
						fclose (dosya);
						
                  case 1:
                       if(secim == 1){
					   printf("----------------Chootti & Caillou----------------\n");
					   printf("1 - Kolay\n2 - Normal\n3 - Zor\n: ");
					   scanf("%d",&knz);
					   if(knz == 1)
					   	knz = 20;
					   else if(knz == 2)
					   	knz = 15;
					   else if(knz == 3)
					   	knz = 10;	
					   
					   say1 = olustur(tarla,knz);
					   
                       goster[bir][iki] = ('#');
                       
					   }
                  	   printf("------------------------------------------------------\n");
					   		
					   
                       yaz(goster,sag,asagi);

                       while(yon != -21){

                       yon = getch() -48 ;
					   
					   system("cls");
					   
					   printf("\n");
					
                       say2 = 0;

                       if(goster[bir][iki] != tarla[bir][iki] + 48 && goster[bir][iki] != ('!'))
                           goster[bir][iki] = 37;

                       switch(yon){
                             case 24:

                                if(bir==0){
                                    bir= 20;
                                    sag=20;
                                }
                                bir--;
                                sag--;
                                
                                break;
                             case 32:

                                if(bir==19){
                                	bir= -1;
                                	sag= -1;
                                }
                                    
                                bir++;
								sag++;

                                break;
                             case 27:

                                if(iki==0){
                                	iki= 20;
                                	asagi=20;
                                }
                                    
                                iki--;
                                asagi--;

                                break;
                             case 29:

                                if(iki==19){
                                	iki= -1;
                                	asagi= -1;
                                }
                                    
                                iki++;
                                asagi++;
                                break;

                              case -35:

                                if(tarla[bir][iki] == 0){

                                    ac(tarla,goster,bir,iki);
                                    
                                    for(f=0;f<20;f++){
       									for(o=0;o<20;o++){
          									if(goster[f][o] == 48)
            									goster[f][o] = 46;

										}
									}

                                    goster[bir][iki] = tarla[bir][iki] + 48;

                                }
                                else if(tarla[bir][iki] < 9){
                                    goster[bir][iki] = tarla[bir][iki] + 48;
                                }
                                else if(tarla[bir][iki] == 9){
                                    for(f=0;f<20;f++){
                                        for(o=0;o<20;o++){
                                            if(tarla[f][o] == 9)
                                                goster[f][o] = ('*');
                                        }
                                    }

                                    yaz(goster,sag,asagi);

                                    printf("\nUzgunum kaybettiniz...\n");
									
									dosya = fopen("C:/Users/CubuKKrakeR/Documents/M.Tarlasi.txt","w");
                              	
                              		fputc(' ',dosya);
                              	
                                    getch();
                                    return 0;
                                    }

                                break;

                              case 0:
                              if(goster[bir][iki] == ('!'))
                                  goster[bir][iki] = ('#');
                              else if(goster[bir][iki] == ('%'))
                                goster[bir][iki] = ('!');

                              break ;
                              case -21:
                              	yaz(goster,sag,asagi);
                              	
                              	dosya = fopen("C:/Users/CubuKKrakeR/Documents/M.Tarlasi.txt","w");
                              	
                              	fprintf(dosya,"%s",goster);
                              	
                              	fputc(' ',dosya);
                              	
								for(f=0;f<20;f++){
                                   for(o=0;o<20;o++){
                              			fprintf(dosya,"%d",((tarla[f][o]+2)*85+6100)*5);
                              			fputc(' ',dosya);
                              		}
                              	}
                              	
                              	fprintf(dosya,"%d",say1);
                              	
								fclose(dosya);
                              	
                                printf("\nKaydedilmistir.\n");
                                getch();
                                return 0;
                       }

                       if(goster[bir][iki] == ('!')){
                           yaz(goster,sag,asagi);
                       }

                       else if(goster[bir][iki] != tarla[bir][iki] + 48){
                           goster[bir][iki] = ('#');
                           yaz(goster,sag,asagi);
                       }
                       else{
                           goster[bir][iki] = ('+');
                           yaz(goster,sag,asagi);
                           goster[bir][iki] = tarla[bir][iki] + 48;
                       }

                       for(f=0;f<20;f++){
                          for(o=0;o<20;o++){
                              if(goster[f][o] > 59 || goster[f][o] < 45)
                                  say2++;
                          }
                       }

                       if(say1 == say2){
                           printf("\nTebrikler.Kazandiniz!\n");
                           getch() ;
                           return 0;
                       }

                       }

                       break;
                  
                  case 3:
                       getch();
                       return 0;
                  }

    }
	

    getch();
    return 0;
}

void menu(){

    printf("------------------------------------------------------\n");
    printf("------------------ Mayin Tarlasi -----CubuKKrakeR ©---\n");
    printf("------------------------------------------------------\n");
    printf("----------------- 1 - Yeni oyun              ---------\n");
    printf("----------------- 2 - Kayitli oyuna devam et ---------\n");
    printf("----------------- 3 - Cikis                  ---------\n");
    printf("------------------------------------------------------\n");

}

void yaz(char t[20][20],int asa,int sa){
     int f,o;

     for(f=0;f<20;f++){
               for(o=0;o<20;o++){
                  printf("%c ",t[f][o]);
               }
               if(f==asa)
               	printf("<--");
               	
               printf("\n");
           }
           
	 for(f=0;f<20;f++){
	 		if(f!=0)
			 printf(" ");
	 		if(f == sa)
	 			printf("^");
	 		printf(" ");
	 	}
	 	printf("\n");	 	
	 	for(f=0;f<20;f++){
	 		if(f!=0)
			 printf(" ");
	 		if(f == sa)
	 			printf("|");
	 		printf(" ");
	 }
	



}

int olustur(int tarla[20][20],int knz){

    int mayin,f,o,say=0;

    for(f=0;f<20;f++){
              for(o=0;o<20;o++){
                                mayin = (rand() % knz) + 1;
                                if(mayin == 5){
                                    tarla[f][o] = 9;
                                    if(tarla[f-1][o-1] != 9 && f != 0 && o != 0)
                                        tarla[f-1][o-1]++;
                                    if(tarla[f-1][o] != 9 && f != 0)
                                        tarla[f-1][o]++;
                                    if(tarla[f-1][o+1] != 9 && f != 0 && o != 19)
                                        tarla[f-1][o+1]++;
                                    if(tarla[f][o+1] != 9 && o!= 19)
                                        tarla[f][o+1]++;
                                    if(tarla[f+1][o+1] != 9 && f != 19 && o != 19)
                                        tarla[f+1][o+1]++;
                                    if(tarla[f+1][o] != 9 && f != 19)
                                        tarla[f+1][o]++;
                                    if(tarla[f+1][o-1] != 9 && f != 19 && o != 0)
                                        tarla[f+1][o-1]++;
                                    if(tarla[f][o-1] != 9 && o != 0)
                                        tarla[f][o-1]++;
                                    say++;

                                }

             }

    }

return say;

}

void ac(int t[20][20],char g[20][20],int f,int o){

    t[f][o] = -2;

    if(t[f-1][o-1] != 9 && f != 0 && o != 0){
        g[f-1][o-1] = t[f-1][o-1] + 48;
        if(t[f-1][o-1] == 0)
            ac(t,g,f-1,o-1);
    }
    if(t[f-1][o] != 9 && f != 0){
        g[f-1][o] = t[f-1][o] + 48;
        if(t[f-1][o] == 0)
            ac(t,g,f-1,o);
    }
    if(t[f-1][o+1] != 9 && f != 0 && o != 19){
        g[f-1][o+1] = t[f-1][o+1] + 48;
        if(t[f-1][o+1] == 0)
            ac(t,g,f-1,o+1);
    }

    if(t[f][o+1] != 9 && o!= 19){
        g[f][o+1] = t[f][o+1] + 48;
        if(t[f][o+1] == 0)
            ac(t,g,f,o+1);
    }

    if(t[f+1][o+1] != 9 && f != 19 && o != 19){
        g[f+1][o+1] = t[f+1][o+1] + 48;
        if(t[f+1][o+1] == 0)
            ac(t,g,f+1,o+1);
    }

    if(t[f+1][o] != 9 && f != 19){
        g[f+1][o] = t[f+1][o] + 48;
        if(t[f+1][o] == 0)
            ac(t,g,f+1,o);
    }

    if(t[f+1][o-1] != 9 && f != 19 && o != 0){
        g[f+1][o-1] = t[f+1][o-1] + 48;
        if(t[f+1][o-1] == 0)
            ac(t,g,f+1,o-1);
    }

    if(t[f][o-1] != 9 && o != 0){
        g[f][o-1] = t[f][o-1] + 48;
        if(t[f][o-1] == 0)
            ac(t,g,f,o-1);
    }
    
}

