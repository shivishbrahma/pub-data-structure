/**
 * @file main.cpp
 * @author Purbayan Chowdhury (pur.cho.99@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <ctime>
#include "linked_list.hpp"

int main(int argc, char const *argv[])
{
    ListNodePtr head = new ListNode();
    std::vector<int> vec = {1, 2, 3, 3, 4, 4, 5};
    head = ListNodeUtil::createFromList(vec);
    head->displayList();
    const clock_t begin_time = clock();
    head = ListNodeUtil::deleteDuplicates(head);
    float time_taken = float(clock() - begin_time) / CLOCKS_PER_SEC;
    head->displayList();
    std::cout << "Time spent: " << time_taken << " s." << std::endl;
    return 0;
}