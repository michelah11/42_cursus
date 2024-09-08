/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 01:08:46 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/09/07 02:17:07 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 2)
    {
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        while(argv[1][i] != '\0')
        {
            while(argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i])
            {
                write(1, &argv[1][i], 1);
                i++;
            }
            while (argv[1][i] == ' ' || argv[1][i] == '\t')
                i++;
            if (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i])
                if (argv[1][i - 1] == ' ' || argv[1][i - 1] == '\t')
                    write(1, "   ", 3);
        }
    }
    write(1, "\n", 1);
    return (0);
}