#include <stdio.h>
#include <map>
int main() {
	std::map<int,int> test;
	printf("%d\n",(sizeof(int) + sizeof(int) + sizeof(_Rb_tree_node_base)) * 100 + sizeof(_Rb_tree));
}