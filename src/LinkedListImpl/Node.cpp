#include "Node.hpp"

LinkedListNode* LinkedListNode::getNext() {
    return next;
}
LinkedListNode::LinkedListNode(std::string toStore, int nest) {
    data=toStore;
    next=nullptr;
    isNested = nest;
}
void LinkedListNode::addToEnd(LinkedListNode* node) {
    // if this is the last element, add it
    // otherwise, use recursion on the next element
    if (next==nullptr) {
        next=node;
    } else {
        next->addToEnd(node);
    }
}
LinkedListNode* LinkedListNode::get(int i) {
    // if this is the node, return
    if (i==0) {
        return this;
    }
    // if there is no next node, return nullptr
    if (next==nullptr) {
        return nullptr;
    }
    // otherwise, check with next, and decrement i
    // cut the first element off the list, and check with a slightly smaller list
    return next->get(i-1);
}
std::string LinkedListNode::getData() {
    return data;
}
bool LinkedListNode::strExists(std::string info) {
    // if it is in this node, return true
    if (data==info) {
        return true;
    } else if (next==nullptr) {
        return false;
    } else {
        return next->strExists(info);
    }
}
int LinkedListNode::getIsNested() {
    return isNested;
}