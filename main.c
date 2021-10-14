#include "find_top.h"


int main() {
	blog_list *blogList = NULL;
	//add_new blog1
	blogList = add_new_blog1(blogList, 10, 4, 2021);
	if (blogList == NULL)
		return 1;
	//add_new blog2
	blogList = add_new_blog2(blogList, 20, 5, 2021);
	if (blogList == NULL)
		return 1;
	//add_new blog3
	blogList = add_new_blog3(blogList, 15, 6, 2021);
	if (blogList == NULL)
		return 1;

	blog_list *current = blogList;

	current = find_top(current);

	printf("top_blog: %s", current->name);

	free_all_blog(blogList);
	return 0;;
}
