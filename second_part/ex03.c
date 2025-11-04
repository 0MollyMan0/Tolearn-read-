/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:02:16 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/04 09:15:28 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void count_lines(const char *name, int n)
{
	int file;
	ssize_t bytes;
	char *buffer;
	int lines;
	int i;

	lines = 0;
	file = open(name, O_RDONLY);
	buffer = malloc(n);
	if (file == -1 || !buffer)
	{
		if (file == -1)
			return;
		close(file);
		return;
	}
	while((bytes = read(file, buffer, n)) > 0)
	{
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				lines++;
			i++;
		}
	}
	if (bytes == -1)
		write(1, "read error", 10);
	else
		printf("Number of lines: %d\n", lines+1);
	close(file);
}

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        write(2, "Usage: ./a.out <file> <n>\n", 27);
        return (1);
    }
    count_lines(argv[1], atoi(argv[2]));
    return (0);
}