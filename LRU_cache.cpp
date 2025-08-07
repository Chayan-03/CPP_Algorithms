#include <unordered_map>

// Using a struct for the node is fine, but it's often cleaner inside the class.
// Using 'prev' and 'next' is more conventional for a doubly linked list.
class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    // Corrected constructor using an initializer list to avoid shadowing
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    // **Correction 1: All variables must be members of the class, not global.**
    int capacity;
    std::unordered_map<int, Node*> cache_map;
    Node* head; // Sentinel/dummy node
    Node* tail; // Sentinel/dummy node

    // Helper function to add a node right after the head (most recent)
    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    // Helper function to remove a node from the list
    void removeNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        // Initialize sentinel nodes
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        // If key is not in the map, it's not in the cache
        if (cache_map.find(key) == cache_map.end()) {
            return -1;
        }

        // **Correction 2: Correct 'get' logic**
        // If the key exists, we need to move its node to the front (most recent)
        Node* targetNode = cache_map[key];
        removeNode(targetNode);
        addNode(targetNode);
        
        return targetNode->val;
    }
    
    void put(int key, int value) {
        // **Correction 3: Correct 'put' logic**
        // If key already exists, update its value and move it to the front.
        if (cache_map.find(key) != cache_map.end()) {
            Node* existingNode = cache_map[key];
            existingNode->val = value; // Update the value
            removeNode(existingNode);
            addNode(existingNode);
            return; // Exit after updating
        }

        // If the cache is full, we must remove the least recently used item.
        if (cache_map.size() == capacity) {
            // The LRU item is the one just before the tail sentinel node.
            Node* lruNode = tail->prev;
            cache_map.erase(lruNode->key); // Erase from map
            removeNode(lruNode);          // Remove from list
            delete lruNode;               // Free memory
        }

        // Add the new key-value pair.
        Node* newNode = new Node(key, value);
        cache_map[key] = newNode; // Add to map
        addNode(newNode);         // Add to the front of the list
    }

    // It's good practice to add a destructor to free memory.
    ~LRUCache() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};