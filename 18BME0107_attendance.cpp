#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<string.h>
using namespace std;

char rg[100],nm[100],hb[100],br[100],pswd[20];
void studisplay();
char reg[10];
int tmp=0;

int a[20],b[20],c[20],d[29];
int n;
struct tt
{
	int f;
	int sf=-1;
	int sr=-1;
	struct sb{
		char sn[20],sr[10],st[10],sc[10];
	}sb[5];
}t[7];

int f=-1; 
int r=-1;
void enqueue();
void dequeue();
void ttdisplay();
void endt();
void todisplay();

void subenqueue();
void subdequeue();
void modify();
struct at
{
	int top;
	char sbnm[50];
	int tc;
	float in;
	float a[7];
}ad[5];
int l=-1;
void apush();
void apop();
void search();


int main()
{   
	int ch,cs,k;
	char a,sb[100],rg[10];
	void dpush();
	void dpop();
	void studisplay();
	printf("\t\t\t\tVIT ATTENDANCE AND TIME TABLE PROGRAM");
	do{
	printf("\n1-Authority login\n2-Student login\n----------------------------------\nEnter your choice: ");
	scanf("%d",&cs);
	if(cs==1)
	  {
		printf("\n1-To enter personal details of student\n2-To enter academic details of student");
		printf("\n3-To display personal details of student\n4-To display academic details of student: ");
		scanf("%d",&ch);
		if(ch==1)
			endt();
		else if(ch==2)
		{for(k=0;k<2;k++)
		  {
			printf("\nEnter subject details for %d day",k+1);
			enqueue();
		  }
		}
		else if(ch==3)
			studisplay();
		else if(ch==4)
			ttdisplay();
	  }
	else if(cs==2)
	{
		int i,c;
		char ps[20];
		printf("Enter your registration no.");
		scanf("%s",reg);
		printf("Enter your password: ");
		scanf("%s",&ps);
		if(strcmp(ps,"abc123")==0)
		{
	      for(i=0;i<2;i++)
	     {
		printf("\nToday is DAY %d :",i+1);
		do{
		printf("\n\n1-To check attendance of a particular subject\n2-To modify today's time table");
		printf("\n3-To get todays time table\n4-To get timetable of all days\n5-To check your personal details\n6-Move to next day\nEnter your choice: ");
		scanf("%d",&c);
		if(c==1)
			search();
		else if(c==2)
			modify();
		else if(c==4)
			ttdisplay();
		else if(c==5)
			studisplay();
		else if(c==3)
			todisplay();	
		}while(c!=6);
		dequeue();
	  }
    }
     else
     	printf("Wrong password");
   }
	}while(cs<=2);
	return 0;	
}

void endt()
{	

 	printf("Enter your registration no.            : ");
 	scanf("%s",&rg);
 	printf("Enter your name                        : ");
 	scanf("%s", &nm);
 	printf("Enter your hostel block with room no.  : ");
 	scanf("%s", &hb);
 	printf("Enter your branch                      : ");
 	scanf("%s", &br);
 	printf("Enter student's password               : ");
 	scanf("%s",&pswd);

}

void search()
{	
	float atnd,na;
	int k,ca,i,p,ttc;
	char aa[10];
	char rs[50];
 	printf("\nEnter the subject whose attendance is required: ");
 	scanf("%s", &rs);
 	for(i=l;i>=0;i--)
 	{
 		if(strcmp(rs,ad[i].sbnm)==0)
 		{
 			k=i;
		 }
 	}
	if((ad[k].top++)==0)
		atnd=ad[k].in;
	else 
	{
		p=ad[k].top;
		atnd=ad[k].a[p];
	}
	printf("Your current attendance is %f  ",atnd);
	printf("\nPress N to check your attendance if you will not go tomorrow: ");
	scanf("%s",&aa);
	ttc=ad[k].tc;
	if(strcmp(aa,"N")==0)
	{
		ca=(atnd*ttc)/100;
		na=(ca*100)/(ttc+1);
		if(na<=75)
			printf("\nYour attendance will become %f, and you will get debared",na);
		else
			printf("\nYour attendance will become %f",na);
	}
}


void apush()
{
	int p,q,ca;
	char nm[20];
	float na,atnd;
	for(p=t[f].sf;p<t[f].sr;p++)
	{
		strcpy(nm,t[r].sb[p].sn);
		for(q=0;q<t[f].sr;q++)
		{
			if(strcmp(nm,ad[q].sbnm)==0)
			{
				if(ad[q].top==-1)
					atnd=ad[q].in;
				else 
					atnd=ad[q].a[ad[q].top];
				ad[q].top++;
				ca=(atnd*100)/ad[q].tc;
				na=((ca+1)*100)/((ad[q].tc)+1);
				ad[q].a[ad[q].top]=na;
			}
		}
	}
}
 
 void enqueue()
 {
 	int j;
 	printf("\nEnter no. of subjects: ");
 	scanf("%d",&n);
	if(f==-1)
	 {f=r=0;
 		for(j=0;j<n;j++)
 			{
			 l++;
 			subenqueue();}
	}
	else
	{
		r++;
		for(j=0;j<n;j++)
			subenqueue();
	}
 }
 
 void subenqueue()
 {	int sff;
 	int srr;
 	sff=t[r].sf;
 	srr=t[r].sr;
 	if(sff==-1)
 	{	sff=srr=0;
 		t[r].sf=t[r].sr=0;
 		printf("\nEnter details of %d subject: ",srr+1);
 		printf("\nEnter %d subject name: ",srr+1);
 		scanf("%s",&t[r].sb[srr].sn);
 		printf("Enter %d subject room no.: ",srr+1);
 		scanf("%s",&t[r].sb[srr].sr);
 		printf("Enter %d subject time: ",srr+1);
 		scanf("%s",&t[r].sb[srr].st);
 		if(r==0)
 		{
 		strcpy(ad[l].sbnm,t[r].sb[srr].sn);
 		printf("Enter initial attendace of %d subject: ",srr+1);
 		scanf("%f",&ad[l].in);
 		printf("Enter total no. of classes till day of %d subject: ",srr+1);
 		scanf("%d",&ad[l].tc);
 		}
 	}
	 else
	 {
	 	srr++;
	 	t[r].sr++;
		printf("\nEnter details of %d subject: ",srr+1);
 		printf("\nEnter %d subject name: ",srr+1);
 		scanf("%s",&t[r].sb[srr].sn);
 		printf("Enter %d subject room no.: ",srr+1);
 		scanf("%s",&t[r].sb[srr].sr);
 		printf("Enter %d subject time: ",srr+1);
 		scanf("%s",&t[r].sb[srr].st);
 		if(r==0)
 		{
 		strcpy(ad[l].sbnm,t[r].sb[srr].sn);
 		printf("Enter initial attendace of %d subject: ",srr+1);
 		scanf("%f",&ad[l].in);
 		printf("Enter total no. of classes till day of %d subject: ",srr+1);
 		scanf("%d",&ad[l].tc);
 		}
	}
}
 
 
void modify()
 {
 	int i,c=0,q,w;
 	char a[10];
 	w=t[f].sr;
 	for(i=0;i<=w;i++)
 	{	q=t[f].sf;
	 	printf("\nSubject name is: %s",t[f].sb[q].sn);
	 	printf("\nSubject room no. is: %s",t[f].sb[q].sr);
	 	printf("\nSubject time is: %s",t[f].sb[q].st);
	 	printf("\nTo delete and get details of next sbject press Y else to stop press S: ");
	 	scanf("%s",&a);
	 	if(strcmp(a,"Y")==0)
	 	{
			subdequeue();
		}
	 	else
	 		break;
	}
}
 
void subdequeue()
 {
 	int k;
 	for(k=(t[f].sf)+1;k<=t[f].sr;k++)
 	  {
		strcpy(t[f].sb[k-1].sn,t[f].sb[k].sn);
 		strcpy(t[f].sb[k-1].sr,t[f].sb[k].sr);
 		strcpy(t[f].sb[k-1].st,t[f].sb[k].st);
 	  }
 	t[f].sr--;
 }
 
 void dequeue()
 {
 	apush();
	 int i;
 	for(i=f+1;i<=r;i++)
 		t[i-1]=t[i];
 	r--;
 	
 }
 
void studisplay()
{
	printf("\nRegistration no.                      : %s",rg);
 	printf("\nName of student                       : %s",nm);
 	printf("\nHostel block with room no.            : %s",hb);
 	printf("\nBranch of student                     : %s",br);
}
 
void ttdisplay()
{
	int i,j;
	for(i=0;i<=r;i++)
	{
		printf("\n\nTime table of %d day is: ",i+1);
		for(j=0;j<=t[i].sr;j++)
		{
	 	printf("\n\nSubject name is: %s",t[i].sb[j].sn);
	 	printf("\nSubject room no. is: %s",t[i].sb[j].sr);
	 	printf("\nSubject time is: %s",t[i].sb[j].st);
		}
	}
}

void todisplay()
{
	int j;
	printf("\nTime table of today is: ");
		for(j=0;j<=t[0].sr;j++)
		{
	 	printf("\n\nSubject name is: %s",t[0].sb[j].sn);
	 	printf("\nSubject room no. is: %s",t[0].sb[j].sr);
	 	printf("\nSubject time is: %s",t[0].sb[j].st);
		}
}
 
 








