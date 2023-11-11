#include "shell.h"

/**
 *_m_errors - A function that frees memory.
 *@arr: first arg
 *Return: NULL
 */
static char	**_m_errors(char	**arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

/**
 *_ft_cnt_wds - Function that counts the number of words.
 *@str: first arg
 *@charset: sec arg
 *Return: num of words.
 */
static int	_ft_cnt_wds(char const *str, char charset)
{
	int	i;
	int	nbr_w;

	nbr_w = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == charset))
			i++;
		if (str[i])
			nbr_w++;
		while (str[i] && !(str[i] == charset))
			i++;
	}
	return (nbr_w);
}

/**
 * _ft_wds_len - This func calculate the lenth.
 *@str: first arg
 *@charset: sec arg
 *Return: the length.
 */
static int	_ft_wds_len(char const *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && !(str[i] == charset))
		i++;
	return (i);
}

/**
 *ft_wds_grp - A function that extracts a word.
 *@str: first arg
 *@charset: sec arg
 *Return: new word.
 */
static char	*ft_wds_grp(char const *str, char charset)
{
	int		len_w;
	int		i;
	char	*word;

	i = 0;
	len_w = _ft_wds_len(str, charset);
	word = malloc(sizeof(char) * (len_w + 1));
	if (!word)
		return (NULL);
	while (i < len_w)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

/**
 *the_split - string array of substrings.
 *@s: first arg
 *@c: sec arg
 *Return: An array of pointers.
 */
char	**the_split(char const *s, char c)
{
	int			i;
	char		**splited;

	if (!s)
		return (NULL);
	i = 0;
	splited = malloc(sizeof(char *) * (_ft_cnt_wds(s, c) + 1));
	if (!splited)
		return (NULL);
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s)
		{
			splited[i] = ft_wds_grp(s, c);
			if (!splited[i])
				return (_m_errors(splited));
			i++;
		}
		while (*s && !(*s == c))
			s++;
	}
	splited[i] = 0;
	return (splited);
}
