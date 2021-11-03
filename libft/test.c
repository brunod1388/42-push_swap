

#include "libft.h"
#include <stdio.h>

int main (void)
{	
	ft_putstr("Hello\nWorld");
	ft_putchar('\n');
	ft_putchar('\n');

	char *str;

	/* Initial memory allocation */
	str = (char *) malloc(15);
	ft_strcpy(str, "tutorialspoint");
	printf("String = %s,  Address = %p\n", str, str);

	/* Reallocating memory */
	str = (char *) ft_realloc(str, 25);
	ft_strcat(str, ".com");
	printf("String = %s,  Address = %p\n", str, str);

	free(str);
	while (1);
	return (0);
}