
/********************************************************************/
/* Copyright (C) SSE-USTC, 2012-2014                                */
/*                                                                  */
/*  FILE NAME             :  testmenu.c                             */
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
#include"menu.h"

/* input the cmd & desc here*/
static tDataNode data[] =
{
    {NULL, "help", "this is help cmd!", Help},
    {NULL, "quit","quit this program", Quit},
    {NULL, "version","menu program v2.0", NULL}
};

int main()
{
    tLinkTable * head =CreateLinkTable();
    InitCmd(head,data);
    /* cmd line begins */
    while (1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a Command > ");
        scanf("%s",cmd);
        tDataNode *p = FindCmd(head,cmd);
        if (p == NULL)
        {
            printf("This is a wrong Conmmand!\n");
            continue;
        }
        printf("%s - %s\n", p->cmd, p->desc);
        if (p->handler != NULL)
        {
            p->handler(head);
        }
    }
}
