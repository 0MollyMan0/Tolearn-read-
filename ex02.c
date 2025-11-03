/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:01:39 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/03 12:03:17 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("text.txt", O_RDONLY);
    if (fd == -1)
	{ 
		printf("open error");
		return 1;
	}
    char buffer[11];
    ssize_t bytes = read(fd, buffer, 10);
    if (bytes == -1) {
        printf("read error");
        return 1;
    }

    buffer[bytes] = '\0';
    printf("Read %zd bytes: %s\n", bytes, buffer);

    close(fd);
    return 0;
}