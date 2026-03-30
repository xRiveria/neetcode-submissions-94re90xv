class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
        {
            return false;
        }

        std::map<int, int> frequencyMap;
        for (int i = 0; i < hand.size(); ++i)
        {
            frequencyMap[hand[i]]++;
        }
        std::sort(hand.begin(), hand.end()); 

        for (int i = 0; i < hand.size(); ++i)
        {
            // If the current card is already used up (its count is 0), skip it
            if (frequencyMap[hand[i]] == 0)
            {
                continue;
            }

            // Say the current number is 2. We want group sizes of 4. We check if 2, 3, 4, 5 are valid.
            for (int j = hand[i]; j < hand[i] + groupSize; ++j)
            {
                if (frequencyMap[j] == 0)
                {
                    return false;
                }
                else
                {
                    frequencyMap[j]--;
                }
            }
        }

        return true;
    }
};
