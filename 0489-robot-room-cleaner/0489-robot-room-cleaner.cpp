class Solution {
public:
    void cleanRoom(Robot& robot) {
        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        unordered_set<string> visited;
        cleanRoomRecursive(robot, visited, directions, 0, 0, 0);
    }
private:
    void cleanRoomRecursive(Robot &robot, unordered_set<string> &visited, const vector<vector<int>> &directions, int i, int j, int faceDirection) {
        visited.insert(to_string(i) + "," + to_string(j));
        robot.clean();
        
        for (int k = 0; k < 4; ++k) {
            int nextFaceDirection = (faceDirection + k) % 4;
            int iNext = i + directions[nextFaceDirection][0];
            int jNext = j + directions[nextFaceDirection][1];
            
            if (!visited.count(to_string(iNext) + "," + to_string(jNext)) && robot.move()) {
                cleanRoomRecursive(robot, visited, directions, iNext, jNext, nextFaceDirection);
                moveBack(robot);
            }
            robot.turnRight();
        }
    }
    void moveBack(Robot &robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    
};
