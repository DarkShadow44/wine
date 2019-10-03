typedef int int2;
typedef void (*func1)(int*[4]);
typedef int2 (*func2)(int*[4]); /* Caused crashes */

/* Normal struct */
struct s1
{
	int f1;
	long f2;
	char* f3;
	void (*f4)(struct s1* param1, int param2, int* param3[4]);
};

typedef struct
{
	int f1;
} s2, *s2b, s2c[4];

typedef union
{
	int f1;
} u1, *u1b, u1c[4];

typedef struct s3
{
	int f1;
} s4;

struct s5
{
	int f1;
	struct s6
	{
		int ff1;
		int ff2;
	} f2;

	struct
	{
		int f3;
		int f4;
	};

	struct
	{
		int ff1;
		int ff2;
	} f5;

	union s7
	{
		int ff1;
		int ff2;
	} f6;

	char f7;

	union
	{
		int f8;
		int f9;
	};
};

struct s8
{
	int f1;

	struct
	{
		int ff1;
		int ff2;
	} f2[40];

	int f3;
};

typedef enum e1
{
    e1_v1 = 0,
	e1_v2 = 1,
} e1;

struct s10
{
	struct s10* f1[1];
};
