# include "headers/ft_printf.h"

int main()
{
	int result;
	
	result= ft_printf("Sentence to know how many %s\n", "characters were written");
	ft_printf("%d result", result);
	return (0);
}