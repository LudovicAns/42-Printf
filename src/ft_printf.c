#include "ft_printf_utils.h"

int	ft_printf(const char *format, ...)
{
	return (get_numspecification(format));
}
