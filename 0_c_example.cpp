#include <memory.h>
#include <stdlib.h>
#include <stdio.h>


// Each struct instance has an int and float member variable
struct s 
{
	int x;
	float y;
};

// Allocate an array
struct s* allocate_struct_s_buffer(int num_elements)
{
	struct s* s_ptr = (struct s*)malloc(num_elements * sizeof(struct s));
	return s_ptr;
}

// Deallocate an array
void deallocate_struct_s_buffer(struct s* s_ptr)
{
	if(s_ptr != NULL)
		free(s_ptr);
}


int main(void)
{
	int i = 0;

	// Allocate buffer
	int num_elements = 10;
	struct s* s_ptr = allocate_struct_s_buffer(num_elements);

	if (s_ptr == NULL)
		return 1;

	// Set the variables, then print them to the console
	for (i = 0; i < num_elements; i++)
	{
		s_ptr[i].x = rand();
		s_ptr[i].y = rand() / (float)RAND_MAX;

		printf("%d %f\n", s_ptr[i].x, s_ptr[i].y);
	}

	// When using malloc, you must not forget to call free when the 
	// buffer is no longer needed, otherwise a memory leak will occur
	deallocate_struct_s_buffer(s_ptr);

	return 0;
}
