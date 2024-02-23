#include "../includes/fdf.h"

int32_t main(int argc, char *argv[])
{  
    fdf *data;

    data = (fdf*)malloc(sizeof(fdf));
    if(argc != 2 || (read_map(argv[1], data) == -1))
        return -1;
    init_map(data);
    free(data);
	return(EXIT_SUCCESS);
    return(0);
}



