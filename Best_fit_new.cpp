//
// Created by atmadeep on 8/11/17.
//
#include <iostream>
#include <tuple>
#include <list>
using namespace std;
const int MAX_MEM_HOLE=10;
const int MAX_PROCESS=8; //MAX_PROCESS is always smaller than MAX_MEM_HOLE
int main(){
 list <pair<int,short>> Memory_holes_list;
    list <pair<int,short>> Process_list;
    //initializing
    printf("\nPlease enter memory holes\n");
    for (int i=0;i<MAX_MEM_HOLE;i++) {
        pair<int,short> pair1;
//        cout<<"please provide mem_size for block %d"<<i+1<<"\n";
        cin>>pair1.first;
        pair1.second=(short)i;
        Memory_holes_list.push_front(pair1);
    }
    printf("\nPlease enter processes\n");
    for (int i = 0; i <MAX_PROCESS ; ++i) {
        pair<int,short> pair1;
        pair1.second=(short)i;
//        cout<<"please provide process_id and process_size for block %d\n"<<i+1;
        cin>>pair1.first;
        Process_list.push_front(pair1);
    }
    Memory_holes_list.sort();
    Process_list.sort();
    printf("Process id -- process size   Memory id -- memory size\n process = ");
    for (auto &&item : Process_list) {
        cout<<item.first<<"@"<<item.second<<" ";
    }printf("\n memory = ");
    for (auto &&item : Memory_holes_list) {
        cout<<item.first<<"#"<<item.second<<" ";
    }


}
