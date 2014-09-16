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

#define CMD_LEN     64               /* the max length of command          */
#define DESC_LEN    64               /* the max length of command describe */
#define CONTENT_LEN 128              /* the max length of content line     */
#define HELP_CMD "help"
#define QUIT_CMD "quit"

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
    /*if s=0,that means the Initialization of cmd[] is failed*/
    int s;
    s = 1;
    while(s)
    {
        tDataNode *p;
        char *cmd;
        cmd = (char *)malloc(sizeof(char*));
        tDataNode *head = NULL;
        head = GetCmdDef(head);
        if(head != NULL)
        {
            printf("Input a cmd number > ");
            scanf("%s",cmd);
            p = FindCmd(head,cmd);
            /* get the right command */
            if(p != NULL)
            {
                /* Show help list */
                if(strcmp(cmd,HELP_CMD) == 0)
                {
                    printf("******This is a help list******\n");
                    /* print out all cmd  */
                    for(p = head;p != NULL;p = p->next)
                    {
                        printf("%s - %s\n", p->cmd, p->desc);
                    }
                }
                else
                {
                    /* quit the program */
                    if(strcmp(cmd,QUIT_CMD) == 0)
                    {
                        exit(0);
                    }
                    else
                    {
                        printf("The command you input is %s,%s\n",p->cmd,p->desc);
                    }
                }
            }
            else
            {
                printf("This is a wrong command! Try again!\n");
            }
        }
        else
        {
            s = 0;
            printf("fail to open the \"menu.ini\" file in the path of the program,\n");
            printf("or the contents of \"menu.ini\" file have some mistakes.\n ");
            system("pause");
        }
    }
    return 0;
}

/* read the configuration file named menu.ini
 * put the content into cmd[] and desc[]
 */
tDataNode * GetCmdDef(tDataNode * head)
{
    FILE *fp1;
    char text[CONTENT_LEN] = {'\0'};
    fp1 = fopen("menu.ini","r");
    /* fp1 = fopen(".\\menu.ini","r");  *//*used in windows environment  */
    if(fp1 != NULL)
    {
        tDataNode *p = NULL;
        /* read the file line by line */
        while(fgets(text,CONTENT_LEN,fp1) != NULL )
        {
            int i;
            int j;
            int k;
            j = strlen(text)-1;
            p = (tDataNode *)malloc(sizeof(tDataNode));
            memset(p,'\0',sizeof(tDataNode));
            for(i = 0;i<j;i++)
            {
                if(text[i] != '#')
                {
                    /* get the cmd */
                    p->cmd[i] = text[i];
                }
                else
                {
                    for(i=i+1,k=0;i<j;i++)
                    {
                        /* get the desc */
                        p->desc[k] = text[i];
                        k++;
                    }
                }
            }
            p->next = head;
            head = p;
        }
        fclose(fp1);
    }
    return head;
}

/* find out if the command exist in the cmd[]
 */
tDataNode * FindCmd(tDataNode * head, char * cmd)
{
    tDataNode *p = NULL;
    tDataNode *q = NULL;
    for(p = head;p != NULL;p = p->next)
    {
         if(strcmp(p->cmd,cmd) == 0)
         {
             q = p;
         }
    }
    return q;
}
