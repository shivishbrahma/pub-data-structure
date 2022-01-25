/**
 * @file linked_list.hpp
 * @author Purbayan Chowdhury (pur.cho.99@gmail.com)
 * @brief Declaration of singly linked list functions and constructors 
 * @version 0.1
 * @date 2022-01-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <vector>
#include <initializer_list>
#include <iostream>

/**
 * @brief Definition for singly linked list node
 * 
 */
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void displayList();
};

typedef ListNode *ListNodePtr;

/**
 * @brief Definition for singly linked list utilities
 * 
 */
class ListNodeUtil
{
public:
    static ListNodePtr createFromList(std::vector<int> vec);
    static ListNodePtr createFromArray(std::initializer_list<int> arr);
    static ListNodePtr removeNthFromEnd(ListNodePtr head, int n);
    static ListNodePtr swapPairs(ListNodePtr head);
    static ListNodePtr rotateRight(ListNodePtr head, int k);
    static ListNodePtr reverseList(ListNodePtr head);
    static ListNodePtr removeDuplicates(ListNodePtr head);
    static ListNodePtr deleteDuplicates(ListNodePtr head);
    static ListNodePtr middleNode(ListNodePtr head);
    static bool hasCycle(ListNodePtr head);
    static ListNodePtr getIntersectionNode(ListNodePtr headA, ListNodePtr headB);
};

#endif