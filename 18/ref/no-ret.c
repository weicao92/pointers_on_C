/*
** A function that works on some machines despite a major error.
*/
int
erroneous( int a, int b )
{
	int	x;

	/*
	** Compute the answer, and return it
	*/
	x = a + b;
	return;
}

int
main()
{
	int x;
	x = erroneous(3, 4);
	printf("res: %d\n", x);
	// 结果证明，我的机器上，我的编译器无法通过编译
}