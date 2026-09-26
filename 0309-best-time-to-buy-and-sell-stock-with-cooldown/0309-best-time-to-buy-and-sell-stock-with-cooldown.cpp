class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = -prices[0];
        int sold = 0;
        int cooldown = 0;

        for (int i = 1; i < prices.size(); i++) {
            int prevHold = hold;
            int prevSold = sold;
            int prevCooldown = cooldown;

            hold = max(prevHold, prevCooldown - prices[i]);
            sold = prevHold + prices[i];
            cooldown = max(prevCooldown, prevSold);
        }

        return max(sold, cooldown);
    }
};