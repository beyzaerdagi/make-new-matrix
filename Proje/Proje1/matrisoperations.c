/*
    @proje1
    @matrislerden islemlere gore yeni matris olusturma
    @08.12.2021
*/
#include <stdio.h>
#include <stdlib.h>
#include "matrisoperations.h"

//yeni olusucak matrisin boyutunu geri donduren method
int matematikselHesaplamalar(int matris1Boyut, int matris2Boyut){

    return (matris1Boyut - matris2Boyut +1);
}

//islem tipi 1 olunca dolgu degerine gore matris1 in etrafına 0 elemanları koyulur
int **yeniMatris1Olusturma(int **matris,int matrisBoyut,int dolgu){

    int yeniMatrisBoyut = matrisBoyut + 2 * dolgu;
    //dinamik olarak heap de yeni matris olusturulur
    int **yeniMatris1 = (int**)malloc(yeniMatrisBoyut * sizeof(int*));
    //matrisin elemanlari dinamik olarak heap de olusturulur
    for (int i = 0; i < yeniMatrisBoyut; i++)
        *(yeniMatris1+i) = (int*)malloc(yeniMatrisBoyut * sizeof(int));

    //dolgu degeri 1 ise matris1 in etrafi 1 kere cerceve yapilir
    if(dolgu == 1){
        for(int h=0;h<yeniMatrisBoyut;h++){
            for(int c=0;c<yeniMatrisBoyut;c++){
                if(h == 0 || h == yeniMatrisBoyut-1 || c == 0 || c == yeniMatrisBoyut-1){
                    *(*(yeniMatris1+h)+c) = 0;
                }else{
                    *(*(yeniMatris1+h)+c) = *(*(matris+h-1)+c-1);
                }
            }
        }
    //dolgu degeri 2 ise matris1 in etrafi 2 kere cerceve yapilir
    }else if(dolgu == 2){
        for(int h=0;h<yeniMatrisBoyut;h++){
            for(int c=0;c<yeniMatrisBoyut;c++){
                if(h == 0 || h == 1 || h == yeniMatrisBoyut-1 || c == 0 || c == yeniMatrisBoyut-1
                || h == yeniMatrisBoyut-2 || c == 1 || c == yeniMatrisBoyut-2){
                   *(*(yeniMatris1+h)+c) = 0;
                }else{
                    *(*(yeniMatris1+h)+c) = *(*(matris+h-2)+c-2);
                }
            }
        }
    }
    //olusan yeni matris1 return edilir
    return yeniMatris1;
}

int **operasyon1(int **matris1,int matris1Boyut,int **matris2,int matris2Boyut){

    int yeniMatrisBoyut = matematikselHesaplamalar(matris1Boyut,matris2Boyut);
    //dinamik olarak heap de yeni matris olusturulur
    int** yeniMatris = (int**)malloc(yeniMatrisBoyut * sizeof(int*));
    //matrisin elemanlari dinamik olarak heap de olusturulur
    for (int i = 0; i < yeniMatrisBoyut; i++)
        *(yeniMatris+i) = (int*)malloc(yeniMatrisBoyut * sizeof(int));

    //matris1 in elemanlari gruplanarak tmpMatrise gecici olarak eklenir
    int tmpMatris[matris2Boyut][matris2Boyut];
    int i=0,j=0,yeniRow=0,yeniColumn=0,matris2R,matris2C,matris1C=0,matris1R=0;

    //matris1 in boyutuna gelince yeniMatrisi olusturma islemi tamamlanir
    while(matris1R + matris2Boyut <= matris1Boyut){
        for(matris2R=0;matris2R<matris2Boyut;matris2R++){ 
            for(matris2C=0;matris2C<matris2Boyut;matris2C++){
                //olusan gruba gore matris1 in elemanlari tmpMatrise eklenir
                *(*(tmpMatris+matris2R)+matris2C) = *(*(matris1+i)+j);
                j++;
            }
            j=matris1C;
            i++;
        }
        matris1C++;
        //matris1 in boyutuna gelince j 0 lanır ve i +1 eklenir 
        if(matris1C+matris2Boyut <= matris1Boyut){ 
            i=matris1R;
            j++;
        }else{
            matris1R++;
            i=matris1R;
            j=0;
            matris1C=0;
        }
        int sum = 0;
        //tmpMatrise atama islemi bittikten sonra elemanlar matris2 ile carpilir ve toplanir
        for(int k=0;k<matris2Boyut;k++){
            for(int r=0;r<matris2Boyut;r++){
                sum += *(*(tmpMatris+k)+r) * *(*(matris2+k)+r);
            }
        }
        //carpma ve toplama islemleri tamamlandiktan sonra yeniMatrisin elemani olarak atanir
        if(yeniColumn<yeniMatrisBoyut){
            *(*(yeniMatris+yeniRow)+yeniColumn) = sum;
            yeniColumn++;
        }else{
            yeniRow++;
            yeniColumn=0;
            *(*(yeniMatris+yeniRow)+yeniColumn) = sum;
            yeniColumn++;
        }
    }
    //yeni olusan matris return edilir
    return yeniMatris;
}

