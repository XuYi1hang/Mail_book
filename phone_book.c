#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "phone_book.h"
#include "tools.h"

Phone_book* p;

static int count = 0;		//	有效联系人数量

void init(void)	//	申请存储联系人的内存空间
{
	p = calloc(MAX_CON,sizeof(Phone_book));
}

void add(void)
{
	//printf("%s\n",__func__);
	if(MAX_CON <= count)
	{
		puts("系统正在升级,请等待...");
		return;
	}
	int i = 0;
	while(p[i].sex)	i++;
	printf("请输入新联系人姓名 性别 电话");
	scanf("%s %c %s",p[i].name,&p[i].sex,p[i].tel);
	count++;
	msg_show("添加联系人成功!\n",1.5);
}

void del(void)
{
	//printf("%s\n",__func__);	
	char key[20] = {};
	printf("请输入要删除的联系人姓名");
	scanf("%s",key);

	for(int i=0; i<MAX_CON; i++)
	{
		if(p[i].sex && 0 == strcmp(key,p[i].name))
		{
			p[i].sex = 0;	
			count--;
			msg_show("删除联系人成功!\n",1.5);
			return;
		}
	}
	msg_show("查无此人,删除失败!\n",1.5);
}

void mod(void)
{
	//printf("%s\n",__func__);	
	char key[20] = {};
	printf("请输入要修改的联系人姓名");
	scanf("%s",key);

	for(int i=0; i<MAX_CON; i++)
	{
		if(p[i].sex && 0 == strcmp(key,p[i].name))
		{
			printf("请重新输入联系人的姓名 性别 电话:");
			scanf("%s %c %s",p[i].name,&p[i].sex,p[i].tel);
			msg_show("修改联系人成功!\n",1.5);
			return;
		}
	}
	msg_show("查无此人!\n",1.5);
}

void find(void)
{
	//printf("%s\n",__func__);	
	char key[20] = {};
	printf("请输入要查询的关键字:");
	scanf("%s",key);
	for(int i=0; i<MAX_CON; i++)
	{
		if(p[i].sex && (strstr(p[i].name,key) || strstr(p[i].tel,key)))
		{
			printf("%s %s %s\n",p[i].name,'w'==p[i].sex?"女":"男",p[i].tel);
		}
	}
	anykey_continue();
}

void show(void)
{
	//printf("%s\n",__func__);	
	for(int i=0; i<MAX_CON; i++)
	{
		if(p[i].sex)
		{
			printf("%s %s %s\n",p[i].name,'w'==p[i].sex?"女":"男",p[i].tel);	
		}
	}
	anykey_continue();
}
