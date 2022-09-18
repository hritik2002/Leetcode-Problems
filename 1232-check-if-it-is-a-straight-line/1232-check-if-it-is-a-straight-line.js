/**
 * @param {number[][]} coordinates
 * @return {boolean}
 */
var checkStraightLine = function(coordinates) {
    let dy,dx,ndy,ndx,i;
    dy=coordinates[1][1] - coordinates[0][1];
    dx=coordinates[1][0] - coordinates[0][0];

    for(i=2; i<coordinates.length; i++)
    {
        ndy=coordinates[i][1] - coordinates[0][1];  // new dy
        ndx=coordinates[i][0] - coordinates[0][0];  // new dx
        
        if(ndx*dy !== ndy*dx )     //straight line: (x3 - x1)/ (y3 - y1) == (x2 - y1)/ (y2 - y1)
            return false;
    }

    return true;
};