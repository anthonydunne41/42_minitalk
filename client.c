/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunne <adunne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:37:40 by adunne            #+#    #+#             */
/*   Updated: 2022/11/27 20:03:48 by adunne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	send_bits(int pid, unsigned char c)
{
	int	counter;

	counter = 0;
	while (counter <= 7)
	{
		if (c & (0x80 >> counter))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		counter++;
		usleep(100);
	}
}

int main(int argc, char* argv[])
{
	pid_t pid = atoi(argv[1]);
	// int command = atoi(argv[2]);
	int stringLen = strlen(argv[2]);
	int i = 0;

	while (i < stringLen)
	{
		send_bits(pid, &argv[2]);
		usleep(100);
		i++;
	}

	//sleep(5);
	//kill(pid, SIGKILL);
}
