/**
 * @file linked_list.cpp
 * @author Purbayan Chowdhury (pur.cho.99@gmail.com)
 * @brief Singly linked list 
 * @version 0.1
 * @date 2022-01-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "linked_list.hpp"

/*
 * List Node Functions
 */

/**
 * @brief Prints the linked list
 * 
 */
void ListNode::displayList()
{
    ListNodePtr curr = this;
    while (curr != nullptr)
    {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

/*
 * List Util Functions
 */

/**
 * @brief Create a linked list from a vector
 * 
 * @param  vec   : std::vector<int> => Vector of data elements
 * 
 * @return head : ListNodePtr       => Pointer of linked list header
 */
ListNodePtr ListNodeUtil::createFromList(std::vector<int> vec)
{
    ListNodePtr head = new ListNode();
    ListNodePtr curr = head;
    for (int i = 0; i < vec.size(); i++)
    {
        curr->val = vec[i];
        if (i == vec.size() - 1)
            curr->next = nullptr;
        else
        {
            curr->next = new ListNode();
            curr = curr->next;
        }
    }
    return head;
}

ListNodePtr ListNodeUtil::createFromArray(std::initializer_list<int> arr)
{
    ListNodePtr head = new ListNode();
    ListNodePtr curr = head;
    for (int i : arr)
    {
        curr->next = new ListNode(i);
        curr = curr->next;
    }
    return head->next;
}

/**
 * @brief Removes Nth node from the linked list
 * 
 * @param  head : ListNodePtr => Pointer of linked list header
 * @param  n    : int         => Position of element in the linked list
 * 
 * @return head : ListNodePtr => Pointer of linked list header
 */
ListNodePtr ListNodeUtil::removeNthFromEnd(ListNodePtr head, int n)
{
    int count = 0;
    ListNodePtr cur = head;
    while (cur)
    {
        count++;
        cur = cur->next;
    }
    if (count == n)
        return head->next;
    cur = head;
    for (int i = 0; i < count - n - 1; i++)
        cur = cur->next;
    cur->next = cur->next->next;
    return head;
}

/**
 * @brief 
 * 
 * @param  head : ListNodePtr => Pointer of linked list header
 * 
 * @return head : ListNodePtr => Pointer of linked list header
 */
ListNodePtr ListNodeUtil::swapPairs(ListNodePtr head)
{
    ListNodePtr curr = head;
    ListNodePtr prev = nullptr;
    while (curr != nullptr && curr->next != nullptr)
    {
        ListNodePtr next = curr->next;
        curr->next = next->next;
        next->next = curr;
        if (prev == nullptr)
        {
            head = next;
        }
        else
        {
            prev->next = next;
        }
        prev = curr;
        curr = curr->next;
    }

    return head;
}

ListNodePtr ListNodeUtil::rotateRight(ListNodePtr head, int k)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNodePtr p = head;
    int len = 1;
    while (p->next != nullptr)
    {
        p = p->next;
        len++;
    }
    p->next = head;
    k = k % len;
    for (int i = 0; i < len - k; i++)
        p = p->next;
    head = p->next;
    p->next = nullptr;
    return head;
}

ListNodePtr ListNodeUtil::reverseList(ListNodePtr head)
{
    ListNodePtr curr = head, prev = NULL, next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

ListNodePtr ListNodeUtil::removeDuplicates(ListNodePtr head)
{
    if (head == nullptr)
        return head;
    ListNodePtr p = head;
    while (p->next != nullptr)
    {
        if (p->val == p->next->val)
        {
            ListNodePtr q = p->next;
            p->next = q->next;
            delete q;
        }
        else
            p = p->next;
    }
    return head;
}

ListNodePtr ListNodeUtil::deleteDuplicates(ListNodePtr head)
{
    if (head == nullptr)
        return head;
    ListNodePtr p = head, prev = nullptr;
    int flag = 0;
    while (p->next != nullptr)
    {
        if (p->val == p->next->val)
        {
            ListNodePtr q = p->next;
            p->next = q->next;
            delete q;
            flag = 1;
        }
        else
        {
            if (flag)
            {
                if (prev == nullptr)
                {
                    head = p->next;
                    delete p;
                    p = head;
                    prev = nullptr;
                }
                else
                    prev->next = p->next;
            }
            else
            {
                prev = p;
                p = p->next;
            }
            flag = 0;
        }
    }
    return head;
}

ListNodePtr ListNodeUtil::middleNode(ListNodePtr head)
{
    ListNodePtr slow = head, fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool ListNodeUtil::hasCycle(ListNodePtr head)
{
    ListNodePtr fast = head, slow = head;
    while (fast != nullptr && fast->next != nullptr && slow != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

ListNodePtr ListNodeUtil::getIntersectionNode(ListNodePtr headA, ListNodePtr headB)
{
    ListNodePtr temp1 = headA, temp2 = headB;
    while (temp1 != nullptr)
    {
        temp1->val = temp1->val * -1;
        temp1 = temp1->next;
    }
    while (temp2 != nullptr)
    {
        if (temp2->val < 0)
            break;
        temp2 = temp2->next;
    }
    temp1 = headA;
    while (temp1 != nullptr)
    {
        temp1->val = temp1->val * -1;
        temp1 = temp1->next;
    }
    return temp2;
}