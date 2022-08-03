#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getch.h>
#include "tools.h"

//	打印提示信息
void msg_show(const char* msg,float sec)
{
	printf("%s",msg);
	fflush(stdout);
	usleep(sec*1000000);
}

//	按任意键继续
void anykey_continue(void)
{
	puts("请按任意键继续...");
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	getch();
}

int menu(void)
{
	system("clear");
	puts("****欢迎使用通讯录****");
	puts("1.添加联系人");
	puts("2.删除联系人");
	puts("3.修改联系人");
	puts("4.查询联系人");
	puts("5.显示联系人");
	puts("6.退出通讯录");
	puts("**********************");
	printf("请输入指令:");
	char cmd = getch();
	printf("%c\n",cmd);		//	回显
	return cmd;
}

