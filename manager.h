void saveData(Product *s, int count);  //파일에 정보를 저장하는 함수
int loadData(Product *s); // 파일에 있는 정보를 불러오는 함수

void listProduct(Product *s, int count);  //등록된 전체 제품 리스트를 출력하는 함수
int selectMenu();  //어떤 것을 실행 할 것 인지 선택하기 위해 메뉴를 보여주는 함수
int selectDataNo(Product *s, int count);  //특정 제품의 번호를 선택하여 수정할 수 있도록 하기위해 제품의 번호를 선택하는 함수
void searchProduct(Product *s, int count);  //제품명을 검색할 때 사용하는 함수
void searchProductStar(Product *s, int count);  //제품의 별점을 검색할 때 사용하는 함수
void searchProductNumStar(Product *s, int count);  //제품의 별점 갯수를 검색할 때 사용하는 함수
