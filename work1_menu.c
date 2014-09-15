/**************************************************************************************************/
/* Copyright (C) SSE@USTC, 2014-2015                                                              */
/*                                                                                                */
/*  FILE NAME             :  MENU.C                                                               */
/*  PRINCIPAL AUTHOR      :  Peifei                                                               */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/08                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Peifei, 2014/09/08
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CMD_LEN     256
#define DESC_LEN    1024
#define MENU        menu.txt
#define CMD_NUM     10

typedef struct tDataNode
{
    char    cmd[CMD_LEN];
    char    desc[DESC_LEN];
    struct  tDataNode *next;
}tDataNode;
tDataNode *GetCmdDef(tDataNode * head);
tDataNode *FindCmd(tDataNode *head, char *cmd);

int main()
{
    while(1)
    {
        tDataNode *p;
        char cmd[CMD_LEN];
        tDataNode *head = NULL;
        head = GetCmdDef(head);
        printf("Input a cmd number > ");
        scanf("%s",cmd);
        p = FindCmd(head,cmd);
        if(p != NULL)
        {
            printf("%s-%s\n",p->cmd,p->desc);
        }
        else
        {
            printf("This is a wrong command! Try again!\n");
        }
    }
}



tDataNode * GetCmdDef(tDataNode * head)
{
    FILE *fp1;
    char text[64]={'\0'};
    fp1 = fopen("../menu.txt","r"); //windows environment
    //fp1 = fopen("menu.txt","r"); //linux environment
    tDataNode *p = NULL;
    while(fgets(text,64,fp1) != NULL )
    {
        int i;
        int j;
        int k;
        j=strlen(text)-1;
        p=(tDataNode *)malloc(sizeof(tDataNode));
        memset(p,'\0',sizeof(tDataNode));

        for(i=0;i<j;i++)
        {
            if(text[i] != '#')
            {
                p->cmd[i] = text[i];
            }
            else
            {
                for(i=i+1,k=0;i<j;i++)
                {
                    p->desc[k] = text[i];
                    k++;
                }
            }
        }
        p->next = head;
        head = p;
    }
    fclose(fp1);
    return head;
}


tDataNode * FindCmd(tDataNode * head, char * cmd)
{

    tDataNode *p=NULL;
    tDataNode *q=NULL;
    for(p=head;p != NULL;p = p->next)
    {
        if(strlen(p->cmd) == strlen(cmd))
        {
             if(strcmp(p->cmd,cmd) == 0)
             {
                 q = p;
             }
        }
    }
    return q;
}
