/**
 * @file test.cpp
 * @author Purbayan Chowdhury (pur.cho.99@gmail.com)
 * @brief Unit Test for singly linked list
 * @version 0.1
 * @date 2022-01-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <gtest/gtest.h>
#include "../src/linked_list.hpp"

class LinkedListTest : public ::testing::Test
{
protected:
    std::vector<int> vec1 = {};
    std::vector<int> vec2 = {1, 2, 3, 4, 5};
    std::vector<int> vec3 = {4, 5, 6, 9};

    ListNodePtr head1 = ListNodeUtil::createFromList(vec1);
    ListNodePtr head2 = ListNodeUtil::createFromList(vec2);
    ListNodePtr head3 = ListNodeUtil::createFromList(std::vector<int>({1, 2, 3, 3, 4, 4, 5}));

    void SetUp() override
    {
    }

    void TearDown() override
    {
    }

public:
    static bool matchLinkedList(ListNodePtr head, std::initializer_list<int> lst);
    static bool matchLinkedList(ListNodePtr head, std::vector<int> vec);
};

/**
 * @brief Checks if vector and linked list has same elements both in frequency and sequence
 * 
 * @param  head  : ListNodePtr      => Pointer of linked list header
 * @param  vec   : std::vector<int> => Vector of data elements
 * 
 * @return check : bool             => Returns true if vector and linked list are same else false.  
 */
bool LinkedListTest::matchLinkedList(ListNodePtr head, std::vector<int> vec)
{
    ListNodePtr curr = head;
    for (int ele : vec)
    {
        if (curr == nullptr)
            return false;
        if (curr->val != ele)
            return false;
        curr = curr->next;
    }
    return true;
}

bool LinkedListTest::matchLinkedList(ListNodePtr head, std::initializer_list<int> lst)
{
    ListNodePtr curr = head;
    for (int ele : lst)
    {
        if (curr == nullptr)
            return false;
        if (curr->val != ele)
            return false;
        curr = curr->next;
    }
    return true;
}

TEST_F(LinkedListTest, CreateListFromVector)
{
    EXPECT_TRUE(LinkedListTest::matchLinkedList(ListNodeUtil::createFromList(vec1), vec1));
    EXPECT_TRUE(LinkedListTest::matchLinkedList(ListNodeUtil::createFromList(vec2), vec2));
    EXPECT_TRUE(LinkedListTest::matchLinkedList(ListNodeUtil::createFromList(vec3), vec3));
}
TEST_F(LinkedListTest, CreateListFromArray)
{
    EXPECT_TRUE(LinkedListTest::matchLinkedList(
        ListNodeUtil::createFromArray({}),
        {}));
    EXPECT_TRUE(LinkedListTest::matchLinkedList(
        ListNodeUtil::createFromArray({1, 2, 3, 4, 5}),
        {1, 2, 3, 4, 5}));
    EXPECT_TRUE(LinkedListTest::matchLinkedList(
        ListNodeUtil::createFromArray({4, 5, 6, 9}),
        {4, 5, 6, 9}));
}

TEST_F(LinkedListTest, ReverseList)
{
    EXPECT_TRUE(LinkedListTest::matchLinkedList(
        ListNodeUtil::reverseList(nullptr),
        {}));
    EXPECT_TRUE(LinkedListTest::matchLinkedList(
        ListNodeUtil::reverseList(ListNodeUtil::createFromArray({1, 2, 3, 4, 5})),
        {5, 4, 3, 2, 1}));
    EXPECT_TRUE(LinkedListTest::matchLinkedList(
        ListNodeUtil::reverseList(ListNodeUtil::createFromArray({1, 2})),
        {2, 1}));
}

TEST_F(LinkedListTest, RemoveNthFromEnd)
{
}

TEST_F(LinkedListTest, RemoveDuplicates)
{
    EXPECT_TRUE(LinkedListTest::matchLinkedList(
        ListNodeUtil::removeDuplicates(ListNodeUtil::createFromArray({1, 1, 2})),
        {1, 2}));
    EXPECT_TRUE(LinkedListTest::matchLinkedList(
        ListNodeUtil::removeDuplicates(ListNodeUtil::createFromArray({1, 1, 2, 3, 3})),
        {1, 2, 3}));
}

TEST_F(LinkedListTest, DeleteDuplicates)
{
    // EXPECT_TRUE(LinkedListTest::matchLinkedList(

    // ));
}

TEST_F(LinkedListTest, MiddleNode)
{
    EXPECT_TRUE(LinkedListTest::matchLinkedList(
        ListNodeUtil::middleNode(ListNodeUtil::createFromArray({1, 2, 3, 4, 5})),
        {3, 4, 5}));
    EXPECT_TRUE(LinkedListTest::matchLinkedList(
        ListNodeUtil::middleNode(ListNodeUtil::createFromArray({1, 2, 3, 4, 5, 6})),
        {4, 5, 6}));
}

TEST_F(LinkedListTest, HasCycle)
{
    ListNodePtr cycleHead1 = ListNodeUtil::createFromArray({3, 2, 0, -4});
    cycleHead1->next->next->next->next = cycleHead1->next;
    EXPECT_TRUE(ListNodeUtil::hasCycle(cycleHead1));

    EXPECT_FALSE(ListNodeUtil::hasCycle(ListNodeUtil::createFromArray({1, 7, 6, 2})));

    ListNodePtr cycleHead2 = ListNodeUtil::createFromArray({2, 9, 0});
    cycleHead2->next->next->next = cycleHead2;
    EXPECT_TRUE(ListNodeUtil::hasCycle(cycleHead2));
}

TEST_F(LinkedListTest, GetIntersectionNode)
{
    ListNodePtr mergedList1_1 = ListNodeUtil::createFromArray({4, 1, 8, 4, 5});
    ListNodePtr mergedList2_1 = ListNodeUtil::createFromArray({5, 6, 1});
    mergedList2_1->next->next->next = mergedList1_1->next->next;
    EXPECT_EQ(ListNodeUtil::getIntersectionNode(mergedList1_1, mergedList2_1)->val, 8);

    ListNodePtr mergedList1_2 = ListNodeUtil::createFromArray({3, 2, 4});
    ListNodePtr mergedList2_2 = ListNodeUtil::createFromArray({1, 9, 1});
    mergedList2_2->next->next->next = mergedList1_2->next;
    EXPECT_EQ(ListNodeUtil::getIntersectionNode(mergedList1_2, mergedList2_2)->val, 2);

    EXPECT_EQ(
        ListNodeUtil::getIntersectionNode(
            ListNodeUtil::createFromArray({2, 6, 4}),
            ListNodeUtil::createFromArray({1, 5})),
        nullptr);
}