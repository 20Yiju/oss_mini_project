#include <stdio.h>
#include <string.h>
#include "product.h"

int createProduct(Product *s){
	getchar();
	printf("제품명? ");
	scanf("%[^\n]s", s->name);
	printf("중량은? ");
        scanf("%d", &s->weight);
	printf("판매 가격은? ");
        scanf("%d", &s->price);
	printf("별점은? ");
        scanf("%d", &s->star);
	printf("별점 갯수는? ");
        scanf("%d", &s->nstar);
	printf("=> 추가되었습니다!:-)\n");
	return 1;
}

void readProduct(Product s){
	printf("제품명       중량    가격   별점   별점갯수\n");
	printf("%s      %d      %d     %d     %d\n", s.name, s.weight, s.price, s.star, s.nstar);
}

int updateProduct(Product *s){
	getchar();
	printf("제품명? ");
        scanf("%[^\n]s", s->name);
        printf("중량은? ");
        scanf("%d", &s->weight);
        printf("판매 가격은? ");
        scanf("%d", &s->price);
        printf("별점은? ");
        scanf("%d", &s->star);
        printf("별점 갯수는? ");
        scanf("%d", &s->nstar);
	printf("=> 수정되었습니다:)\n");

	return 1;
}

int deleteProduct(Product *s){
	s->weight = -1;
	return 1;
}

