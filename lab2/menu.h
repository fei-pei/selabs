
/********************************************************************/
/* Copyright (C) SSE-USTC, 2012-2014                                */
/*                                                                  */
/*  FILE NAME             :  menu.h                                 */
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

#include"linktable.h"
#ifndef _MENU_H_
#define _MENU_H_

#define SUCCESS 0
#define FAILURE (-1)

#define CMD_MAX_LEN 128

/* data struct and its operations */
typedef struct DataNode
{
    tLinkTableNode * pNext;
    char* cmd;
    char* desc;
    int   (*handler)(tLinkTable * head);
}tDataNode;

/*init the Command */
int InitCmd(tLinkTable* head,tDataNode data[]);

/*Find a Command*/
tDataNode* FindCmd(tLinkTable* head, char * cmd);

/* show all cmd in listlist */
int Help(tLinkTable * head);

/* quit the program */
int Quit(tLinkTable * head);

#endif /* _MENU_H_ */

