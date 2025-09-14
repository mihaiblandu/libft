/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 21:33:00 by mihaiblandu       #+#    #+#             */
/*   Updated: 2025/09/14 21:34:03 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./includes/list.h"

int main() {
    DynamicList *list;
    int value;
    int *retrieved;
    int i;

    list = list_create(sizeof(int));
    if (!list) {
        printf("Failed to create list\n");
        return 1;
    }

    // Use the variables
    for (i = 0; i < 5; i++) {
        value = i * 10;
        list_add(list, &value);
    }

    // Retrieve and print values
    for (i = 0; i < (int)list_size(list); i++) {
        retrieved = (int*)list_get(list, i);
        if (retrieved)
            printf("Element %d: %d\n", i, *retrieved);
    }

    list_free(list);
    return 0;
}