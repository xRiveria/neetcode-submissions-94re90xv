class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> count;
        for (int num : hand) count[num]++;

 
        for (int num : hand)
        {
            int start = num;
            // Always start from the smallest card we still have left, and try to build a straight starting from it.
            // Let start = the smallest card we still have.
            // Try to build a group: [start, start+1, start+2, ..., start+groupSize-1]
            // If we used all cards successfully → return true.
            while (count[start - 1] > 0) start--; 
            while (start <= num)
            {
                while (count[start] > 0)
                {
                    for (int i = start; i < start + groupSize; ++i)
                    {

                        if (count[i] == 0) return false; // If we're building from the smallest index and a card in the middle is missing, we cannot form our groups.
                        count[i]--;
                    }
                }
                start++;
            }
        }

        return true;
    }
};
