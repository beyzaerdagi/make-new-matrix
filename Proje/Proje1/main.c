/*
    @proje1
    @matrislerden islemlere gore yeni matris olusturma
    @08.12.2021
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrisoperations.h"

int main(int argc, char *argv[]){

    if(argc < 5){
        printf("Eksik arguman girdiniz");
        exit(1);
    }else if(argc > 5){
        printf("Fazla arguman girdiniz");
        exit(1);
    }else{
        
        int matris1Boyut = atoi(argv[1]);
        int matris2Boyut = atoi(argv[2]);
        int islemTipi = atoi(argv[3]);
        int seedDeger = atoi(argv[4]);
        int **matris1, **matris2, **yeniOlusanMatris;
        int yeniOlusanMatrisBoyut;

        if(matris2Boyut != 3 && matris2Boyut != 5){
            printf("Matris2 boyutu sadece 3 veya 5 olabilir");
            exit(1);
        }
        if(matris1Boyut % 2 == 0){
            printf("Matris1 in boyutu tek sayi olmalidir");
            exit(1);
        }else if(matris1Boyut <= matris2Boyut){
            printf("Matris1 in boyutu matris2 den buyuk olmalidir");
            exit(1);
        }
        if(islemTipi != 0 && islemTipi != 1){
            printf("Islem tipi sadece 0 veya 1 olabilir");
            exit(1);
        }
        //dinamik olarak heap de yeni matris olusturulur
        matris2 = (int **)malloc(matris2Boyut * sizeof(int *));
        //matrisin elemanlari dinamik olarak heap de olusur
        for (int i = 0; i < matris2Boyut; i++)
            *(matris2 + i) = (int *)malloc(matris2Boyut * sizeof(int));

        //matris2 nin elemanlari random(1-10 arasi) bir sekilde olusturulur
        srand(seedDeger);
        for (int i = 0; i < matris2Boyut; i++){
            for (int j = 0; j < matris2Boyut; j++){
                *(*(matris2 + i) + j) = (rand() % 10) + 1;
            }
        }
        printf("\n");
        printf("*********Olusan 2.matris*********\n");
        printf("\n");
        //matris2 nin elemanlari ekrana yazdirilir
        for (int i = 0; i < matris2Boyut; i++){
            for (int j = 0; j < matris2Boyut; j++){
                printf("%5d      ", *(*(matris2 + i) + j));
            }
            printf("\n");
        }
        matris1 = (int **)malloc(matris1Boyut * sizeof(int *));
        for (int i = 0; i < matris1Boyut; i++)
            *(matris1 + i) = (int *)malloc(matris1Boyut * sizeof(int));

        //matris1 nin elemanlari random(1-10 arasi) bir sekilde olusturulur
        srand(seedDeger);
        for (int i = 0; i < matris1Boyut; i++){
            for (int j = 0; j < matris1Boyut; j++){
                *(*(matris1 + i) + j) = (rand() % 10) + 1;
            }
        }
        //islem tipine gore matrisler operasyon1 e gonderilir
        if (islemTipi == 0){
            printf("\n");
            printf("*********Olusan 1.matris*********\n");
            printf("\n");
            for (int i = 0; i < matris1Boyut; i++){
                for (int j = 0; j < matris1Boyut; j++){
                    printf("%5d      ", *(*(matris1 + i) + j));
                }
                printf("\n");
            }
            yeniOlusanMatris = operasyon1(matris1, matris1Boyut, matris2, matris2Boyut);
            yeniOlusanMatrisBoyut = matematikselHesaplamalar(matris1Boyut, matris2Boyut);
        }else{
            //yeniMatris1 ve yeniMatris icin dolgu degeri hesaplanir
            int dolgu = (matris2Boyut - 1) / 2;
            int yeniMatris1Boyut = matris1Boyut + 2 * dolgu;
            //yeniMatris1 olusturulur
            int **yeniMatris1 = yeniMatris1Olusturma(matris1, matris1Boyut, dolgu);
            printf("\n");
            printf("*********Olusan 1.matris*********\n");
            printf("\n");
            for (int i = 0; i < yeniMatris1Boyut; i++){
                for (int j = 0; j < yeniMatris1Boyut; j++){
                    printf("%5d      ", *(*(yeniMatris1 + i) + j));
                }
                printf("\n");
            }
            //yeniMatris olusturulur
            yeniOlusanMatris = operasyon1(yeniMatris1, yeniMatris1Boyut, matris2, matris2Boyut);
            yeniOlusanMatrisBoyut = matematikselHesaplamalar(yeniMatris1Boyut, matris2Boyut);
            //olusturulan matris2 nin elemanlari heap de iade edilir
            for (int i = 0; i < matris2Boyut; i++)
                free(*(matris2 + i));

            //olusturulan matris2 heap de iade edilir
            free(matris2);

            //olusturulan matris1 in elemanlari heap de iade edilir
            for (int i = 0; i < matris1Boyut; i++)
                free(*(matris1 + i));

            //olusturulan matris1 heap de iade edilir
            free(matris1);

            //olusturulan yeniMatris1 in elemanlari heap de iade edilir
            for (int i = 0; i < yeniMatris1Boyut; i++)
                free(*(yeniMatris1 + i));

            //olusturulan yeniMatris1 heap de iade edilir
            free(yeniMatris1);
        }
        printf("\n");
        printf("*********Islem sonucu olusan matris*********\n");
        printf("\n");
        //olusan yeniMatris in elemanlari ekrana basilir
        for (int i = 0; i < yeniOlusanMatrisBoyut; i++){
            for (int j = 0; j < yeniOlusanMatrisBoyut; j++){
                printf("%5d      ", *(*(yeniOlusanMatris + i) + j));
            }
            printf("\n");
        }
        printf("\n");
        //olusan yeniMatris in elemanlari heap de iade edilir
        for (int i = 0; i < yeniOlusanMatrisBoyut; i++)
            free(*(yeniOlusanMatris + i));

        //olusan yeniMatris heap de iade edilir
        free(yeniOlusanMatris);
    }
    return 0;
}