#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"
#include "manager.h"

int selectMenu(){
        int menu;
        printf("\n--- 상 품 관 리---\n");
        printf("1. 조회\n");
        printf("2. 추가\n");
        printf("3. 수정\n");
        printf("4. 삭제\n");
        printf("5. 저장\n");
        printf("6. 제품명 검색\n");
        printf("7. 제품의 별점 검색\n");
        printf("8. 제품의 별점 갯수 검색\n");
        printf("0. 종료\n\n");
        printf("=> 원하는 메뉴는? ");
        scanf("%d", &menu);
        return menu;
}

void listProduct(Product *s, int count){
    printf("\n 제품명      중량  판매가격  별점  별점갯수\n");
    printf("===============================================\n");
    for(int i = 0; i < count; i++){
        if(s[i].weight == -1) continue;
        printf("%2d", i+1);
        readProduct(s[i]);
    }
}

int selectDataNo(Product *s, int count){
    int no;
    listProduct(s, count);
    printf("번호는(취소:0)? ");
    scanf("%d", &no);
    return no;
}

void searchProduct(Product *s, int count){
    int scnt = 0;
    char search[20];

    printf("검색할 제품명은? ");
    scanf("%s", search);
    printf("\n***************************\n");
    for(int i =0; i <count ; i++){
        if(s[i].weight == -1) continue;
        if(strstr(s[i].name, search)){
            printf("%2d ", i+1);
            readProduct(s[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

void searchProductStar(Product *s, int count){
    int scnt = 0;
    int search = 0;

    printf("검색할 제품의 별점은? ");
    scanf("%d", &search);
    printf("***************************\n");
    for(int i =0; i <count ; i++){
        if(s[i].weight == -1) continue;
        if(s[i].star == search){
            printf("%2d ", i+1);
            readProduct(s[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

void searchProductNumStar(Product *s, int count) {
	int scnt = 0;
	int search = 0;
	printf("검색할 제품의 별점 갯수는? ");
	scanf("%d", &search);
	printf("*****************************\n");
	for(int i = 0; i < count; i++) {
		if(s[i].weight == -1) {
			continue;
		}
		if(s[i].nstar == search) {
			printf("%2d" , i+1);
			readProduct(s[i]);
			scnt++;
		}
	}
	if(scnt == 0) {
		printf("=> 검색된 데이터가 없습니다...!");
	}
	printf("\n");
}

void saveData(Product *s, int count){
    FILE *fp;
    fp = fopen("product.txt", "wt");
    for(int i = 0; i < count; i++){
        if(s[i].weight == -1) continue;
        fprintf(fp, "%d %d %d %d %s\n", s[i].weight, s[i].price, s[i].star, s[i].nstar, s[i].name);
    }
    fclose(fp);
    printf("=> 저장되었습니다!:->!\n");
}

int loadData(product *s) {
	int i = 0;
	FILE *fp;
	fp = fopen("product.txt", "rt");
	for(; i < 100; i++){
		fscanf(fp, "%d", &s[i].weight);
		if(feof(fp)) break;	
		fscanf(fp, "%d", &s[i].price);
		fscanf(fp, "%d", &s[i].star);
		fscanf(fp, "%d", &s[i].nstar);
		fscanf(fp, "%[^\n]s", &s[i].name);
	}

