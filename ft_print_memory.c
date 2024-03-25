#include <unistd.h>

void    *ft_print_memory(void *addr, unsigned int size)
{
    (char)addr;
    
}

unsigned int    ft_strlen(char *addr)
{
    unsigned int i;

    i = -1;
    while (addr[++i])
    return (i);
}

int main(void)
{
    void addr[] = "Bonjour les amin";
    ft_print_memory(addr, ft_strlen(addr));
}