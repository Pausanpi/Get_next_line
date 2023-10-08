char	*ft_strchr(const char *s, int c)
{
	int				aux;
	unsigned char	*tmp;

	aux = 0;
	tmp = (unsigned char *)s;
	while (tmp[aux] != '\0')
	{
		if (tmp[aux] == (unsigned char)c)
			return ((char *)&s[aux]);
		aux++;
	}
	if (c == '\0' || c == 1024)
		return ((char *)&s[aux]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	x;
	size_t	y;

	str = malloc(sizeof(char) * ((size_t)ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	x = 0;
	y = 0;
	while (s1[x])
	{
		str[x] = s1[x];
		x++;
	}
	while (s2[y])
	{
		str[x + y] = s2[y];
		y++;
	}
	str[x + y] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	cont;

	cont = 0;
	while (s[cont] != '\0')
		cont++;
	return (cont);
}