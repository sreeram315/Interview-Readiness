 int gcd(int a, int b)
{
	while(a!=b)
	{
		if(a > b)
			a = a - b;
		else
			b = b - a; 
	}

	return a;
}


 int gcd(int a, int b)
{
	if(b==0)
		return a;

	return gcd(b, a % b);
}