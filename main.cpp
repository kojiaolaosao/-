#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct stud
{
    int id;
    int name;
    struct stud *left,*right;
};
//insert a new stu
insert_newstu(stud *head,stud *neo)
{
   stud* cur=head;
   if(cur->id>neo->id)
   {
       if(!(cur->left==NULL))
       {
       cur=cur->left;
       insert_newstu(cur,neo);
       }
       else
       {
           cur->left=neo;
           neo->left=NULL;
           neo->right=NULL;
       }
   }
   else
   {
       if(!(cur->right==NULL))
       {
           cur=cur->right;
           insert_newstu(cur,neo);
       }
       else
       {
           cur->right=neo;
           neo->left=NULL;
           neo->right=NULL;
       }
   }
}

//4.show all\n
visit_stu(stud *head)
{
    stud *cur=head;
    if(cur)
    {
        visit_stu(cur->left);
        printf("id:%d name:%d\n",cur->id,cur->name);
        visit_stu(cur->right);
    }
    return 0;
}

//2.delete stu info
delete_stu(stud *head,stud *fat,stud *neo)
{
    stud *cur=head,*fa=fat;
    if(cur->id>neo->id)
    {
        delete_stu(cur->left,cur,neo);
    }
    if(cur->id<neo->id)
    {
        delete_stu(cur->right,cur,neo);
    }
    if(cur->id==neo->id)
    {
        if(cur->right==NULL&&cur->left==NULL)
        {
           if(fa->left==cur)
           {
               neo=cur;
               fa->left=NULL;
               free(neo);
               return 0;
           }
           if(fa->right==cur)
           {
               neo=cur;
               fa->right=NULL;
               free(neo);
               return 0;
           }
           if(cur->id==fa->id)
           {
               free(fa);
           }
        }
        if(cur->right==NULL&&cur->left!=NULL)
        {
           if(fa->left==cur)
           {
               neo=cur;
               fa->left=cur->left;
               free(neo);
           }
           if(fa->right==cur)
           {
               neo=cur;
               fa->right=cur->left;
               free(neo);
           }
        }
        if(cur->right!=NULL&&cur->left==NULL)
        {
           if(fa->left==cur)
           {
               neo=cur;
               fa->left=cur->right;
               free(neo);
           }
           if(fa->right==cur)
           {
               neo=cur;
               fa->right=cur->right;
               free(neo);
           }
        if(cur->right!=NULL&&cur->left!=NULL)
        {
           if(fa->left==cur)
           {
               neo=cur;
               if(cur->right->left==NULL)
               {
                   fa->left=cur->right;
                   cur->right->left=cur->left;
                   free(neo);
                   return 0;
               }
               else
               {
                   stud *sun=cur->right->left;
                   stud *sfa=cur->right;
                   while(sun)
                   {
                       sun=sun->left;
                       sfa=sfa->left;
                   }
                   if(sun->right)
                   {
                       fa->left=sun;
                       sfa->left=sun->right;
                       sun->right=cur->right;
                       sun->left=cur->left;
                   }
                   else
                   {
                       fa->left=sun;
                       sun->left=cur->left;
                       sun->right=cur->right;
                       sfa->left=NULL;
                   }
               }
           }
           if(fa->right==cur)
           {
               neo=cur;
               if(cur->right->left==NULL)
               {
                   fa->right=cur->right;
                   cur->right->left=cur->left;
                   free(neo);
                   return 0;
               }
               else
               {
                   stud *sun=cur->right->left;
                   stud *sfa=cur->right;
                   while(sun)
                   {
                       sun=sun->left;
                       sfa=sfa->left;
                   }
                   if(sun->right)
                   {
                       fa->right=sun;
                       sfa->left=sun->right;
                       sun->right=cur->right;
                       sun->left=cur->left;
                   }
                   else
                   {
                       fa->right=sun;
                       sun->left=cur->left;
                       sun->right=cur->right;
                       sfa->left=NULL;
                   }
               }
           }
        }
    }
}
}

//3.update stu info
stud* update_stu(stud *head,stud *neo)
{
    stud *cur=head;
    if(cur->id>neo->id)
    {
        if(cur->left)
        {
            cur=cur->left;
            update_stu(cur,neo);
        }
        else printf("错误！\n");
    }
    if(cur->id<neo->id)
    {
        if(cur->right)
        {
            cur=cur->right;
            update_stu(cur,neo);
        }
        else printf("错误!\n");
    }
    if(cur->id=neo->id)
    {
        cur->name=neo->name;
    }
}

//5.query stu info;
qurey_stu(stud *head,stud *neo)
{
    stud *cur=head;
    if(cur->id>neo->id)
    {
        if(cur->left)
        {
            cur=cur->left;
            update_stu(cur,neo);
        }
        else printf("错误！无该学生！\n");
    }
    if(cur->id<neo->id)
    {
        if(cur->right)
        {
            cur=cur->right;
            update_stu(cur,neo);
        }
        else printf("错误!无该学生！\n");
    }
    if(cur->id==neo->id)
    {
        printf("id:%d name:%d\n",cur->id,cur->name);
    }
}

int main()
{
    int choice;
    printf("**********welcome to stu manage system**************\n");
    stud* head=(stud*)malloc(sizeof(struct stud));
    printf("Since there is no student in the system, input the first student's data first, plz:\n");
    printf("input the first stud id, plz:");
    scanf("%d",&(head->id));
    printf("input the first name, plz:");
    scanf("%d",&(head->name));
    head->left=NULL;
    head->right=NULL;
    printf("1.insert a new stu info\n");
    printf("2.delete stu info\n");
    printf("3.update stu info\n");
    printf("4.show all\n");
    printf("5.query stu info\n");
    printf("0.exit\n");
    printf("input your choice : \n");
    while(1)
    {
        scanf("%d",&choice);
        if(choice==1)
        {
            stud* neo=(stud*)malloc(sizeof(struct stud));
            printf("input new stud id, plz:");
            scanf("%d",&(neo->id));
            printf("input new stud name, plz:");
            scanf("%d",&(neo->name));
            insert_newstu(head,neo);
        }
        if(choice==2)
        {
            stud* neo=(stud*)malloc(sizeof(struct stud));
            printf("input the stu id, plz:");
            scanf("%d",&(neo->id));
            printf("input the stu name, plz:");
            scanf("%d",&(neo->name));
            delete_stu(head,head,neo);
        }
        if(choice==3)
        {
            stud* neo=(stud*)malloc(sizeof(struct stud));
            printf("input the stu id, plz:");
            scanf("%d",&(neo->id));
            printf("input the stu new name, plz:");
            scanf("%d",&(neo->name));
            update_stu(head,neo);
        }
        if(choice==4)
        {
            visit_stu(head);
        }
        if(choice==5)
        {
            stud *neo=(stud*)malloc(sizeof(struct stud));
            printf("input the stu id, plz:");
            scanf("%d",&(neo->id));
            qurey_stu(head,neo);
        }
        if(choice==0)
        {
            printf("byebye!");
            return 0;
        }
        printf("make your choice again :\n");
    }
}
