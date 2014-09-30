/**************************************************************************************************/
/*  Copyright (C) SSE@USTC, 2014-2015                                                             */
/*                                                                                                */
/*  FILE NAME             :  testinterface.c                                                      */
/*  PRINCIPAL AUTHOR      :  PeiFei                                                               */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/27                                                           */
/*  DESCRIPTION           :  This is a test program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by PeiFei, 2014/09/27
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include"menu.h"

static tLinkTable * head;

/* test AddCmd */
int TestAddCmd(tLinkTable * head);
/* test InitCmd */
int TestInitCmd(tLinkTable * head);
/* test FindCmd */
int TestFindCmd(tLinkTable * head);

/* test OnOffCmd */
int TestOnOffCmd(tLinkTable * head);
/* test DelCmd */
int TestDelCmd(tLinkTable * head);

int Test1(tLinkTable * head);


int main()
{
    head =CreateLinkTable();
    InitCmd(head);
	AddCmd(head, "show","this is show cmd!", NULL, ENABLE);
	AddCmd(head,"test1", "for instance", Test1, ENABLE);
	Help(head);
	printf("test is ready,press any key to begin!\n");
	getchar();

    TestFindCmd(head);
    TestAddCmd(head);
    TestInitCmd(head);
    TestOnOffCmd(head);
    TestDelCmd(head);

    /* cmd line begins */
    if(Stub(head) == SUCCESS)
    {
        MenuStart(head);
    }
	return 0;
}

/* User can define the fuction like this */
int Test1(tLinkTable * head)
{
    printf("this is a good prgram!\n");
    return 0;
}
/* test AddCmd */

int TestAddCmd(tLinkTable * head)
{
    /* normal test */
    if(AddCmd(head,"ta1", "testAddCmd1", NULL, ENABLE)==SUCCESS)
    {
        tDataNode *p;
        p=FindCmd(head, "ta1");
        if(p != NULL)
        {
            printf("normal AddCmd test is passed\n");
        }
        else
        {
            printf("normal AddCmd test is failure,can't find the cmd\n");
        }
    }
    else
    {
        printf("normal AddCmd test is failure in the process\n");
    }
    /*  test repeat add cmd  */
    if(AddCmd(head, "ta1", " ", NULL, ENABLE) == FAILURE)
    {
        printf("repeat AddCmd test is passed\n");
    }
    /*  test add cmd in to a wrong head  */
    tLinkTable * testhead;
    testhead=NULL;
    if(AddCmd(testhead, "ta2", "t2test", NULL, ENABLE) == FAILURE)
    {
        printf("wrong head AddCmd test is passed\n");
    }
    /*  test add cmd in to a wrong head  */
    if(AddCmd(head, '\0', "t3test", NULL, ENABLE) == FAILURE)
    {
        printf("empty cmd AddCmd test is passed\n");
    }
    return 0;
}

/* test InitCmd */
int TestInitCmd(tLinkTable * head)
{
    tDataNode *p;
    p=FindCmd(head, "help");
    if(p != NULL)
    {
        p=FindCmd(head, "quit");
        if(p != NULL)
        {
            printf("InitCmd test is passed\n");
        }
        else
        {
             printf("InitCmd test failed,can't find the \"quit\" cmd\n");
        }
    }
    else
    {
        printf("InitCmd test failed,can't find the \"help\" cmd\n");
    }
    return 0;
}

/* test findCmd */
int TestFindCmd(tLinkTable * head)
{
    tDataNode *p;
    p=FindCmd(head, "help");
    if(p != NULL)
    {
        printf("Findind exist cmd test is passed!\n");
    }
    else
    {
        printf("Findind exist cmd test is failure!\n");
    }
    p=FindCmd(head, "wrong");
    if(p == NULL)
    {
        printf("Findind not exist cmd test is passed!\n");
    }
    else
    {
        printf("Findind not exist cmd test is failure!\n");
    }
    return 0;
}

/* test DelCmd */
int TestDelCmd(tLinkTable * head)
{
    tDataNode *p;
    if(AddCmd(head, "td", "tdtest", NULL, ENABLE) == FAILURE)
    {
        p=FindCmd(head, "td");

        if(p != NULL)
        {
            if(DelCmd(head,"td")==SUCCESS)
            {
                p=FindCmd(head, "td");
                if(p == NULL)
                {
                    printf("DelCmd test is passed!\n");
                }
                else
                {
                    printf("DelCmd test is failure!\n");
                }
            }
            else
            {
                printf("DelCmd test is failure!\n");
            }
        }
        else
        {
            printf("DelCmd test is failure when add cmd into linktable!\n");
        }

    }
    if(DelCmd(head,"")==SUCCESS)
    {
        printf("Del empty Cmd test is failure!\n");
    }
    else
    {
        printf("Del empty Cmd test is passed!\n");
    }

    return 0;
}

/* test OnOffCmd */
int TestOnOffCmd(tLinkTable * head)
{
    tDataNode *p;
    p = FindCmd(head,"test1");
    if(p != NULL)
    {
        OnOffCmd(head, "test1",ENABLE);
        if(p->enable==ENABLE)
        {
           OnOffCmd(head, "test1",DISABLE);
           {
               if(p->enable == DISABLE)
               {
                   printf("OnOffCmd test is passed!\n");
               }
               else
               {
                   printf("OnOffCmd test is failure!\n");
               }
           }
        }
        else
        {
           printf("OnOffCmd test is failure!\n");
        }
    }
    else
    {
        printf("OnOffCmd test is failure,the cmd is not exist!\n");
    }
        return 0;
}
