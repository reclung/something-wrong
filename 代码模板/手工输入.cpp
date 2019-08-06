int read()
{
	int x=0,ok=0;
	char ch;
	ch=getchar();
	
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	while((ch>='0'&&ch<='9')||ch=='-')
	{
		if(ch=='-') ok=1;
		else x=x*10+ch-'0';
		ch=getchar();
	}
	
	return ok==1?-x:x;
}

