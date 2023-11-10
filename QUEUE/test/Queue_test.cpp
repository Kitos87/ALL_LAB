#include <gtest.h>
#include <MyQueue.h>

TEST(TQueue, ConstructorWithNegativeSize) {
	ASSERT_ANY_THROW(TQueue<int> queue(-1));
}

TEST(TQueue, DefaultConstructor) {
	TQueue<int> queue;
	EXPECT_EQ(queue.GetSize(), 1);
	EXPECT_TRUE(queue.IsEmpty());
}

TEST(TQueue, CopyConstructor) {
	TQueue<int> queue1(2);
	queue1.Push(1);
	queue1.Push(2);
	TQueue<int> queue2(queue1);

	// Проверка, что элементы скопировались правильно
	EXPECT_EQ(queue2.Get(), 1);
	EXPECT_EQ(queue2.Get(), 2);
}

TEST(TQueue, PushElement) {
	TQueue<int> queue;
	ASSERT_NO_THROW(queue.Push(1));
	EXPECT_FALSE(queue.IsEmpty());
}

TEST(TQueue, GetElement) {
	TQueue<int> queue;
	queue.Push(1);
	int res;
	ASSERT_NO_THROW(res = queue.Get());
	EXPECT_EQ(res, 1);
}

TEST(TQueue, GetEmptyQueue) {
	TQueue<int> queue;
	ASSERT_ANY_THROW(queue.Get());
}

TEST(TQueue, PushFullQueue) {
	TQueue<int> queue(1);
	queue.Push(1);
	ASSERT_ANY_THROW(queue.Push(2));
}

TEST(TQueue, CheckIsFull) {
	TQueue<int> queue(1);
	EXPECT_FALSE(queue.IsFull());
	queue.Push(1);
	EXPECT_TRUE(queue.IsFull());
}

TEST(TQueue, CheckIsEmpty) {
	TQueue<int> queue(1);
	EXPECT_TRUE(queue.IsEmpty());
	queue.Push(1);
	EXPECT_FALSE(queue.IsEmpty());
	queue.Get();
	EXPECT_TRUE(queue.IsEmpty());
}

TEST(TQueue, AssignmentOperator) {
	TQueue<int> queue1(2);
	queue1.Push(1);
	queue1.Push(2);
	TQueue<int> queue2;
	queue2 = queue1;
	EXPECT_EQ(queue2.Get(), 1);
	EXPECT_EQ(queue2.Get(), 2);
}
