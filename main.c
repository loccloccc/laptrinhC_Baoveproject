#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Category category[100];
	int id = 1 ;
	int answer;
	int n = 0 , choice ;
	readDataCategory(&n,category);
	int i ; 
	for ( i = 0; i < n; i++) {
        if (category[i].id >= id) {
            id = category[i].id + 1;
        }
    }
	do{
		system("cls");
		menuFirstly();
		printf("Lua chon cua ban :");
		scanf("%d",&answer);
		switch(answer){
			case 1:
				do{
					system("cls");
					menuCategory();
					printf("Lua chon cua ban :");
					scanf("%d",&choice);
					switch(choice){
						case 1 :
							system("cls");
							printCategory(n,category);
							backAndEixt();
							break;
						case 2 :
							system("cls");
							inputCategory(&n,category,&id);
							backAndEixt();
							break;
						case 3 :
							system("cls");
							editCategory(n,category);
							backAndEixt();
							break;
						case 4 :
							system("cls");
							deleteCategory(&n,category);
							backAndEixt();
							break;
						case 5 :
							system("cls");
							searchCategory(n,category);
							backAndEixt();
							break;
						case 6 : 
							system("cls");
							int answer ;
							do{
								menuArrangeCategory(); 
								printf("Lua chon cua ban :");
								scanf("%d",&answer); 
								switch(answer){
									case 1 :
										system("cls");
										arrangeCategory1(n,category);
										printf("Danh sach sau khi sap xep.\n"); 
										backAndEixt();
										system("cls");
										break;
									case 2 :
										system("cls");
										arrangeCategory2(n,category);
										printf("Danh sach sau khi sap xep.\n"); 	
										backAndEixt();
										system("cls");				
										break;
									case 3 :
										printf("Thoat chuong trinh sap xep.\n");
										break ;
									default :
										printf("Khong co lua chon nay.\n");
								}
							}while(answer!=3);
							//backAndEixt();
							break;
						case 7 :
							printf("Thoat chuong trinh .");
							break ;
						default :
							printf("Khong co lua chon nay .\n");
					}
				}while(choice!=7);
				break;
			case 2 :
				break;
			case 3 :
				break;
			case 4 :
				break;
			default:
				printf("thoat chuong trinh.\n");
		}
	}while(answer!=4);
	return 0;
}
