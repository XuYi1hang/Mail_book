#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#define MAX_CON 50 //	最大联系人数
typedef struct Phone_book
{
	char name[20];	//	姓名
	char sex;		//	性别
	char tel[12];	//	电话
}Phone_book;

void init(void);
void add(void);
void del(void);
void mod(void);
void find(void);
void show(void);

#endif//PHONE_BOOK_H
