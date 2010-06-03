double exp( double base, double power )
{
	double result = 1;
	for( double i = 0.0; i < power; ++i )
	{
		result *= base;
	}
	return result;
}
