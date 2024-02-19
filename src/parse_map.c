#include "../includes/fdf.h"

int drop_height(char* route_map)
{
    int fd;
    int len_height;
    char *line;

    fd = open(route_map, O_RDONLY);
    
    len_height = 0;
    while((line = get_next_line(fd)) != NULL)
    {
        len_height++;
        free(line);
    }
    close(fd);
    return(len_height);
}

int drop_width(char *route_map)
{
    int fd;
    int widht_line;
    char *line;

    fd = open(route_map, O_RDONLY);
    line = get_next_line(fd);
    widht_line = ft_split_values(line, ' ');
    free(line);
    return(widht_line);
}

int read_map(char *route_map, fdf *data)
{
    int i;
    int fd;
    char *line;

    if(!ft_strnstr(route_map, ".fdf", ft_strlen(route_map))){
        fprintf(stderr, "invalid format file \n");
        return(-1);
    }
    data->x = drop_width(route_map);
    data->y = drop_height(route_map);

    data->z_3d = (int **)malloc(sizeof(int *) * (data->y + 1));
    if(!data->z_3d){
        perror("Memory allocation failled");
        return -1;
    }

    i = 0;
    while(i <= data->y)
        data->z_3d[i++] = (int *)malloc(sizeof(int) * (data->x + 1));

    fd = open(route_map, O_RDONLY);
    i = 0;
    while((line = get_next_line(fd)) != NULL)
    {
        clear_matrix(line, data->z_3d[i]);
        free(line);
        i++;
    }
    close(fd);
    data->z_3d[i] = NULL;
    return (1);
}

void clear_matrix(char *line, int *z_line3d)
{
    int i;
    char **num_line;

    i = 0;
    num_line = ft_split(line, ' ');
    while(num_line[i])
    {
        z_line3d[i] = ft_atoi(num_line[i]);
        free(num_line[i]);
        i++;
    }
    free(num_line);
}


int ft_split_values(char *line, char c)
{
    int i;
    char **counters_wd;

    counters_wd = ft_split(line, c);
    
    i = 0;
    while(counters_wd[i])
    {
        i++;
    }
    return(i);
}