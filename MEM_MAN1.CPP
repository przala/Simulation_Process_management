#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <iostream.h>
#include <graphics.h>

void plot(struct node *);
struct node *start=NULL;
//p=(struct node *)malloc(sizeof(struct node));
  int x1=25,x2=75;
  int jj;
struct node
{
int size;
int ref;         //0 for hole, 1 for process.
struct node *link;
};

void main()
{
/*--------*/
int rem[25];               //remaining process
/*-----*/
int n;		//no. of partation
cout<<"Enter the no. of memory portion:\n";
cin>>n;

int mem[25];
for(int i=0;i<n;i++)
{

	cout<<"enter portion "<<i+1<<"size:";
	cin>>mem[i];
}

int totol=0;
for(int j=0;j<n;j++)
{
	totol=totol+mem[j];
}

/*-----*/
int p;		//no. of process
cout<<"Enter the no. of process:\n";
cin>>p;

int pro_size[25];
for (i=0;i<p;i++)
{
	cout<<"enter size of process "<<i+1<<" :";
	cin>>pro_size[i];
}
clrscr();
/*-----*/
b13:		     //lable for restart;

x1=25,x2=75;

//	int gd = DETECT, gm;
  //	initgraph(&gd, &gm,"C:\BORLANDC\BIN");
    /* request auto detection */
int gdriver = DETECT, gmode, errorcode;

/* initialize graphics mode */
initgraph(&gdriver, &gmode, "");

/* read result of initialization */
errorcode = graphresult();

if (errorcode != grOk)  /* an error occurred */
{
   printf("Graphics error: %s\n", grapherrormsg(errorcode));
   printf("Press any key to halt:");
   getch();
   exit(1);             /* return with error code */
}


for(int u=0;u<n;u++)
{rem[u]=0;}
struct node *m,*save;
start=NULL;
for (i=0;i<n;i++) //initialize linked list
{
m=(struct node *)malloc(sizeof(struct node));
m->size=mem[i];
m->ref=0;               //0 for hole, 1 for process.
	if (start==NULL)
	{
	m->link=NULL;
	start=m;
	}

	else
	{
	save=start;
	while((save->link)!=NULL)
	{
	save=save->link;
	}
	save->link=m;
	m->link=NULL;
	}
}       //for end    ;linked list initialized


/*
save=start;
while(save!=NULL)
{
cout<<"size of hole is"<<save->size;
cout<<"type is"<<save->ref;

save=save->link;
}
*/

b11:                  //lable for error
int fit;
cout<<"Enter any one\n";
cout<<"First fit:1\n";
cout<<"Next fit:2\n";
cout<<"Best fit:3\n";
cout<<"Worst fit:4\n";
cout<<"Exit :0\n";
cin>>fit;
cleardevice();
struct node *next,*temp1,*new1;

//for remaing process:
char msg1[10];
int g12=410;

int m12=0;
int m23;
char u23[10]={"min hole"};
char u12[10]={"max hole"};


plot(start);
switch(fit)
{
case 1:
int ct=0;
while(ct<p)
{
int k=0;
save=start;
m=(struct node *)malloc(sizeof(struct node));
	 while(k==0)
	 {
	 if(save->size>=pro_size[ct] && save->ref==0)
	 {
	 m->link=save->link;
	 save->link=m;
	 m->ref=1;
	 m->size=pro_size[ct];
	 save->size=save->size-pro_size[ct];
	 k=1;
	 plot(start);
	 }
	 else
	 {
	 save=save->link;
		if(save==NULL)
		{
		k=1;
		rem[ct]=1;
		}
	 }
	 }
ct++;
}
/*cout<<"remaining";
for(int u=0;u<n;u++)
{cout<<rem[u];}   */
break;

case 2:
ct=0;
int j1=0;
while(ct<p)
{
int k=0;
if(j1==0)
{
save=start;
}
else
{
save=temp1;
}
m=(struct node *)malloc(sizeof(struct node));
	 while(k==0)
	 {
	 if(save->size>=pro_size[ct] && save->ref==0)
	 {
	 m->link=save->link;
	 save->link=m;
	 temp1=save;
	 m->ref=1;
	 m->size=pro_size[ct];
	 save->size=save->size-pro_size[ct];
	 k=1;
	 j1=1;
	 plot(start);
	 }
	 else
	 {
	 save=save->link;
		if(j1==1)
		{
			if(save==NULL)
			{
			save=start;
			}
			if(save==temp1)
			{k=1;rem[ct]=1;		}
		}
		else
		{
		if(save==NULL)
		{
		k=1;
		rem[ct]=1;
		}
		}
	 }
	 }
ct++;
}

break;

case 4:

ct=0;
while(ct<p)
{
save=start;
int s1=0;
m=(struct node *)malloc(sizeof(struct node));
	while(save!=NULL)
	{
	if(pro_size[ct]<=save->size&&save->ref==0)
	{
	if(s1<save->size)
	{
		s1=save->size;
		temp1=save;
	}
	}
	save=save->link;

	}
	if(s1!=0)
	{
	save=temp1;
	m->link=save->link;
	save->link=m;
	m->ref=1;
	m->size=pro_size[ct];
	save->size=save->size-pro_size[ct];
	plot(start);
	}
	else
	{
	rem[ct]=1;
	}
ct++;
}
break;

case 3:

ct=0;
while(ct<p)
{
int k=0;
save=start;
int s1=totol;
m=(struct node *)malloc(sizeof(struct node));
	while(save!=NULL)
	{
	if(pro_size[ct]<=save->size&&save->ref==0)
	{
	if(s1>save->size)
	{
		s1=save->size;
		temp1=save;
		k=1;
	}
	}
	save=save->link;

	}
	if(k==1)
	{
	save=temp1;
	m->link=save->link;
	save->link=m;
	m->ref=1;
	m->size=pro_size[ct];
	save->size=save->size-pro_size[ct];
	plot(start);
	}
	else
	{
	rem[ct]=1;
	}
ct++;
}
break;

case 0:
	goto b12;


default:
	cout<<"error in input\nEnter input again:";
	goto b11;
}

/*save=start;
while(save!=NULL)
{
cout<<"\nsize of hole is"<<save->size;
cout<<"type is"<<save->ref;

save=save->link;
} */
//setviewport(0,0,390,400,1);
moveto(1,400);
outtext("green portion indicates menory & voilate indicates process.");
outtext("remaining processes:");

for(jj=0;jj<n;jj++)
{
if(rem[jj]==1)
	{
	outtext("process of size:");
	sprintf(msg1, "%d",pro_size[jj]);
	outtextxy(1,g12, msg1);
	g12+=10;
	}
}
getch();


//for max & min holes:
save=start;
m23=save->size;
while(save!=NULL)
{
if(save->ref==0)
{
	if((save->size)>m12)
	{
	m12=save->size;
	}
	if((save->size)<m23)
	{
	m23=save->size;
	}

}
save=save->link;
}//end
outtextxy(1,450,u12);
sprintf(msg1,"%d",m12);
outtextxy(90,450,msg1);

outtextxy(1,460,u23);
sprintf(msg1, "%d",m23);
outtextxy(90,460, msg1);

getch();
closegraph();
getch();
goto b13;


b12: //lable for exit
getch();
}

char msg[10];
void plot(struct node *result)
{

   //    char ma1[5];
    //   int f1=1;
       int k1,k2;
       struct node *save;
       save=result;

       int y1=50,y2;
       int max=getmaxy();
       while(save!=NULL)
       {
		if(save->ref==0)
		{setcolor(2);}
		else
		{setcolor(5);}

       y2=y1+save->size/2;
       rectangle(x1,y1,x2,y2);
       sprintf(msg, "%d",save->size);

		if(save->ref==1)
		{outtextxy(x1-25, y1, msg);}
		else
		{outtextxy(x2+3,y1,msg);}

	//for indicating process:

	k1=(x1+x2)/2;
	k2=(y1+y2)/2;
	moveto(k1,k2);
	if(save->ref==1)
	{
	outtext("P");
//	sprintf(ma1, "%d",f1);
//	outtextxy(k1+10,k2, ma1);
//	f1++;
	}

	//for space in between.
	y1=y2;
	y2=y2+4;
	setcolor(9);
	rectangle(x1,y1,x2,y2);        //space complete.

       y1=y2;
       save=save->link;
       }

       x1=x2+60;
       x2=x1+50;
       getch();

}