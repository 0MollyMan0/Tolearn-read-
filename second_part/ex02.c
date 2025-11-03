/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:34:32 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/03 15:34:42 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print_n(const char *file, int n)
{
	
}

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        write(2, "Usage: ./a.out <file> <n>\n", 27);
        return (1);
    }
    print_n(argv[1], atoi(argv[2]));
    return (0);
}
