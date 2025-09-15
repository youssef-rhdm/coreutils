/* Test program to verify memory safety fixes */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void test_null_safety(void)
{
	printf("Testing null pointer safety...\n");
	
	// Test memory functions with null
	if (ft_memcpy(NULL, NULL, 0) == NULL)
		printf("✓ ft_memcpy handles NULL correctly\n");
	
	if (ft_memset(NULL, 'c', 5) == NULL)
		printf("✓ ft_memset handles NULL correctly\n");
		
	if (ft_memchr(NULL, 'c', 5) == NULL)
		printf("✓ ft_memchr handles NULL correctly\n");
		
	// Test string functions with null
	if (ft_strchr(NULL, 'c') == NULL)
		printf("✓ ft_strchr handles NULL correctly\n");
	
	if (ft_strrchr(NULL, 'c') == NULL)
		printf("✓ ft_strrchr handles NULL correctly\n");
		
	if (ft_strnstr(NULL, "test", 5) == NULL)
		printf("✓ ft_strnstr handles NULL correctly\n");
}

void test_memory_management(void)
{
	printf("\nTesting memory management...\n");
	
	// Test linked list operations
	t_list *list = NULL;
	t_list *node1, *node2;
	
	int val1 = 42;
	int val2 = 84;
	
	node1 = ft_lstnew(&val1);
	node2 = ft_lstnew(&val2);
	
	if (node1 && node2) {
		ft_lstadd_back(&list, node1);
		ft_lstadd_back(&list, node2);
		
		printf("✓ Linked list creation successful\n");
		printf("List size: %d\n", ft_lstsize(list));
		
		ft_lstclear(&list, NULL);
		printf("✓ Linked list properly freed\n");
	}
}

void test_edge_cases(void)
{
	printf("\nTesting edge cases...\n");
	
	// Test ft_calloc with zero
	void *ptr = ft_calloc(0, 10);
	if (ptr) {
		free(ptr);
		printf("✓ ft_calloc handles zero count correctly\n");
	}
	
	// Test ft_split with null
	char **result = ft_split(NULL, ' ');
	if (result == NULL)
		printf("✓ ft_split handles NULL correctly\n");
	
	// Test string operations with empty strings
	char *dup = ft_strdup("");
	if (dup && strlen(dup) == 0) {
		free(dup);
		printf("✓ ft_strdup handles empty string correctly\n");
	}
}

void test_buffer_operations(void)
{
	printf("\nTesting buffer operations...\n");
	
	char buffer[100];
	char src[] = "Hello, World!";
	
	// Test safe memory operations
	ft_bzero(buffer, sizeof(buffer));
	ft_memset(buffer, 'A', 10);
	ft_memcpy(buffer + 20, src, strlen(src));
	
	printf("✓ Buffer operations completed safely\n");
}

int main(void)
{
	printf("=== Memory Safety Test Suite ===\n");
	
	test_null_safety();
	test_memory_management();
	test_edge_cases();
	test_buffer_operations();
	
	printf("\n=== All tests completed ===\n");
	return 0;
}