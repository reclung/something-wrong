void out(int x)
{
	char s[25];
	int k=0;
	sprintf(s,"%d",x);
	for(int i=0;i<strlen(s);i++) putchar(s[i]);
}

