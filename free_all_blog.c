#include "find_top.h"
void free_all_blog(blog_list *blogList)
{
	blog_list *current = blogList;
	blog_list *temp_blog;
	while (current != NULL)
	{
		temp_blog = current->next;

		free(current->name);
		free(current->content);

		like *current_likes = current->likes;
		like *temp_likes;

		comment *current_comments = current->comments;
		comment *temp_comment;

		tag *current_tag = current->tags;
		tag *temp_tag;

		while (current_tag != NULL)
		{
			temp_tag = current_tag->next;
			current_tag->next = NULL;
			free(current_tag->content);
			free(current_tag);
			current_tag = temp_tag;
		}
		while (current_likes != NULL)
		{
			temp_likes = current_likes->next;
			current_likes->next = NULL;
			free(current_likes);
			current_likes = temp_likes;
		}
		while (current_comments != NULL)
		{
			temp_comment = current_comments->next;
			current_comments->next = NULL;
			free(current_comments->content);
			free(current_comments);
			current_comments = temp_comment;
		}
		current->next = NULL;
		free(current);
		current = temp_blog;
	}
}

