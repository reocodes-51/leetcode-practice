class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        int first = -1;
        int previous = -1;
        int minDist = INT_MAX;
        
        int pos = 1;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        while (curr->next != nullptr) {
            
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                
                if (first == -1) {
                    first = pos;
                }

                if (previous != -1) {
                    minDist = min(minDist, pos - previous);
                }
                
                previous = pos;
            }
            
            prev = curr;
            curr = curr->next;
            pos++;
        }
        
        if (first == previous) {
            return {-1, -1};
        }
        
        int maxDist = previous - first;
        
        return {minDist, maxDist};
    }
};