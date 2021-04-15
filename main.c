#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"
#include "manager.h"

int main(void){
#ifdef DEBUG
	printf("=> DEBUGMODE\n");
#endif
        Product plist[50];
	int index = 0;
        int count = 0, menu;
	FILE *fp;
	fp = fopen("product.txt", "r");

	if(fp == NULL) {
		printf("=> 파일이 없습니다...\n");
	}
	else {
		count = loadData(plist);
		index = count;
	}

        while (1){
                menu = selectMenu();
                if(menu == 0) break;
                if(menu == 1){
			listProduct(plist, index);
                }
                else if(menu == 2){
                        count += createProduct(&plist[index]);
			index++;
                }
                else if(menu == 3){
		       	int no = selectDataNo(plist, index);
			if(no > 0){
				updateProduct(&plist[no-1]);
			}
			else{
				printf("=> 취소되었습니다!:->\n");
				continue;
			}
                }

                else if(menu == 4){
			int no = selectDataNo(plist, index);
			if(no > 0) {
				printf("정말로 삭제하시겠습니까?(삭제: 1) ");
			}
			int delok;
			scanf("%d", &delok);
			if(delok == 1) {
				deleteProduct(&plist[no-1]);
				count--;
				printf("=> 삭제되었습니다 :-)\n");
			}
		}
		else if(menu == 5) {
			saveData(plist, index);
		}
		else if(menu == 6) {
			searchProduct(plist, index);
		}
		else if (menu == 7) {
			searchProductStar(plist, index);
		}
		else if (menu == 8) {
			searchProductNumStar(plist, index);
		}
	}
	printf("종료되었습니다!:-)\n");
	fclose(fp);
	return 0;
}
