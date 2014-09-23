
/********************************************************************/
/* Copyright (C) SSE-USTC, 2012-2014                                */
/*                                                                  */
/*  FILE NAME             :  menu.c                                 */
/*  PRINCIPAL AUTHOR      :  PeiFei                                 */
/*  SUBSYSTEM NAME        :  Menu                                   */
/*  MODULE NAME           :  Menu                                   */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  ANY                                    */
/*  DATE OF FIRST RELEASE :  2014/09/20                             */
/*  DESCRIPTION           :  interface of Menu                      */
/********************************************************************/

/*
 * Revision log:
 *
 * Created by PeiFei,2014/09/20
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"menu.h"

/* initialize the Command */
int InitCmd(tLinkTable* head,tDataNode data[])
{
    int i;
    i = 0;
    for(; i<CMD_MAX_LEN; i++)
    {
        if(data[i].cmd != NULL)
        {
            AddLinkTableNode(head,(tLinkTableNode *)&data[i]);
        }
        else
        {
            break;
        }
    }
    return 0;
}

/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(tLinkTable* head, char * cmd)
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

/* show all cmd in listlist */
int ShowAllCmd(tLinkTable * head)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return 0;
}

int Help(tLinkTable * head)
{
    ShowAllCmd(head);
    return 0;
}

/* show all cmd in listlist */
int Quit(tLinkTable * head)
{
    exit(0);
    return 0;
}




