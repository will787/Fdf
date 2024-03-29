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
    data->map = route_map;
    if(!ft_strnstr(data->map, ".fdf", ft_strlen(data->map))){
        fprintf(stderr, "invalid format file \n");
        return(-1);
    }
    data->width = drop_width(data->map);
    data->height = drop_height(data->map);

    data->z_3d = (int **)malloc(sizeof(int *) * (data->height + 1));
    if(!data->z_3d){
        perror("Memory allocation failled");
        return -1;
    }
    i = 0;
    while(i <= data->height)
        data->z_3d[i++] = (int *)malloc(sizeof(int) * (data->width + 1));

    fd = open(data->map, O_RDONLY);
    i = 0;
    while((line = get_next_line(fd)) != NULL)
    {
        alloc_matrix(line, data->z_3d[i]);
        free(line);
        i++;
    }
    close(fd);
    data->z_3d[i] = NULL;
    return (1);
}

void alloc_matrix(char *line, int *z_line3d)
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
        free(counters_wd[i]);
        i++;
    }
    free(counters_wd);
    return(i);
}