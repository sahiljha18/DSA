class Solution {
public:

    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {

        // Empty graph
        if (node == NULL)
            return NULL;

        // Already cloned
        if (mp.find(node) != mp.end())
            return mp[node];

        // Create new node
        Node* clone = new Node(node->val);

        // Store it before visiting neighbors
        mp[node] = clone;

        // Clone all neighbors
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};