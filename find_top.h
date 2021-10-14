#ifndef IZ_1_FIND_TOP_H
#define IZ_1_FIND_TOP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct comment
{
	int				date_comment;
	int				month_comment;
	int				year_comment;

	char			*content;
	struct comment	*next;
}comment;

typedef struct like
{
	int			date_like;
	int			month_like;
	int			year_like;

	struct like *next;
}like;

typedef struct tag
{
	char		*content;
	struct	tag	*next;
}tag;

typedef	struct blog_list
{
	char	*name;
	char	*content;
	tag		*tags;
	comment	*comments;
	like	*likes;

	int		date_publication;
	int		month_publication;
	int		year_publication;

	struct	blog_list *next;
}blog_list;


blog_list	*find_top(blog_list *blogList);


blog_list	*add_new_blog1(blog_list *head, int date, int month, int year);
blog_list	*add_new_blog2(blog_list *head, int date, int month, int year);
blog_list	*add_new_blog3(blog_list *head, int date, int month, int year);

tag			*add_new_tag(tag *head, char *content);
like		*add_new_like(like *head, int date, int month, int year);
comment		*add_new_comment(comment *head, char *content, int date, int month, int year);

void free_all_blog(blog_list *blogList);
int	set_time(int date, int month, int year);
int compare_struct(const blog_list *a, const blog_list *b);

#endif //IZ_1_FIND_TOP_H
