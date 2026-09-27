class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;

        unordered_map<Node*, Node*> mp;

        // Create a copy for every node
        Node* curr = head;

        while (curr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Connect next and random pointers
        curr = head;

        while (curr) {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];

            curr = curr->next;
        }

        return mp[head];
    }
};