/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:38:17 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/03 12:50:43 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd;
	ssize_t bytes;
	char buffer[11];

	fd = open("text.txt", O_RDONLY);
    if (fd == -1)
	{ 
		printf("open error");
		return 1;
	}
	while ((bytes = read(fd, buffer, 10)) > 0)
	{
		buffer[bytes] = '\0';
		write(1, buffer, bytes);
	}
	if (bytes == -1)
	{
		printf("read error\n");
	}
    close(fd);
    return 0;
}