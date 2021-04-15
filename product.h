
typedef struct {
    char name[100];  //제품명
    int weight;  //중량
    int price;  //판매 가격
    int star;  //별점
    int nstar;  //별점 갯수
} Product;

int createProduct(Product *s);  //제품을 추가하는 함수
void readProduct(Product s);  //하나의 제품을 읽어 보여주는 함수
int deleteProduct(Product *s);  //등록된 특정 제품 삭제하는 함수
int updateProduct(Product *s);  //제품을 수정하는 함수

