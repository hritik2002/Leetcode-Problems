class Solution {
public:
    int countCollisions(string directions) {
        int count = 0;
        int n = directions.length();
        
        for(int i = 0; i < n; i++) {
            if(directions[i] == 'L') {
                if(i - 1 >= 0 && directions[i - 1] == 'S') {
                    count++;
                    directions[i] = 'S';
                }else if(i - 1 >= 0 && directions[i - 1] == 'R') {
                    count += 2;
                    directions[i] = 'S';
                    directions[i - 1] = 'S';
                }
            }else if(directions[i] == 'R') {
                if(i + 1 < n && directions[i + 1] == 'L') {
                    count += 2;
                    directions[i] = 'S';
                    directions[i + 1] = 'S';
                }else if(i + 1 < n && directions[i + 1] == 'S') {
                    count++;
                    directions[i] = 'S';
                }
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            if(directions[i] == 'L') {
                if(i - 1 >= 0 && directions[i - 1] == 'S') {
                    count++;
                    directions[i] = 'S';
                }else if(i - 1 >= 0 && directions[i - 1] == 'R') {
                    count += 2;
                    directions[i] = 'S';
                    directions[i - 1] = 'S';
                }
            }else if(directions[i] == 'R') {
                if(i + 1 < n && directions[i + 1] == 'L') {
                    count += 2;
                    directions[i] = 'S';
                    directions[i + 1] = 'S';
                }else if(i + 1 < n && directions[i + 1] == 'S') {
                    count++;
                    directions[i] = 'S';
                }
            }
        }
        
        return count;
    }
};