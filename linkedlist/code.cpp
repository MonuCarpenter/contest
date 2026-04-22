// /*
//  * Author: Monu Carpenter
//  * Handle: m_o_n_u
//  * Time: 11:59 AM IST
//  * Problem: <problem-name>
//  */

// #include <bits/stdc++.h>

// using i64 = long long;
// using u64 = unsigned long long;
// using u32 = unsigned;

// #ifndef ONLINE_JUDGE
// #include "../cpp-dump/cpp-dump.hpp"
// #define log(...) cpp_dump(__VA_ARGS__)
// template <>
// inline void cpp_dump::write_log(std::string_view output) {
//     std::cout << output << '\n';
// }
// #else
// #define log(...)
// #define CPP_DUMP_SET_OPTION(...)
// #define CPP_DUMP_DEFINE_EXPORT_OBJECT(...)
// #define CPP_DUMP_DEFINE_EXPORT_OBJECT_GENERIC(...)
// #define CPP_DUMP_DEFINE_EXPORT_ENUM(...)
// #define CPP_DUMP_DEFINE_EXPORT_ENUM_GENERIC(...)
// #endif


// class Node {
//     public: 
//         int data; 
//         Node* next;

//         Node(int d, Node* n) {
//             data = d;
//             next = n; 
//         }

//         // Node(int d) {
//         //     data = d; 
//         //     next = nullptr; 
//         // }
// }; 



// int main() {
//     CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);

//     // creating an array; 
//     std::vector<int> arr = { 2,5,6,7,8}; 

//     //create first node
//     Node* y = new Node(arr[0], nullptr);

//     //print memory allocation of that node; 
//     std::cout <<"Memory allotion/address of the node" <<  y << std::endl; 

//     //printing the data stored in the y node; 
//     std::cout <<"Printing the data stored in the node: " << y->data << std::endl;

//     //printing the addd of next pointer. 

//     std::cout << "Address of the next node: " << y->next << std::endl; 

//     return 0;
// }


#include <bits/stdc++.h> 


class Node {
    public: 
        int data; 
        Node* next; 

        Node(int d, Node* n) {
            data = d; 
            next = n; 
        }

        Node(int d) {
            data = d; 
            next = nullptr; 
        }
}; 


int main() {
    std::vector<int> arr = {2,5,7,9,0}; 

    Node* _node = new Node(arr[0]); 

    std::cout << "Printing the allocation of the node i mean addresss" << _node << std::endl; 
    std::cout << "Printing the data of the node" << _node->data << std::endl; 
    std::cout << "Printing the address of the next node" << _node->next << std::endl; 
}
