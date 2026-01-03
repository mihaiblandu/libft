/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihaiblandu <mihaiblandu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 21:30:00 by mihaiblandu       #+#    #+#             */
/*   Updated: 2026/01/02 23:48:05 by mihaiblandu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_tree/trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	print_test_result(const char *test_name, bool passed)
{
	printf("%s: %s\n", test_name, passed ? "PASS" : "FAIL");
}

int	main(void)
{
	t_trie	*trie;
	char	*value1;
	char	*value2;
	char	*value3;
	char	*search_result;

	trie = trie_create_node();
	if (!trie)
	{
		printf("Failed to create trie\n");
		return (1);
	}

	// Test insertion and search
	value1 = strdup("hello world");
	value2 = strdup("test value");
	value3 = strdup("another value");

	print_test_result("Insert 'hello'", trie_insert(trie, "hello", value1));
	print_test_result("Insert 'test'", trie_insert(trie, "test", value2));
	print_test_result("Insert 'another'", trie_insert(trie, "another", value3));

	// Test search
	search_result = (char *)trie_search(trie, "hello");
	print_test_result("Search 'hello'", search_result && strcmp(search_result, "hello world") == 0);

	search_result = (char *)trie_search(trie, "test");
	print_test_result("Search 'test'", search_result && strcmp(search_result, "test value") == 0);

	search_result = (char *)trie_search(trie, "another");
	print_test_result("Search 'another'", search_result && strcmp(search_result, "another value") == 0);

	// Test search for non-existent key
	search_result = (char *)trie_search(trie, "nonexistent");
	print_test_result("Search 'nonexistent'", search_result == NULL);

	// Test prefix search (should return NULL)
	search_result = (char *)trie_search(trie, "hel");
	print_test_result("Search prefix 'hel'", search_result == NULL);

	// Test deletion
	print_test_result("Delete 'test'", trie_delete(&trie, "test"));
	search_result = (char *)trie_search(trie, "test");
	print_test_result("Search deleted 'test'", search_result == NULL);

	// Verify other keys still exist
	search_result = (char *)trie_search(trie, "hello");
	print_test_result("Search 'hello' after deletion", search_result && strcmp(search_result, "hello world") == 0);

	// Test case sensitivity
	print_test_result("Insert 'Hello' (uppercase)", trie_insert(trie, "Hello", value1));
	search_result = (char *)trie_search(trie, "Hello");
	print_test_result("Search 'Hello'", search_result != NULL);

	// Clean up
	trie_free(&trie, free);
	
	// Test free on NULL
	trie_free(&trie, free);
	print_test_result("Free NULL trie", trie == NULL);

	printf("\nAll tests completed!\n");
	return (0);
}
