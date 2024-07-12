#ifndef IBPTREE_NODE_HPP
#define IBPTREE_NODE_HPP

// Standard
#include <iostream>
#include <vector>
#include <memory>

// Class
#include "Key.hpp"

// Forward declaration
class Key;

class Node {
    public:
        Node(int k); // create a new Node with a given order k
        ~Node(); // destructor

        // getter & setter
        int getOrder();
        void setOrder(int k);
        std::vector<Key>& getKeys();
        void setKeys(std::vector<Key> keys);
        std::vector<Node*> getChildren();
        void setChildren(std::vector<Node*> children);
        void setNext(Node* next);
        Node* getNext();
        void setIsLeaf(bool leaf);
        bool getIsLeaf();

        /*
         * @brief inserts a new key to the Node
         * @param key the key (Interval, Node) to add
         * @param index the index at which to add the key
         */
        void insertKey(Key& key);
//        /*
//         * @brief assign a range of keys to the Node
//         * @param start the start of the range
//         * @param end the end of the range
//         */
        void assignKeys(std::vector<Key>::iterator start, std::vector<Key>::iterator end);
        void resizeKeys(int size);


//        void assignKeys(std::vector<std::pair<dtp::Interval, std::shared_ptr<void>>>::iterator start,
//                        std::vector<std::pair<dtp::Interval, std::shared_ptr<void>>>::iterator end);
//
//        /*
//         * @brief moves keys from one node to another
//         * @param mid the index of left-most key to move (until end of vector)
//         * @param child the node from which to move the keys
//         */
//        void moveKeys(int mid, Node* child);
//        /*
//         * @brief resize the keys vector (to order-1)
//         */
//        void resizeKeys();
//        /*
//         * @brief calculates/updates the new key (Interval) of the Node based on the keys
//         */
//        dtp::Interval updateKey();
//
        void addChild(Node* child, int index);
        Node* getChild(int index);




//        void assignChilds(std::vector<Node*>::iterator start, std::vector<Node*>::iterator end);
//        void resizeChildren(int size);
//
//        void addData(dtp::Interval interval, std::shared_ptr<void> data);

private:
        int order; // order of the Node
        std::vector<Key> keys;
        std::vector<Node*> children; // children of the Node
        Node* next;
        bool isLeaf; // is the Node a leaf
};

#endif //IBPTREE_NODE_HPP
