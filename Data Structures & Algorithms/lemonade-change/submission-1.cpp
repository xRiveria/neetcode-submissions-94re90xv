class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveDollarNotes = 0;
        int tenDollarNotes = 0;
        int twentyDollarNotes = 0;

        for (int bill : bills)
        {
            if (bill == 5)
            {
                fiveDollarNotes++;
            }
            else if (bill == 10)
            {
                tenDollarNotes++;
                if (fiveDollarNotes > 0)
                {
                    fiveDollarNotes--;
                }
                else
                {
                    return false;
                }
            }
            else if (bill == 20)
            {
                twentyDollarNotes++;
                if (tenDollarNotes > 0)
                {
                    tenDollarNotes--;
                    if (fiveDollarNotes > 0)
                    {
                        fiveDollarNotes--;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (fiveDollarNotes >= 3)
                {
                    fiveDollarNotes -= 3;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};