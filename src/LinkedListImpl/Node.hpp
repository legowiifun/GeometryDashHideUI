#include <string>
/**
 * A Linked List implementation
 * It is easier to resize then arrays are
 */
class LinkedListNode {
    private:
        /**
         * A reference to the next node in the list
        */ 
        LinkedListNode* next;
        /**
         * A reference to the data inside the node
         */
        std::string data;
        /**
         * If the node is nested
         * 0 for not nested
         * 1 for nested
         * -1 for sibling/nested in sibling
         */
        int isNested;
    public:
        /**
         * Get the next node in the list
        */ 
        LinkedListNode* getNext();
        /**
         * Create a new linked list node
        */
        LinkedListNode(std::string toStore, int nest);
        /**
         * Add a node to the end of the list
        */ 
        void addToEnd(LinkedListNode* node);
        /**
         * Get a node by its index
        */ 
        LinkedListNode* get(int i);
        /**
         * Get the data inside the node
         */
        std::string getData();
        /**
         * Check if the data exists inside the entire list
         * Return true if the data exists, false if it does not
         */
        boolean strExists(std::string info);
        /**
         * Get the nested status
         */
        int getIsNested();
};