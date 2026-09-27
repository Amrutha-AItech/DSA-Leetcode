class Solution {
public:
    int minMutation(
        string startGene,
        string endGene,
        vector<string>& bank) {

        unordered_set<string> valid(
            bank.begin(), bank.end()
        );

        if (!valid.count(endGene))
            return -1;

        queue<string> q;
        q.push(startGene);

        unordered_set<string> visited;
        visited.insert(startGene);

        string chars = "ACGT";
        int mutations = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string gene = q.front();
                q.pop();

                if (gene == endGene)
                    return mutations;

                for (int i = 0; i < gene.size(); i++) {
                    char original = gene[i];

                    for (char ch : chars) {
                        if (ch == original)
                            continue;

                        gene[i] = ch;

                        if (valid.count(gene) &&
                            !visited.count(gene)) {

                            visited.insert(gene);
                            q.push(gene);
                        }
                    }

                    gene[i] = original;
                }
            }

            mutations++;
        }

        return -1;
    }
};