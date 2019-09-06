struct ee
{
	void **lop;
	int kop;
};

typedef int (*FUNCTYPE)(int k, struct ee arr2[3], void **test);

struct klsd
{
	int k;
	void **sdk;
	int (*func)(void);
	int* (*func2)(int k, struct ee arr2[3], void **test);
	FUNCTYPE func3;
	int arr[45];
	int x[34][45];
	char *fg[45];
	struct ee arr2[3];
	struct
	{
		int meta;
	};
	struct
	{
		int asdasd;
	} d;
	union
	{
		struct
		{
			int ksd;
			int lol;
		};
		int k;
	} uni;
};


typedef int sd;

int main()
{
}

