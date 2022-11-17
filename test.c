/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunne <adunne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:36:04 by adunne            #+#    #+#             */
/*   Updated: 2022/11/17 15:49:03 by adunne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void handler(int num){
	write(STDOUT_FILENO, "I won't die\n", 13);
}


int main()
{
	signal(SIGINT, handler);
	while (1)
	{
		printf("Wasting your cycles. %d\n", getpid());
		sleep(1);
	}
}
