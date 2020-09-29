#include "header.h"

void Measurement()
{
	int sizes[] = { 10, 100, 1000, 5000, 10000, 50000 };
	int add_factors[] = { 1000, 5000, 10000, 50000, 75000, 100000 };
	float mp_factors[] = { (float)9 / 8, (float)4 / 3, (float)3 / 2, (float)8 / 5, 2, (float)9 / 4, (float)10 / 4 };

	for (int k = 0; k < 6; ++k)
	{
		printf("SIZE: %d\n", sizes[k]);

		for (int j = 0; j < 7; ++j)
		{
			//printf("INCREASE FACTOR: %d\n", add_factors[j]);

			double measurement_a = 0;
			double measurement_b = 0;
			double measurement_c = 0;

			int start = 0;

			const int SIZE = sizes[k];
            const int INCREASE_FACTOR = mp_factors[j];

			const OPERATION TYPE = MULTIPLY;

			start = clock();
			Array* arr_a = constructArray(SIZE, INCREASE_FACTOR, TYPE);
			for (int i = 0; i < 1e6; ++i)
			{
				pushArray(arr_a, i);
			}
			for (int i = 0; i < 5e5; ++i)
			{
				popArray(arr_a);
			}
			for (int i = 0; i < 5e5; ++i)
			{
				pushArray(arr_a, i);
			}

			measurement_a = difftime(clock(), start) / CLOCKS_PER_SEC;

			start = clock();
			Array* arr_b = constructArray(SIZE, INCREASE_FACTOR, TYPE);
			for (int i = 0; i < 1e6; ++i)
			{
				pushArray(arr_b, i);
			}
			for (int i = 0; i < 5e5; ++i)
			{
				popArray(arr_b);
			}
			for (int i = 0; i < 5e5; ++i)
			{
				pushArray(arr_b, i);
			}

			measurement_b = difftime(clock(), start) / CLOCKS_PER_SEC;

			start = clock();
			Array* arr_c = constructArray(SIZE, INCREASE_FACTOR, TYPE);
			for (int i = 0; i < 1e6; ++i)
			{
				pushArray(arr_c, i);
			}
			for (int i = 0; i < 5e5; ++i)
			{
				popArray(arr_c);
			}
			for (int i = 0; i < 5e5; ++i)
			{
				pushArray(arr_c, i);
			}

			measurement_c = difftime(clock(), start) / CLOCKS_PER_SEC;

			/*
			printf("Measurement A: %lg\n", measurement_a);
			printf("Measurement B: %lg\n", measurement_b);
			printf("Measurement C: %lg\n", measurement_c);

			printf("Average: %lg\n", (measurement_a + measurement_b + measurement_c) / 3);
			*/
			printf("%lg, ", (measurement_a + measurement_b + measurement_c) / 3);

			destroyArray(arr_a);
			destroyArray(arr_b);
			destroyArray(arr_c);

			//printf("\n");
		}

		printf("\n\n");
	}

}

void MMeasurement()
{
	double* measurements = (double*)calloc(3, sizeof(double));

	for (int j = 0; j < 3; ++j)
	{
		int start = clock();

		Array* Stack = constructArray(50000, 2, MULTIPLY);

		for (int i = 0; i < (int)1e6; ++i)
		{
			pushArray(Stack, i);
		}

		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < (int)1e4; ++j)
			{
				popArray(Stack);
			}

			for (int j = 0; j < (int)1e4; ++j)
			{
				pushArray(Stack, j);
			}
		}

		int length = (int)1e6;
		for (int _ = 0; _ < 9; ++_)
		{
			for (int i = 0; i < length; ++i)
			{
				pushArray(Stack, i);
			}
			//printf("SIZE AFTER PUSH: %d\n", ListStack->size);

			length = (int)Stack->size / 2;
			for (int i = 0; i < length; ++i)
			{
				popArray(Stack);
			}
			//printf("SIZE AFTER POP: %d\n\n", ListStack->size);
			length = (int)Stack->size / 2;

		}


		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < (int)1e4; ++j)
				popArray(Stack);

			for (int j = 0; j < (int)1e4; ++j)
				pushArray(Stack, j);
		}

		measurements[j] = difftime(clock(), start) / CLOCKS_PER_SEC;
	}

	double average = (double)(measurements[0] + measurements[1] + measurements[2]) / 3;

	printf("MEASUREMENT A: %lg\n", measurements[0]);
	printf("MEASUREMENT B: %lg\n", measurements[1]);
	printf("MEASUREMENT C: %lg\n", measurements[2]);

	printf("AVERAGE: %lg", average);
}

void ArrayStackExp2_1()
{
	int start = clock();

	Array* ArrayStack = constructArray(50000, 2, MULTIPLY);

	int length = (int)1e6;
	for (int _ = 0; _ < 9; ++_)
	{
		for (int i = 0; i < length; ++i)
		{
			pushArray(ArrayStack, i);
		}
		printf("SIZE AFTER PUSH: %d\n", ArrayStack->size);

		length = (int)ArrayStack->size / 2;
		for (int i = 0; i < length; ++i)
		{
			popArray(ArrayStack);
		}
		printf("SIZE AFTER POP: %d\n\n", ArrayStack->size);
		length = (int)ArrayStack->size / 2;

	}
}

int Randomly()
{
	return rand() % 2;
}

int main()
{
	double* measurements = (double*)calloc(3, sizeof(double));

	List* Stack = constructList();
	
	for (int i = 0; i < 1e6; ++i)
	{
		pushList(Stack, i);
	}

	for (int j = 0; j < 3; ++j)
	{
		int start = clock();
		for (int i = 0; i < (int)1e6; ++i)
		{
			if (Randomly())
			{
				pushList(Stack, i);
			}
			else
			{
				popList(Stack);
			}
		}
		measurements[j] = difftime(clock(), start) / CLOCKS_PER_SEC;
	}
	double average = (double)(measurements[0] + measurements[1] + measurements[2]) / 3;

	printf("MEASUREMENT A: %lg\n", measurements[0]);
	printf("MEASUREMENT B: %lg\n", measurements[1]);
	printf("MEASUREMENT C: %lg\n", measurements[2]);

	printf("AVERAGE: %lg", average);

	return 0;
}
