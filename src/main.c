#include "../includes/fdf.h"

int32_t main(int argc, char *argv[])
{  
    fdf *data;

    data = (fdf*)malloc(sizeof(data));
    
    if(argc != 2 || !argv)
        return (printf("Passe o caminho do mapa\n"));
    
    if(read_map(argv[1], data) == -1)
        return(printf("mapa inválido\n"));

    return(0);
}
