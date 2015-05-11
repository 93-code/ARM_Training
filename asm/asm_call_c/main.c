
extern void mycopy(char *dest, const char *src);
int main()
{
	const char *src = "hello";
	char dest[10];

	mycopy(dest, src);

	return 0;
}
