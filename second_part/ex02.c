/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:34:32 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/03 15:46:35 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print_all(const char *name, int n)
{
	int file;
	ssize_t bytes;
	char *buffer;

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
		write(1, buffer, bytes);
	if (bytes == -1)
		write(1, "read error", 10);
	else
		write(1, "\n\nend of file\n", 14);
	close(file);
}

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        write(2, "Usage: ./a.out <file> <n>\n", 27);
        return (1);
    }
    print_all(argv[1], atoi(argv[2]));
    return (0);
}
