#include "../includes/fdf.h"

int read_map(char *route_map)
{
    int fd;
    char *line;
    char *rout;

    rout = route_map;
    fd = open(rout, O_RDWR);
    if(fd < 0){
        ft_printf("Erro ao abrir o arquivo\n");
        return -1;
    }
    printf("\n\nEsse é o valor do fd: %i\n", fd);
    while((line = get_next_line(fd)) != NULL)
    {
        ft_printf("%s", line);
        free(line);
    }
    close(fd);
    return 1;
}