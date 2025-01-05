#include "data.h"

void menuFirstly();
//menu danh muc
void menuCategory();
//file

void readDataCategory(int *n , Category category[]);//luu
void saveDataCategory(int n , Category category[]);
//cac chuc nang danh muc.
void inputCategory(int *n , Category category[] , int *Id );//nhap
void printCategory(int n , Category category[]);//xuat
void editCategory(int n , Category categgory[]);//sua
void deleteCategory(int *n , Category category[]);//xoa
//void searchCategory(int n , Category category[]);//tim kiem
void arrangeCategory1(int n , Category category[]);//sap xep
void arrangeCategory2(int n , Category category[]);//sap xep
void menuArrangeCategory(); 

void backAndEixt();
