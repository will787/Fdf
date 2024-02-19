#include "../includes/fdf.h"

int32_t main(int argc, char *argv[])
{  
    fdf *data;

    data = (fdf*)malloc(sizeof(fdf));
    if(argc != 2 || (read_map(argv[1], data) == -1))
        return -1;
    int i;
    int j;
    
    i = 0;
    while(i < data->y)
    {    
        j = 0;
        while(j < data->x)
        {
            printf("%3d", data->z_3d[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    return(0);
}