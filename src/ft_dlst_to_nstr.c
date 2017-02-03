#include "libft.h"

char	*ft_dlst_to_nstr(t_dlist *lst, size_t n)
{
	char	*ret;
	char	*ptr;

	ret = ft_strnew(n);
	if (!ret)
		return (NULL);
	ptr = ret;
	while (n)
	{
		*(ret++) = *((char *)lst->content);
		lst = lst->next;
		n--;
	}
	*ret = '\0';
	return (ptr);
}
