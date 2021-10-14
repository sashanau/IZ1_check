#include "find_top.h"

blog_list *add_new_blog1(blog_list *head, int date, int month, int year)
{
	//add_new blog 10, 4, 2021
	blog_list *blogList = NULL;
	blogList = malloc(sizeof(blog_list));
	if (blogList == NULL)
		return NULL;

	//add_new name
	blogList->name = (char *) malloc(sizeof(char) * (strlen("Cat") + 1));
	if (blogList->name == NULL)
		return NULL;
	strcpy(blogList->name, "Cat");

	//add_new content
	blogList->content = (char *) malloc(sizeof(char) * (strlen("Good cat") + 1));
	if (blogList->content == NULL)
		return NULL;
	strcpy(blogList->content, "Good cat");

	//add_tags
	blogList->tags = NULL;
	blogList->tags = add_new_tag(blogList->tags, "@cat");
	if (blogList->tags == NULL)
		return NULL;
	blogList->tags = add_new_tag(blogList->tags, "@cats");
	if (blogList->tags == NULL)
		return NULL;
	blogList->tags = add_new_tag(blogList->tags, "@catssss");
	if (blogList->tags == NULL)
		return NULL;

	//add_likes
	blogList->likes = NULL;
	blogList->likes = add_new_like(blogList->likes, 5, 5, 2021); //in 30
	if (blogList->likes == NULL)
		return NULL;
	blogList->likes = add_new_like(blogList->likes, 21, 5, 2021); //no in 30
	if (blogList->likes == NULL)
		return NULL;
	blogList->likes = add_new_like(blogList->likes, 28, 5, 2021); //no in 30
	if (blogList->likes == NULL)
		return NULL;

	//add_new comments
	blogList->comments = NULL;
	blogList->comments = add_new_comment(blogList->comments, "I like cats", 10, 4, 2021); //in 30
	if (blogList->comments == NULL)
		return NULL;
	blogList->comments = add_new_comment(blogList->comments, "I like cats", 20, 4, 2021); //in 30
	if (blogList->comments == NULL)
		return NULL;
	blogList->comments = add_new_comment(blogList->comments, "I like cats", 30, 4, 2021); //in 30
	if (blogList->comments == NULL)
		return NULL;


	//add_new date
	blogList->date_publication = date;
	blogList->month_publication = month;
	blogList->year_publication = year;

	blogList->next = head;

	return (blogList);
}

blog_list *add_new_blog2(blog_list *head, int date, int month, int year)
{
	//add_new blog 20, 5, 2021
	blog_list *blogList = NULL;
	blogList = malloc(sizeof(blog_list));
	if (blogList == NULL)
		return NULL;

	//add_new name
	blogList->name = (char *) malloc(sizeof(char) * (strlen("Dog") + 1));
	if (blogList->name == NULL)
		return NULL;
	strcpy(blogList->name, "Dog");

	//add_new content
	blogList->content = (char *) malloc(sizeof(char) * (strlen("Good dog") + 1));
	if (blogList->content == NULL)
		return NULL;
	strcpy(blogList->content, "Good dog");

	//add_tags
	blogList->tags = NULL;
	blogList->tags = add_new_tag(blogList->tags, "@dog");
	if (blogList->tags == NULL)
		return NULL;
	blogList->tags = add_new_tag(blogList->tags, "@dogs");
	if (blogList->tags == NULL)
		return NULL;
	blogList->tags = add_new_tag(blogList->tags, "@dogssss");
	if (blogList->tags == NULL)
		return NULL;

	//add_likes
	blogList->likes = NULL;
	blogList->likes = add_new_like(blogList->likes, 10, 6, 2021); //in 30
	if (blogList->likes == NULL)
		return NULL;
	blogList->likes = add_new_like(blogList->likes, 11, 6, 2021); //in 30
	if (blogList->likes == NULL)
		return NULL;
	blogList->likes = add_new_like(blogList->likes, 11, 6, 2021); //in 30
	if (blogList->likes == NULL)
		return NULL;
	blogList->likes = add_new_like(blogList->likes, 11, 7, 2021); //no in 30
	if (blogList->likes == NULL)
		return NULL;
	blogList->likes = add_new_like(blogList->likes, 11, 7, 2021); //no in 30
	if (blogList->likes == NULL)
		return NULL;

	//add_new comments
	blogList->comments = NULL;
	blogList->comments = add_new_comment(blogList->comments, "I like dogs", 10, 6, 2021); //in 30
	if (blogList->comments == NULL)
		return NULL;
	blogList->comments = add_new_comment(blogList->comments, "I like dogs", 15, 6, 2021); //in 30
	if (blogList->comments == NULL)
		return NULL;
	blogList->comments = add_new_comment(blogList->comments, "I like dogs", 15, 6, 2021); //in 30
	if (blogList->comments == NULL)
		return NULL;
	blogList->comments = add_new_comment(blogList->comments, "I like dogs", 15, 6, 2021); //in 30
	if (blogList->comments == NULL)
		return NULL;
	blogList->comments = add_new_comment(blogList->comments, "I like dogs", 15, 6, 2021); //in 30
	if (blogList->comments == NULL)
		return NULL;

	//add_new date
	blogList->date_publication = date;
	blogList->month_publication = month;
	blogList->year_publication = year;


	blogList->next = head;


	return (blogList);
}

blog_list *add_new_blog3(blog_list *head, int date, int month, int year)
{
	//add_new blog frog 15, 6, 2021
	blog_list *blogList = NULL;
	blogList = malloc(sizeof(blog_list));
	if (blogList == NULL)
		return NULL;

	//add_new name
	blogList->name = (char *) malloc(sizeof(char) * (strlen("Frog") + 1));
	if (blogList->name == NULL)
		return NULL;
	strcpy(blogList->name, "Frog");

	//add_new content
	blogList->content = (char *) malloc(sizeof(char) * (strlen("Good frog") + 1));
	if (blogList->content == NULL)
		return NULL;
	strcpy(blogList->content, "Good frog");

	//add_tags
	blogList->tags = NULL;
	blogList->tags = add_new_tag(blogList->tags, "@frog");
	if (blogList->tags == NULL)
		return NULL;
	blogList->tags = add_new_tag(blogList->tags, "@frogs");
	if (blogList->tags == NULL)
		return NULL;
	blogList->tags = add_new_tag(blogList->tags, "@frogssss");
	if (blogList->tags == NULL)
		return NULL;

	//add_likes
	blogList->likes = NULL;
	blogList->likes = add_new_like(blogList->likes, 15, 6, 2021); //in 30
	if (blogList->likes == NULL)
		return NULL;
	blogList->likes = add_new_like(blogList->likes, 25, 6, 2021); //in 30
	if (blogList->likes == NULL)
		return NULL;
	blogList->likes = add_new_like(blogList->likes, 30, 6, 2021); //in 30
	if (blogList->likes == NULL)
		return NULL;
	blogList->likes = add_new_like(blogList->likes, 15, 6, 2021); //in 30
	if (blogList->likes == NULL)
		return NULL;
	blogList->likes = add_new_like(blogList->likes, 11, 7, 2021); //in 30
	if (blogList->likes == NULL)
		return NULL;

	//add_new comments
	blogList->comments = NULL;
	blogList->comments = add_new_comment(blogList->comments, "I like frog", 11, 6, 2021); //no in 30
	if (blogList->comments == NULL)
		return NULL;
	blogList->comments = add_new_comment(blogList->comments, "I like frog", 16, 6, 2021); //in 30
	if (blogList->comments == NULL)
		return NULL;
	blogList->comments = add_new_comment(blogList->comments, "I like frog", 11, 6, 2021); //no in 30
	if (blogList->comments == NULL)
		return NULL;
	blogList->comments = add_new_comment(blogList->comments, "I like frog", 11, 7, 2021); //in 30
	if (blogList->comments == NULL)
		return NULL;

	//add_new date
	blogList->date_publication = date;
	blogList->month_publication = month;
	blogList->year_publication = year;

	blogList->next = head;

	return (blogList);
}

tag *add_new_tag(tag *head, char *content)
{
	tag *new_tag = malloc(sizeof(tag));
	if (new_tag == NULL)
		return NULL;
	new_tag->content = malloc(sizeof(char) * strlen(content));
	if (new_tag->content == NULL)
		return NULL;
	strcpy(new_tag->content, content);

	new_tag->next = head;

	return new_tag;
}

like *add_new_like(like *head, int date, int month, int year)
{
	like *new_like = malloc(sizeof(like));
	if (new_like == NULL)
		return NULL;
	new_like->date_like = date;
	new_like->month_like = month;
	new_like->year_like = year;

	new_like->next = head;

	return new_like;
}

comment *add_new_comment(comment *head, char *content, int date, int month, int year)
{
	comment *new_comment = malloc(sizeof(comment));
	if (new_comment == NULL)
		return NULL;
	new_comment->content = malloc(sizeof(char) * strlen(content));
	if (new_comment->content == NULL)
		return NULL;
	strcpy(new_comment->content, content);
	new_comment->date_comment = date;
	new_comment->month_comment = month;
	new_comment->year_comment = year;

	new_comment->next = head;

	return new_comment;
}
