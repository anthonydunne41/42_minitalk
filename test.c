/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunne <adunne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:36:04 by adunne            #+#    #+#             */
/*   Updated: 2022/11/27 15:31:16 by adunne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void handler(int num) {
	write(STDOUT_FILENO, "Poo poo pee pee\n", 16);
}

void printOne(int num) {
	write(STDOUT_FILENO, "1\n", 2);
}

void printZero(int num) {
	write(STDOUT_FILENO, "0\n", 2);
}

int main()
{
	printf("%d\n", getpid());
	//signal(SIGINT, handler);
	signal(SIGUSR1, printOne);
	signal(SIGUSR2, printZero);
	printf("\n");
	printf("%d", getpid());
	while (1) {
		printf("Penis\n");
		sleep(10);
	}

	return 0;
}



// void handler(int num) {
// 	write(STDOUT_FILENO, "Poo poo pee pee\n", 16);
// }

// int main()
// {
// 	struct sigaction sa;

// 	sa.sa_handler = handler;

// 	sigaction(SIGINT, &sa, NULL);
// 	printf("%d", getpid());
// 	while (1) {
// 		printf("Penis\n");
// 		sleep(1);
// 	}

// 	return 0;
// }
