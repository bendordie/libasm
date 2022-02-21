/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:24:48 by cshells           #+#    #+#             */
/*   Updated: 2021/02/21 00:49:27 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void	ft_bzero(void *s, size_t n)
{
    while (n--)
        *(char*)(s + n) = '\0';
}


int main(void)
{
    int fd_o = open("./test.txt", O_RDONLY);
    int fd_c = open("./test2.txt", O_RDONLY);
    char *s_null = NULL;
    char s_buf0[256];
    char s_buf1[256];
    char *dest_o;
    char *dest_c;

	printf(ANSI_COLOR_YELLOW "\n============== STRLEN ==============\n" ANSI_COLOR_RESET);

    printf("\n___________random strings___________\n\n");
    printf("ORIGIN: %zu$\n", strlen("The length of this string is 42 characters"));
	printf("CUSTOM: %zu$\n", ft_strlen("The length of this string is 42 characters"));

    printf("\n___________empty strings____________\n\n");
    printf("ORIGIN: %zu$\n", strlen(""));
    printf("CUSTOM: %zu$\n", ft_strlen(""));


    printf(ANSI_COLOR_YELLOW "\n============== STRCPY ==============\n" ANSI_COLOR_RESET);

    printf("\n___________random strings___________\n\n");
    printf("ORIGIN: %s$\n", strcpy(s_buf0, "Hello World!"));
    printf("CUSTOM: %s$\n", ft_strcpy(s_buf1, "Hello World!"));
    ft_bzero(s_buf0, 256);
    ft_bzero(s_buf1, 256);
    printf("\n___________empty strings____________\n\n");
    printf("ORIGIN: %s$\n", strcpy(s_buf0, ""));
    printf("CUSTOM: %s$\n", ft_strcpy(s_buf1, ""));
    ft_bzero(s_buf0, 256);
    ft_bzero(s_buf1, 256);
    printf(ANSI_COLOR_YELLOW "\n============== STRCMP ==============\n" ANSI_COLOR_RESET);

    printf("\n___________equal strings___________\n\n");
    printf("ORIGIN: %d$\n", strcmp("Hello World!", "Hello World!"));
    printf("CUSTOM: %d$\n", ft_strcmp("Hello World!", "Hello World!"));

    printf("\n_________different +strings_________\n\n");
    printf("ORIGIN: %d$\n", strcmp("Hello World1", "Hello World9"));
    printf("CUSTOM: %d$\n", ft_strcmp("Hello World1", "Hello World9"));

    printf("\n_________different -strings_________\n\n");
    printf("ORIGIN: %d$\n", strcmp("Hello World9", "Hello World1"));
    printf("CUSTOM: %d$\n", ft_strcmp("Hello World9", "Hello World1"));

    printf("\n___________empty strings___________\n\n");
    printf("ORIGIN: %d$\n", strcmp("", ""));
    printf("CUSTOM: %d$\n", ft_strcmp("", ""));

    printf(ANSI_COLOR_YELLOW "\n============== STRDUP ==============\n" ANSI_COLOR_RESET);

    printf("\n___________random strings___________\n\n");
    printf("ORIGIN: %s$\n", strdup("Hello World!"));
    printf("CUSTOM: %s$\n", ft_strdup("Hello World!"));

    printf("\n___________empty strings____________\n\n");
    printf("ORIGIN: %s$\n", strdup(""));
    printf("CUSTOM: %s$\n", ft_strdup(""));


    printf(ANSI_COLOR_YELLOW "\n============== WRITE ==============\n" ANSI_COLOR_RESET);

    printf("\n_______write random strings_______\n\n");
    int o = write(1, "ORIGIN: Hello World!$\n", 22);
    int c = ft_write(1, "CUSTOM: Hello World!$\n", 22);

    printf("\n__________return success__________\n\n");
    printf("ORIGIN: %d$\n", o);
    printf("CUSTOM: %d$\n", c);

    printf("\n___________write error___________\n\n");
    o = write(1, "ORIGIN: Hello World!\n", -123);
    perror(ANSI_COLOR_RED "ORIGIN ERROR" ANSI_COLOR_RESET);
    c = ft_write(1, "CUSTOM: Hello World!\n", -123);
    perror(ANSI_COLOR_RED "CUSTOM ERROR" ANSI_COLOR_RESET);
    printf("ORIGIN: %d$\n", o);
    printf("CUSTOM: %d$\n", c);

    printf(ANSI_COLOR_YELLOW "\n=============== READ ===============\n" ANSI_COLOR_RESET);

    printf("\n___read random strings from file___\n\n");
    o = read(fd_o, s_buf0, 21);
    c = ft_read(fd_c, s_buf1, 21);
    printf("ORIGIN: %s$\n", s_buf0);
    printf("CUSTOM: %s$\n", s_buf1);
    ft_bzero(s_buf0, 256);
    ft_bzero(s_buf1, 256);
    printf("\n___________return success___________\n\n");
    printf("ORIGIN: %d$\n", o);
    printf("CUSTOM: %d$\n", c);

    printf("\n___________read error fd___________\n\n");
    o = read(123, s_buf0, 0);
    perror(ANSI_COLOR_RED "ORIGIN ERROR" ANSI_COLOR_RESET);
    c = ft_read(123, s_buf1, 0);
    perror(ANSI_COLOR_RED "CUSTOM ERROR" ANSI_COLOR_RESET);
    printf("ORIGIN: %d$\n", o);
    printf("CUSTOM: %d$\n", c);

	return (0);
}
