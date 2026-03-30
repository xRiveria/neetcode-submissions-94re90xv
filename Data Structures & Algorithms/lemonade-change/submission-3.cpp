class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // A perfect check is to see if $5 becomes negative.
        // This is because 5$ is needed as a change in every large bill setting.
        // If it becomes negative, it means we tried to give a bill we don't have. Thats not allowed.
        int fiveDollarBills = 0;
        int tenDollarBills = 0;
        for (auto bill : bills)
        {
            if (bill == 5)
            {
                fiveDollarBills++;
            }
            else if (bill == 10)
            {
                fiveDollarBills--;
                tenDollarBills++;
            }
            else if (bill == 20)
            {
                if (tenDollarBills > 0)
                {
                    tenDollarBills--;
                    fiveDollarBills--;
                }
                else
                {
                    fiveDollarBills -= 3;
                }
            }

            if (fiveDollarBills < 0)
            {
                return false;
            }
        }

        return true;
    }
};