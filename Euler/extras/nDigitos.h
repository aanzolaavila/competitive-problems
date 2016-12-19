int nDigitos( long int n )
{
	int c=0;
	if(n == 0) return 1;
	while(n)
	{
		n = (n-(n%10))/10;
		c++;
	}
	return c;
}
