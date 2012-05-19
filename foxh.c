#include "stdio.h"
#include "stdlib.h"
#include "time.h"
int summa(int x, int y, int n, int *c) 
	{
	int s=0,i,j;
		for(j=0;j<n;j++)
		{
		s+=c[x*n+j];
		}
			for(i=0;i<n;i++)
			{
			s+=c[i*n+y];
			}
		if (c[x*n+y]==1) s-=1;
		return s;
	}
		void pech_gl(int *b, int n, int *d) 
		{
		int i,j;
		printf("\n");
		printf("  | 1");
		for(i=2;i<9;i++)printf("%5i",i);
										printf("\t\t  | 1");
										for(i=2;i<9;i++)printf("%5i",i);
		printf("\n");
		printf("----------------------------------------\t\t----------------------------------------\n");
		for(i=0;i<8;i++)
		{
		printf("%i | ",i+1);
		for(j=0;j<8;j++)
		if(b[i*n+j]!=120)
			if(b[i*n+j]>15)
		printf("%1c%c%i  ",76,47,b[i*n+j]-20); 
			else
		printf("%1i    ",b[i*n+j]);
		else
		printf("%1c    ",b[i*n+j]);
									printf("\t\t%i | ",i+1);
									for(j=0;j<8;j++)
									printf("%1c    ",d[i*n+j]);
		printf("\n\n");
		}
		}
				void ybil(int *a,int *b, int n, int str, int sto)
					{
					a[str*n+sto]=0;
					b[str*n+sto]+=19;
					}

main()
{
int a[64],i,j,n=8,kol,kol1,*c=&a[0],s=0,p,str,sto,shag=0,kol_ybit=0,kolich[64],str_y[64],sto_y[64],str_s[64],sto_s[64],strel[64],kol_strel=0;
int b[64],d[64],*dd=&d[0],w[64],*ww=&w[0],u,str1,sto1, er, par=0, per1=-1,per2=-1, par1=0, par2=0;
int *br=&b[0],ss=0, iskl[64], ii=0, parz=0,par_isk1, par_isk2,par3;
system("cls");
system("title ohota na lis v 1.0");
system("color 21");
printf("Pole na kotorom vi bydete iskat lis nahoditsya sleva a vashe pole sprava. Ydachi!\n");
system("pause");
system("cls");
time_t t;
srand(time(&t));
for(i=0;i<64;i++)
	{a[i]=0;b[i]=120;d[i]=45;w[i]=0;}	
	
	do
	{
	printf("vvedite kolichestvo lis\n");
	scanf("%i",&kol); system("cls"); 
	if((kol>64)||(kol<0)){ printf("nevernoe kolichestvo lis\n");system("pause");system("cls");}
	}
	while((kol>64)||(kol<0));
		for(i=0;i<kol;i++)
		{ s=1;
		while (s!=0)
		{p=rand()%64;
		if(a[p]!=1)
		{a[p]=1; s=0;}
		}
		} 
	u=0;
	printf("rasstavte v levoe pole %i lis\n",kol);
	system("pause");
	while(u!=kol)
	{
	pech_gl(br,n,dd);
	er=0;
	while(er<1)   
		{
		printf("vvedite coord lisi ");
		scanf("%i%i",&str1,&sto1); str1--;sto1--; 
		if((str1<0)||(str1>7)||(sto1<0)||(sto1>7))
		{printf("\n nevernaya koordinata\n");}
		else er=1;
		if((er==1)&&(d[str1*n+sto1]!=45))
			{ printf("\n vi suda yzhe stavili\n"); er=0;}
		} 
		w[str1*n+sto1]=1; d[str1*n+sto1]=76;
		system("cls"); u++;
		}
		printf("IGRA NACHINAETSYA\n");
		system("pause");
		system("cls");
		pech_gl(br,n,dd); kol1=kol;
int z;	
	while((kol!=0)&&(kol1!=0))
	{	z=0;
		while(z<1)
		{
		printf("vvedite coord lisi protivnika "); 
		scanf("%i%i",&str,&sto); str--;sto--; 
		if((str<0)||(str>7)||(sto<0)||(sto>7))
		{printf("\n nevernaya koordinata\n");}
		else z=1;
		if((z==1)&&(b[str*n+sto]!=120))
			{ printf("\n vi suda yzhe strelyali\n"); z=0;}
		}
	b[str*n+sto]=summa(str,sto,n,c); shag++;
	if(a[str*n+sto]==1) 
	{		ybil(c,br,n,str,sto); kol--; 
	kolich[kol_ybit]=str*n+sto; str_y[kol_ybit]=str; sto_y[kol_ybit]=sto;kol_ybit++; 
		if(kol_ybit>1) for(i=0;i<kol_ybit;i++) 
						{
						int aa=str_y[i],bb=sto_y[i]; 
						b[kolich[i]]=summa(aa,bb,n,c);
						b[kolich[i]]+=20;
						}
		if(kol_strel>1) for(i=0;i<kol_strel;i++)
						{
						int xx=str_s[i],yy=sto_s[i];
						b[strel[i]]=summa(xx,yy,n,c);
						}
	}
	else {strel[kol_strel]=str*n+sto; str_s[kol_strel]=str; sto_s[kol_strel]=sto; kol_strel++;}
	int vv=0,ee,str_c, sto_c,ppp; 
	while(vv==0)
		{ par3=0; 
		if(par==0)		
			{str_c=rand()%8;ppp=str_c;
			sto_c=rand()%8;
			}
		else
				if((par1==1)&&(per1<7))
				{
				per1++;
				str_c=per1;
				if(summa(str_c,sto_c,n,ww)==0) {par1=0; par2=1;}
				}
				else 
				if((par2==1)&&(per2<7))
				{
				per2++;
				str_c=ppp;
				sto_c=per2;
				if(summa(str_c,sto_c,n,ww)==0) {par2=0; par=0;}					
				}
				else par=0;
		ee=str_c*n+sto_c;	
			ss=summa(str_c,sto_c,n,ww);	
				for(i=0;i<ii;i++)
					{
					if(ee==iskl[i]) par3=1; 
					}
					if(par3!=1)
					{
				if(ss==0) 
					{
					if(parz==0)
						{
						for(i=0;i<8;i++)
						{
						iskl[ii]=str_c*n+i; ii++;
						iskl[ii]=i*n+sto_c; ii++;
						}
						parz=1;
						}
					else
						{
						for(i=0;i<8;i++)
							{
							par_isk1=0;
							par_isk2=0;
							for(j=0;j<ii;j++)
								{
								if(iskl[j]==str_c*n+i) par_isk1=1;
								}
								if(par_isk1!=1)
										{
										iskl[ii]=str_c*n+i; ii++;
										}
							for(j=0;j<ii;j++)
								{
								if(iskl[j]==i*n+sto_c) par_isk2=1;
								}	
									if(par_isk2!=1)
										{
										iskl[ii]=i*n+sto_c; ii++;
										}
							}
						}
					}
		if((d[ee]==45)||(d[ee]==76))
		if(w[ee]==1){kol1--; w[ee]=0; d[ee]=33;vv++;}
		else	if(ss>0)
				{
				par=1; par1=1; d[ee]=120;vv++;
				}
				else {par==0;par1==0; per1=-1; per2=-1; d[ee]=120;vv++;}
					}		
		}
	system("cls");
	printf("kol-vo shagov = %i   ostalos lis sopernika = %i\t\t ostalos vashih lis =%i",shag,kol, kol1); 
	pech_gl(br,n,dd);
	}
	
	system("cls");if(kol==0)printf("POBEDA!!!!!!\n"); else printf("PORAZHENIE!!!!!!\n"); system("pause");
}