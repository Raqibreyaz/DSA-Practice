class Solution {
public:
    int findTheWinner(int n, int k) {

        if(n == 1)
            return 1;

        queue<int> q;

        for(int i = 1; i <= n; i++){
            q.push(i);
        }

        while(q.size() > 1){

            // removing k-1 players from front and adding at the back
            for(int i = k; i > 1; i--){
                int player = q.front();
                q.pop();

                q.push(player);
            }

            // removing the kth one
            q.pop();
        }

        return q.front();
    }
};