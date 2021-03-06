#include<stdio.h>
#include<string.h>
//Creating master branch
struct bank
{
        char name[10],gender,addr[10],usr[10],psswrd[10];
        int yob,bal;
};
void login(struct bank b1[],int j);
void deposit(struct bank b2[],int a)
{
        int amnt;
        printf("\nenter the amount you want to deposit: ");
        scanf("%d",&amnt);
        b2[a].bal=b2[a].bal+amnt;
        printf("\nThe total balance is: %d",b2[a].bal);
}
void withdraw(struct bank b2[],int a)
{
        int amnt;
        if(b2[a].bal<1)
        {
                printf("\ninsufficient balance to withdraw!!");
        }
	else
        {
                if(amnt>b2[a].bal)
                {
                        printf("\ninsufficient balance to withdraw!!");
                }
                else
                {
                        printf("\nenter the amount to withdraw: ");
                        scanf("%d",&amnt);
                        b2[a].bal=b2[a].bal-amnt;
                        printf("\nThe total balance is: %d",b2[a].bal);
                }
        }
}
void checkBal(struct bank b2[],int a)
{
        printf("\nYour total balance is: %d",b2[a].bal);
}
void changePass(struct bank b2[],int a)
{
        int w1=0;
        char op[10],np1[10],np2[10];
	while(w1==0)
        {
                printf("\nenter your old password: ");
                scanf("%s",op);
                printf("\nenter new password: ");
                scanf("%s",np1);
                printf("\nre-enter new password: ");
                scanf("%s",np2);
                if(strcmp(op,b2[a].psswrd)==0 && strcmp(np1,np2)==0)
                {
                        strcpy(b2[a].psswrd,np1);
                        w1=1;
                        printf("\npassword sucessfully changed!! Please login again");
                        login(b2,a);
                }
                else
		{
			printf("\nWrong password! Please try again.");
                }
        }
}
void login(struct bank b1[],int j)
{
        char un[10],ps[10];
        int w=0,ch,w1=0;
        while(w==0)
        {
                printf("\nenter username: ");
                scanf("%s",un);
                printf("\nenter password: ");
                scanf("%s",ps);
                if(strcmp(un,b1[j].usr)==0 && strcmp(ps,b1[j].psswrd)==0)
                {
                        w=1;
                        printf("\nyou are successfully logged in!!");
                        while(w1==0)
                        {
                                printf("\n1. Deposit Money\n2. Withdraw Money\n3. Check Balance\n4. Change Password\n5. Exit");
                                printf("\nenter your choice: ");
                                scanf("%d",&ch);
				if(ch==1)
                                {
                                        deposit(b1,j);
                                }
                                else if(ch==2)
                                {
                                        withdraw(b1,j);
                                }
                                else if(ch==3)
                                {
                                        checkBal(b1,j);
                                }
                                else if(ch==4)
                                {
                                        changePass(b1,j);
				}
				else if(ch==5)
                                {
                                        w1=1;
                                }
                                else
                                {
                                        printf("\nYou have entered the wrong choice. Please Try Again!");
                                }
                        }
                }
                else
                {
                        printf("\nWrong credentials. Please Try Again!");
                }
        }
}
void openAccount(struct bank b[],int i)
{
        char x[10];
        int y=0;
        printf("\nenter name: ");
	scanf("%s",b[i].name);
        printf("\nenter gender: ");
        scanf("%s",&b[i].gender);
        printf("\nenter address: ");
        scanf("%s",b[i].addr);
        printf("\nenter year of birth: ");
        scanf("%d",&b[i].yob);
        printf("\nenter your username: ");
        scanf("%s",b[i].usr);
        while(y==0)
        {
                printf("\nenter your password: ");
                scanf("%s",b[i].psswrd);
                printf("\nre-enter password: ");
                scanf("%s",x);
                if(strcmp(b[i].psswrd,x)==0)
                {
                        printf("\nyou are successfully registered!!");
                        b[i].bal=0;
                        y=1;
                }
                else
                {
                        printf("\nyou have entered the wrong password! Please try again.");
		}
	 }
        printf("\nyour reference no. is: %d",i);
        login(b,i);
}
void main()
{
        struct bank obj[10];
        int num,k;
        printf("\nenter the no of customers: ");
        scanf("%d",&num);
        for(k=1;k<=num;k++)
        {
                openAccount(obj,k);
        }
}
