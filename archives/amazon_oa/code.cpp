/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 09:47 AM IST
 * Problem: <problem-name>
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

#ifndef ONLINE_JUDGE
#include "../cpp-dump/cpp-dump.hpp"
#define log(...) cpp_dump(__VA_ARGS__)
template <>
inline void cpp_dump::write_log(std::string_view output) {
    std::cout << output << '\n';
}
#else
#define log(...)
#define CPP_DUMP_SET_OPTION(...)
#define CPP_DUMP_DEFINE_EXPORT_OBJECT(...)
#define CPP_DUMP_DEFINE_EXPORT_OBJECT_GENERIC(...)
#define CPP_DUMP_DEFINE_EXPORT_ENUM(...)
#define CPP_DUMP_DEFINE_EXPORT_ENUM_GENERIC(...)
#endif


// linkedlist problem; 
// int countPairs(ListNode* head) {
//     //fist we will make two pointers one is slow and other one is fast; 
//     // after that we will have slow at mid and fast at the end; 
//     // we will either reverse the last one or store in a stack; 
//     // then we will simply add values of first half and the stack values; 
//     ListNode* slow = head;
//     ListNode* fast = head;

//     while(fast != nullptr && fast->next != nullptr) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     stack<int> st;
//     while(slow != nullptr) {
//         st.push(slow->val);
//         slow = slow->next;
//     }
//     int count = 0;
//     while(!st.empty()) {
//         int result = head->val + st.top();
//         st.pop();
//         head = head->next;
//     }
//     return count;
// }


int main() {
    CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    return 0;
}
