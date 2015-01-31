#include<stdio.h>
#include<conio.h>

enum format_t {
  OCT = 66, BIN, HEX
};

void convert (enum format_t mode, unsigned long value)
{
	//unsigned long n;
	//n=100;
	int i,j,k;
	FILE *file;
	if(mode==BIN)
	{
		char* s[32];
	//binary conversion
	for(i=31;i>=0;i--)
	{
		j=value>>i;
		if(j&1)
		s[i]='1';
		else
		s[i]='0';
	}
	
	for(i =31;i>=0 ;i--)
	printf("%c",s[i]);
	printf("\n");
	
	
	file=fopen("F:\\MyStuffs\\MS\\Operating System\\conversion.txt","wt");
	for(i =31;i>=0 ;i--)
	putc(s[i],file);
	
	putc('\\',file);
	putc('n',file);
	fclose(file);
	}
	
	if(mode==OCT)
	{
		//octal conversion
	char* o[11];
	i=0;
	//n=100;
	for(i=0;i<11;i++)
	o[i]='0';
	i=10;
	
	while(1)
	{
		o[i]=value%8+'0';
		value=value/8;
		i--;
		if(value/8==0)
		{
			o[i]=value%8+'0';
			break;
		}
	}
	
	file=fopen("F:\\MyStuffs\\MS\\Operating System\\conversion.txt","wt");
	for(i =0;i<11 ;i++)
	{
		printf("%c",o[i]);
		putc(o[i],file);
	}
	putc('\\',file);
	putc('n',file);
	fclose(file);
	printf("\n");
	}
	
	
	if(mode==HEX)
	{
		//hexadecimal
	char hexcode[6]={'A','B','C','D','E','F'};
	char* h[8];
	i=0;
	for(i=0;i<8;i++)
	h[i]='0';
	i=7;
	//n=12349;
	while(1)
	{
		
		if(value%16>9)
		{
			h[i]=hexcode[((value%16))%10];
		}
		else
		h[i]=value%16+'0';
		
		value=value/16;
		i--;
		if(value/16==0)
		{
			h[i]=value%16+'0';
			break;
		}
	}
	
	file=fopen("F:\\MyStuffs\\MS\\Operating System\\conversion.txt","wt");
	for(i =0;i<8 ;i++)
	{
		putc(h[i],file);
		printf("%c",h[i]);
	}
	putc('\\',file);
	putc('n',file);
	fclose(file);
	}
	else
	{
		printf("nothing");
	}
	
}
int main()
{
	convert(HEX,12349);
	return 0;
}

 
