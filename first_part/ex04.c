/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:52:20 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/03 15:06:57 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int src;
	int	dst;
	ssize_t bytes;
	char buffer[11];

	src = open("text.txt", O_RDONLY);
	dst = open("copy.txt", O_WRONLY);
    if (src == -1)
	{ 
		printf("open error");
		return 1;
	}
	while ((bytes = read(src, buffer, 10)) > 0)
	{
		buffer[bytes] = '\0';
		write(dst, buffer, bytes);
	}
	if (bytes == -1)
		printf("read error\n");
    close(src);
	close(dst);
    return 0;
}