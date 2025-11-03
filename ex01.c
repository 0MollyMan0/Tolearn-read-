/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:51:26 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/03 11:57:41 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("text.txt", O_RDONLY);

    if (fd == -1) 
	{
        printf("Failed");
        return 1;
    }
    printf("Sucess");
    close(fd);
    return 0;
}