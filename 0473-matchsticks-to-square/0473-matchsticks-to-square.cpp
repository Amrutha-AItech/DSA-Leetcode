class Solution {
public:
    bool backtrack(vector<int>& matchsticks,
                   vector<int>& sides,
                   int index,
                   int target) {

        if (index == matchsticks.size())
            return sides[0] == target &&
                   sides[1] == target &&
                   sides[2] == target &&
                   sides[3] == target;

        int stick = matchsticks[index];

        for (int i = 0; i < 4; i++) {

            if (sides[i] + stick > target)
                continue;

            // Avoid trying identical empty sides.
            if (i > 0 && sides[i] == sides[i - 1])
                continue;

            sides[i] += stick;

            if (backtrack(
                    matchsticks,
                    sides,
                    index + 1,
                    target)) {
                return true;
            }

            sides[i] -= stick;
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(
            matchsticks.begin(),
            matchsticks.end(),
            0
        );

        if (total % 4 != 0)
            return false;

        int target = total / 4;

        sort(matchsticks.rbegin(),
             matchsticks.rend());

        if (matchsticks[0] > target)
            return false;

        vector<int> sides(4, 0);

        return backtrack(
            matchsticks,
            sides,
            0,
            target
        );
    }
};