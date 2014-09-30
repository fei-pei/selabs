#include"linktable.h"
#ifndef _MENU_H_
#define _MENU_H_

#define SUCCESS 0
#define FAILURE (-1)
#define ENABLE 0
#define DISABLE (-1)
#define MAX_SIZE 1024

/* define struct */
typedef struct DataNode
{
    tLinkTableNode * pNext;
    const char*      cmd;
    const char*      desc;
    int              (*handler)(tLinkTable * handler);
    int              enable;
}tDataNode;

/* initialise hte command */
int InitCmd(tLinkTable * head);

/* find a command */
tDataNode* FindCmd(tLinkTable* head, char * cmd);

/* find all commands */
int FindAllCmd(tLinkTable * head);

/* menu start */
int MenuStart(tLinkTable * head);

/* add a command */
int AddCmd(tLinkTable *head, const char * cmd, const char * desc,int (*handler)(tLinkTable * handler),int * enable);

/* delete a command */
int DelCmd(tLinkTable *head, const char * cmd);

/* turn on or turn off a command */
int OnOffCmd(tLinkTable *head, const char *cmd,int enable);

/* run a command */
int RunCmd(tLinkTable * head, tDataNode *pNode);

/* show all cmd in listlist */
int Help(tLinkTable * head);

/* quit the program */
int Quit(tLinkTable * head);

/* the stub function */
int Stub(tLinkTable * head);
#endif

