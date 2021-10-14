#include "find_top.h"

blog_list	*find_top(blog_list *blogList)
{
	if (blogList == NULL)
		return NULL;
	blog_list *current = blogList;
	blog_list *top_current = blogList;
	int likes_and_comments = 0;
	int max_likes_and_comments = 0;

	while (current != NULL)
	{
		comment	*current_comments = current->comments;
		like	*current_likes = current->likes;

		//+comments
		while (current_comments != NULL)
		{
			if((set_time(current_comments->date_comment, current_comments->month_comment,
						current_comments->year_comment) >= set_time(current->date_publication,
						current->month_publication, current->year_publication)) &&
					(set_time(current_comments->date_comment, current_comments->month_comment,
						current_comments->year_comment)  <= set_time(current->date_publication,
						current->month_publication, current->year_publication) + 30))
				likes_and_comments++;
			current_comments = current_comments->next;
		}
		//+likes
		while (current_likes != NULL)
		{
			if((set_time(current_likes->date_like, current_likes->month_like,
						current_likes->year_like) >= set_time(current->date_publication,
						current->month_publication, current->year_publication)) &&
			   (set_time(current_likes->date_like, current_likes->month_like,
						current_likes->year_like)  <= set_time(current->date_publication,
						current->month_publication, current->year_publication) + 30))
				likes_and_comments++;
			current_likes = current_likes->next;
		}

		//printf("%d\n", likes_and_comments);

		if(likes_and_comments > max_likes_and_comments)
		{
			max_likes_and_comments = likes_and_comments;
			top_current = current;
		}
		likes_and_comments = 0;
		current = current->next;
	}
	//printf("%d\n", max_likes_and_comments);
	return (top_current);
}

int	set_time(int date, int month, int year)
{
	if (!((date <= 31 && date >=0) && (month <= 12 && month >= 0) && year >= 0))
		return (0);

	return (date + month * 31 + year * 365);
}

int compare_struct(const blog_list *a, const blog_list *b)
{
	if (strcmp(a->name, b->name) != 0)
		return 0;
	if (strcmp(a->content, b->content) != 0)
		return 0;
	if (a->year_publication != b->year_publication || a->month_publication != b->month_publication || a->date_publication != b->date_publication)
		return 0;
	tag *temp_tag_a = a->tags;
	tag *temp_tag_b = b->tags;
	while (temp_tag_a != NULL && temp_tag_b != NULL)
	{
		if(strcmp(temp_tag_b->content, temp_tag_a->content) != 0)
			return 0;
		temp_tag_b = temp_tag_b->next;
		temp_tag_a = temp_tag_a->next;
	}
	comment *temp_comment_a = a->comments;
	comment *temp_comment_b = b->comments;
	while (temp_comment_a != NULL && temp_comment_b != NULL)
	{
		if(strcmp(temp_comment_a->content, temp_comment_b->content) != 0)
			return 0;
		if (temp_comment_a->year_comment != temp_comment_b->year_comment
		|| temp_comment_a->month_comment != temp_comment_b->month_comment
		|| temp_comment_a->date_comment != temp_comment_b->date_comment)
			return 0;
		temp_comment_a = temp_comment_a->next;
		temp_comment_b = temp_comment_b->next;
	}
	like *temp_like_a = a->likes;
	like *temp_like_b = b->likes;
	while (temp_like_a != NULL && temp_like_b != NULL)
	{
		if (temp_like_a->year_like != temp_like_b->year_like
			|| temp_like_a->month_like != temp_like_b->month_like
			|| temp_like_a->date_like != temp_like_b->date_like)
			return 0;
		temp_like_a = temp_like_a->next;
		temp_like_b = temp_like_b->next;
	}
	return 1;
}