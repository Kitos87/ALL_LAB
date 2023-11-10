#include "MyStack.h"
#include <gtest.h>

TEST(TStack, constructor_with_negative_size) {
    ASSERT_ANY_THROW(TStack<int> stack(-1));
}

TEST(TStack, default_constructor) {
    TStack<int> stack;
    EXPECT_EQ(stack.GetSize(), 1);
    EXPECT_TRUE(stack.IsEmpty());
}

TEST(TStack, copy_constructor) {
    TStack<int> stack1(2);
    stack1.Push(1);
    stack1.Push(2);
    TStack<int> stack2(stack1);
    EXPECT_EQ(stack2.Pop(), 2); // Изменено с Get() на Pop()
    EXPECT_EQ(stack2.Pop(), 1); // Изменено с Get() на Pop()
}

TEST(TStack, push_element) {
    TStack<int> stack;
    ASSERT_NO_THROW(stack.Push(1));
    EXPECT_EQ(stack.Top(), 1); // Изменено с TopView() на Top()
}

TEST(TStack, pop_element) { // Изменено название теста с get_element
    TStack<int> stack;
    stack.Push(1);
    int res;
    ASSERT_NO_THROW(res = stack.Pop()); // Изменено с Get() на Pop()
    EXPECT_EQ(res, 1);
}

TEST(TStack, pop_empty_stack) { // Изменено название теста с get_empty_stack
    TStack<int> stack;
    ASSERT_ANY_THROW(stack.Pop()); // Изменено с Get() на Pop()
}

TEST(TStack, top_empty_stack) { // Изменено название теста с top_view_empty_stack
    TStack<int> stack;
    ASSERT_ANY_THROW(stack.Top()); // Изменено с TopView() на Top()
}

TEST(TStack, push_full_stack) {
    TStack<int> stack(1);
    stack.Push(1);
    ASSERT_ANY_THROW(stack.Push(2));
}

TEST(TStack, top_element) { // Изменено название теста с top_view_element
    TStack<int> stack;
    stack.Push(25);
    EXPECT_EQ(stack.Top(), 25); // Изменено с TopView() на Top()
}

TEST(TStack, check_is_full) {
    TStack<int> stack(2);
    stack.Push(1);
    EXPECT_FALSE(stack.IsFull());
    stack.Push(2);
    EXPECT_TRUE(stack.IsFull());
}

TEST(TStack, check_is_empty) {
    TStack<int> stack(2);
    EXPECT_TRUE(stack.IsEmpty());
    stack.Push(1);
    EXPECT_FALSE(stack.IsEmpty());
    stack.Pop(); // Изменено с Get() на Pop()
    EXPECT_TRUE(stack.IsEmpty());
}
TEST(TStack, operator_assign) {
    TStack<int> stack1(2);
    stack1.Push(1);
    stack1.Push(2);
    TStack<int> stack2;
    ASSERT_NO_THROW(stack2 = stack1);
    EXPECT_EQ(stack2.Pop(), 2); // Изменено с Get() на Pop()
    EXPECT_EQ(stack2.Pop(), 1); // Изменено с Get() на Pop()
}
