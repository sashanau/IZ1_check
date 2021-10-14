#include <gtest/gtest.h>

extern "C"
{
#include "find_top.h"
}

TEST(FIND_TEST, Assert_1 ) //тест на 3 блога
{
	blog_list	*blogList = NULL;
	blog_list	*temp = NULL;
	//add_new blog1
	blogList = add_new_blog1(blogList, 10, 4, 2021); // 7
	if (blogList == NULL)
		return;
	//add_new blog2
	blogList = add_new_blog2(blogList, 20, 5, 2021); // 8
	if (blogList == NULL)
		return;
	temp = blogList; // записываю ответ в temp
	//add_new blog3
	blogList = add_new_blog3(blogList, 15, 6, 2021); // 4
	if (blogList == NULL)
		return;

	blog_list *current = blogList;

	current = find_top(current); //Поиск топ записи

	ASSERT_EQ (compare_struct(current, temp), 1); // compare_struct - функция сравнения 2-х структур
	free_all_blog(blogList);
}

TEST(FIND_TEST, Assert_2 ) //тест на 1 блог
{
	blog_list	*blogList = NULL;
	blogList = add_new_blog1(blogList, 10, 4, 2021); // 7
	if (blogList == NULL)
		return;
	blog_list	*temp = blogList;
	blog_list *current = blogList;

	current = find_top(current);
	ASSERT_EQ (compare_struct(current, temp), 1 );
	free_all_blog(blogList);
}

TEST(FIND_TEST, Assert_3) //тест на пустой поиск
{
	blog_list	*blogList = NULL;
	blog_list *current = blogList;

	current = find_top(current);
	ASSERT_EQ ((current == NULL), 1 );
}

TEST(SET_TIME_TEST, Assert_1) //тест приобразования даты
{
	int time = set_time(5, 5, 2021);
	ASSERT_EQ (time, 737825);
}

TEST(SET_TIME_TEST, Assert_2) //тест приобразования даты
{
	int time = set_time(0, 0, 0);
	ASSERT_EQ (time, 0);
}

TEST(SET_TIME_TEST, Assert_3) //тест приобразования даты
{
	int time = set_time(32, 0, 0);
	ASSERT_EQ (time, 0 );
}

TEST(SET_TIME_TEST, Assert_4) //тест приобразования даты
{
	int time = set_time(0, 13, 0);
	ASSERT_EQ (time, 0 );
}

TEST(SET_TIME_TEST, Assert_5) //тест приобразования даты
{
	int time = set_time(0, 0, -1);
	ASSERT_EQ (time, 0 );
}

TEST(ADD_NEW_STRUCT, Assert_1) //тест на заполнение структуры //add_new_blog2 и add_new_blog3 аналогичны
{
	blog_list	*blogList = NULL;
	blogList = add_new_blog1(blogList, 10, 4, 2021); // 7
	if (blogList == NULL)
		return;

	ASSERT_STREQ(blogList->name, "Cat");
	ASSERT_STREQ(blogList->content, "Good cat");
	ASSERT_STREQ(blogList->tags->content, "@catssss");
	ASSERT_STREQ(blogList->tags->next->content, "@cats");
	ASSERT_STREQ(blogList->tags->next->next->content, "@cat");

	ASSERT_EQ(blogList->likes->date_like, 28);
	ASSERT_EQ(blogList->likes->month_like, 5);
	ASSERT_EQ(blogList->likes->year_like, 2021);
	ASSERT_EQ(blogList->likes->next->date_like, 21);
	ASSERT_EQ(blogList->likes->next->month_like, 5);
	ASSERT_EQ(blogList->likes->next->year_like, 2021);
	ASSERT_EQ(blogList->likes->next->next->date_like, 5);
	ASSERT_EQ(blogList->likes->next->next->month_like, 5);
	ASSERT_EQ(blogList->likes->next->next->year_like, 2021);

	ASSERT_STREQ(blogList->comments->content, "I like cats");
	ASSERT_STREQ(blogList->comments->next->content, "I like cats");
	ASSERT_STREQ(blogList->comments->next->next->content, "I like cats");

	ASSERT_EQ(blogList->comments->date_comment, 30);
	ASSERT_EQ(blogList->comments->month_comment, 4);
	ASSERT_EQ(blogList->comments->year_comment, 2021);
	ASSERT_EQ(blogList->comments->next->date_comment, 20);
	ASSERT_EQ(blogList->comments->next->month_comment, 4);
	ASSERT_EQ(blogList->comments->next->year_comment, 2021);
	ASSERT_EQ(blogList->comments->next->next->date_comment, 10);
	ASSERT_EQ(blogList->comments->next->next->month_comment, 4);
	ASSERT_EQ(blogList->comments->next->next->year_comment, 2021);

	ASSERT_EQ(blogList->date_publication, 10);
	ASSERT_EQ(blogList->month_publication, 4);
	ASSERT_EQ(blogList->year_publication, 2021);


	free_all_blog(blogList);
}

TEST(ADD_NEW_STRUCT_TAGS, Assert_1) //тест на заполнение структуры
{
	tag *a = NULL;
	a = add_new_tag(a, "HI");
	if (a == NULL)
		return;
	a = add_new_tag(a, "HI2");
		if(a == NULL)
			return;
	ASSERT_STREQ(a->content, "HI2");
	ASSERT_STREQ(a->next->content, "HI");
	free(a->content);
	free(a->next->content);
	free(a->next);
	free(a);
}

TEST(ADD_NEW_STRUCT_TAGS, Assert_2) //тест на заполнение структуры
{
	tag *a = NULL;
	a = add_new_tag(a, "");
	if(a == NULL)
		return;
	a = add_new_tag(a, "HI2");
	if(a == NULL)
		return;

	ASSERT_STREQ(a->content, "HI2");
	ASSERT_STREQ(a->next->content, "");
	free(a->content);
	free(a->next->content);
	free(a->next);
	free(a);
}



int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


