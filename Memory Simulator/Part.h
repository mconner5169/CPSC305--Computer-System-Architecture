typedef struct {
	char name[80];
	long number;
	double cost;
} Part;

extern Part * find_longest(Part *parts, int num_of_parts);

extern void read_parts(Part parts[], int *num_of_parts);
