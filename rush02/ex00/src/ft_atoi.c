int ft_atoi(char *a)
{
	int i;
	int signe;
	int nb;

	i = 0;
	signe = 1;
	nb = 0;

	if (a[i] == '-' || a[i] == '+')
	{
		if (a[i] == '-')
			signe *= -1;
		i++;
	}
	
	while (a[i] >= '0' && a[i] <= '9' && a[i] != 0)
	{
		nb = nb * 10 + (a[i] - '0');
		i++;
	}
	return (nb * signe);
}