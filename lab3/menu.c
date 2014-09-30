/**************************************************************************************************/
/*  Copyright (C) SSE@USTC, 2014-2015                                                             */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  PeiFei                                                               */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/27                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by PeiFei, 2014/09/27
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

/* initialise hte cmd */
int InitCmd(tLinkTable * head)
{
    AddCmd(head, "help","this is help cmd!", Help, ENABLE);
    AddCmd(head, "quit","quit this program!", Quit, ENABLE);
    return 0;
}

/*find a command*/
tDataNode* FindCmd(tLinkTable * head, char * cmd)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        if(!strcmp(pNode->cmd, cmd))
        {
            return pNode;
        }
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return NULL;
}

/* show all commands */
int FindAllCmd(tLinkTable * head)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return 0;
}

/* add commands into the head */
int AddCmd(tLinkTable *head, const char * cmd, const char * desc,int (*handler)(tLinkTable * handler), int * enable)
{
    if(head != NULL && cmd != NULL)
    {
        if(FindCmd(head, (char*)cmd)==NULL)
        {
            tDataNode * pNode = (tDataNode*)malloc(sizeof(tDataNode));
            pNode->pNext=NULL;
            pNode->cmd=cmd;
            pNode->desc=desc;
            pNode->handler=handler;
            pNode->enable=ENABLE;
            AddLinkTableNode(head,(tLinkTableNode *)pNode);
            return SUCCESS;
        }
        else
        {
            printf("command is exist!\n");
            return FAILURE;
        }
    }
    else
    {
        return FAILURE;
    }
}

/* delete commands from the head */
int DelCmd(tLinkTable *head, const char * cmd)
{
    tDataNode *p;
    p = FindCmd(head, (char*)cmd);
    if(p==NULL)
    {
         printf("command is not exist!\n");
         return FAILURE;
    }
    else
    {
        DelLinkTableNode(head,(tLinkTableNode *)p);
        free(p);
        p=NULL;
        return SUCCESS;
    }

}

/* turn on or turn off a command */
int OnOffCmd(tLinkTable *head, const char *cmd,int enable)
{
    tDataNode *p;
    p = FindCmd(head, (char*)cmd);
    if(p==NULL)
    {
        printf("command is not exist!\n");
        return FAILURE;
    }
    else
    {
        p->enable =enable;
        return SUCCESS;
    }
    return 0;
}

int RunCmd(tLinkTable * head, tDataNode *pNode)
{
        if (pNode->handler != NULL)
        {
            printf("%s - %s\n", pNode->cmd, pNode->desc);
            if(pNode->enable == ENABLE)
            {
                pNode->handler(head);
                return SUCCESS;
            }
            else
            {
                return FAILURE;
            }
        }
        return FAILURE;
}

int MenuStart(tLinkTable * head)
{
    while (1)
    {
		char cmd[MAX_SIZE];
        printf("Please input a command > ");
        scanf("%s",cmd);
        tDataNode *p = FindCmd(head,cmd);
        if (p == NULL)
        {
            printf("This is a wrong command!\n");
            continue;
        }
        else
        {
            RunCmd(head,p);
        }
    }
    return 0;
}

int Help(tLinkTable * head)
{
    FindAllCmd(head);
    return 0;
}

int Quit(tLinkTable * head)
{
    exit(0);
    return 0;
}

/* the stub function */
int Stub(tLinkTable * head)
{
    return SUCCESS;
}


