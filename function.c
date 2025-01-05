#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "function.h"

void menuFirstly(){
	printf("\t        Menu\n ");
	printf("\t======================\n");
	printf("\t[1].Quan li danh muc.\n");
	printf("\t[2].Quan li danh sach.\n");
	printf("\t[3].Admin.\n");
	printf("\t[4].Thoat chuong trinh .\n");
}


//danh muc
void menuCategory(){
	printf("\t        Menu Danh Muc\n  ");
	printf("\t[1].Hien thi danh muc.\n");
	printf("\t[2].Them danh muc.\n");
	printf("\t[3].Sua danh muc.\n");
	printf("\t[4].Xoa danh muc.\n");
	printf("\t[5].Tim kiem danh muc.\n");
	printf("\t[6].Sap xep danh muc.\n");
	printf("\t[7].Thoat danh muc.\n");
}

//file


void readDataCategory(int *n, Category category[]) {
    FILE *file = fopen("project_C.dat", "rb");
    if (file == NULL) {
        printf("Tap tin loi.\n");
        *n = 0;
        return;
    }

    fread(n, sizeof(int), 1, file);
    fread(category, sizeof(Category), *n, file);
    fclose(file);
    printf("Doc file thanh cong.\n");
}
void saveDataCategory(int n , Category category[]){
	FILE *file = fopen("project_C.dat","wb");
	if(file==NULL){
		printf("Loi tap tin.\n");
		return ;
	} 
	fwrite(&n,sizeof(n),1,file);
	fwrite(category,sizeof(Category),n,file);
	fclose(file);
	printf("Luu du lieu vao trong file thanh cong .\n");
}

//chuc nang danh muc
void inputCategory(int *n, Category category[], int *Id) {
    int initial = *n;
    int add, i , j , k ;

    printf("So luong danh muc ban muon them: ");
    scanf("%d", &add);
    *n += add;

    for (i = initial; i < *n; i++) {
        category[i].id = (*Id)++;
        getchar(); 
        printf("Moi ban nhap ten: ");
        fgets(category[i].name, 50, stdin);
        category[i].name[strcspn(category[i].name, "\n")] = '\0'; 

        for ( j = 0; j < i; j++) {
            if (strcmp(category[i].name, category[j].name) == 0 || category[i].name[0]==' ') {
                printf("Ten da ton tai hoac ban da khong nhap dung  . Vui long nhap lai.\n");
                (*n)--;
                (*Id)--;
                i--;
                inputCategory(n, category, Id);
                return;
            }
        }

        printf("Nhap so luong danh muc : ");
        scanf("%d", &category[i].quantity);
        for(k = 0 ; k < i ; k++){
        	if(category[i].quantity<0){
        		printf("Ban nhap khong dung . Vui long nhap lai .\n ");
        		(*n);
        		(*Id);
        		i--;
        		inputCategory(n, category, Id);
                return;
			}
		}
    }
    saveDataCategory(*n, category);
}
void printCategory(int n, Category category[]) {
	printf("\n\tDanh Sach Danh Muc\n");
    printf("|=======|===========================|=============|\n");
    printf("|  ID   |       Ten danh muc        |   So luong  |\n");
    printf("|=======|===========================|=============|\n");
    int i ;  
	for( i = 0; i < n; i++) {
     printf("|%6d | %-25s | %11d |\n",
            category[i].id,
            category[i].name,
            category[i].quantity);
        printf("|=======|===========================|=============|\n");
    }
    
}



void editCategory(int n , Category category[]){
	int i,j,k,id ; 
	printf("Moi ban nhap id danh muc can sua : ");
	scanf("%d",&id);
	for( i = 0 ; i< n ; i++){
		if(category[i].id==id){
			getchar();
			printf("Nhap ten danh muc moi :");
			fgets(category[i].name,50,stdin);
			category[i].name[strcspn(category[i].name, "\n")] = '\0'; 
			printf("Moi ban nhap lai so luong san pham :");
			scanf("%d",&category[i].quantity);
			saveDataCategory(n,category);
			return ;
		}
	}
	printf("Id khong hop le.\n");
}
void deleteCategory(int *n , Category category[] ){
    int id1;
    int i, j;
    printf("Moi ban nhap id muon xoa : ");
    scanf("%d", &id1);
    int answer;
    for(i = 0; i < *n; i++){
        if(category[i].id == id1){
            printf("Dong y(1) va khong dong y(0): ");
            scanf("%d", &answer);
            if(answer == 1){
                for(j = i; j < *n - 1; j++){
                    category[j].id = category[j + 1].id;
                    category[j].quantity = category[j + 1].quantity;
                    strcpy(category[j].name, category[j + 1].name); 
                }
                (*n)--;
                printf("Xoa thanh cong.\n");
                saveDataCategory(*n, category);
                return;
            } else {
                printf("Da huy xoa.\n");
            }
        }
    }
    printf("Khong tim thay id ma ban muon xoa\n");
}

void searchCategory(int n , Category category[]){
	char name[50];
	getchar();
	printf("Nhap ten danh muc ban muon tim :");
	fgets(name,50,stdin);
	name[strcspn(name, "\n")] = '\0';
	int i ; 
	for( i = 0 ; i < n ; i++){
		if(strstr(category[i].name,name)!=NULL){
			printf("\nThong tin danh muc ban muon tim la :");
			printf("\nId : %d",category[i].id);
			printf("\nTen danh muc : %s",category[i].name);
			printf("\nSo luong san pham : %d\n ",category[i].quantity);
			return ;
		}
	}
	printf("Khong co danh muc nay .\n"); 
	
}
void arrangeCategory1(int n , Category category[]){
	int i , j ; 
	for(i = 0 ; i < n ; i++){
		for( j = i + 1 ; j < n ; j++){
			if(strcmp(category[i].name,category[j].name)>0){
				Category temp = category[i];
				category[i] = category[j];
				category[j] = temp;
			}
		}
	}
	printf("sap xep thanh cong :\n"); 
	printf("|=======|===========================|=============|\n");
    printf("|  ID   |       Ten danh muc        |   So luong  |\n");
    printf("|=======|===========================|=============|\n");
    int k ;  
	for( k = 0; k < n; k++) {
     printf("|%6d | %-25s | %11d |\n",
            category[k].id,
            category[k].name,
            category[k].quantity);
        printf("|=======|===========================|=============|\n");
    }
}
void backAndEixt() { 
	int choice; 
	do { 
		printf("Quay lai(1) hoac thoat chuong trinh(10): "); 
		scanf("%d", &choice); 
		if(choice != 1 && choice != 10) { 
			printf("Xin loi, moi ban nhap lai: "); 
		} 
	} while(choice != 1 && choice != 10); 
	if(choice == 10) {
		 printf("Cam on quy khach.\n"); 
		 exit(0); 
		} 
}
void menuArrangeCategory(){
	printf("[1].Sap xep tu 'a' den 'z'.\n");
	printf("[2].Sap xep tu 'z' den 'a'.\n");
	printf("[3].Thoat chuong trinh sap xep.\n");
}
void arrangeCategory2(int n , Category category[]){
	int i , j ; 
	for(i = 0 ; i < n ; i++){
		for( j = i + 1 ; j < n ; j++){
			if(strcmp(category[i].name,category[j].name)<0){
				Category temp = category[i];
				category[i] = category[j];
				category[j] = temp;
			}
		}
	}
	printf("Sap xep thanh cong.\n");
	printf("|=======|===========================|=============|\n");
    printf("|  ID   |       Ten danh muc        |   So luong  |\n");
    printf("|=======|===========================|=============|\n");
    int k ;  
	for( k = 0; k < n; k++) {
     printf("|%6d | %-25s | %11d |\n",
            category[k].id,
            category[k].name,
            category[k].quantity);
        printf("|=======|===========================|=============|\n");
    }
}

