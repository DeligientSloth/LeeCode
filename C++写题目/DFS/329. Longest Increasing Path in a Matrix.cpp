class Solution {
public:
    int dfs(vector<vector<int>>& matrix,vector<vector<int>>& record,int x,int y,int rows,int columns){
        if(x<0||y<0||x>=rows||y>=columns) return 0;//入口参数检查
        if(record[x][y]!=0) return record[x][y];
        //求出相邻点的最长递增子序列
        if(x>=1&&matrix[x-1][y]>matrix[x][y])
            record[x][y]=max(record[x][y],dfs(matrix,record,x-1,y,rows,columns));//此时recodxy==0
        if(y>=1&&matrix[x][y-1]>matrix[x][y])
            record[x][y]=max(record[x][y],dfs(matrix,record,x,y-1,rows,columns));
        if(x<=rows-2&&matrix[x+1][y]>matrix[x][y])
            record[x][y]=max(record[x][y],dfs(matrix,record,x+1,y,rows,columns));
        if(y<=columns-2&&matrix[x][y+1]>matrix[x][y])
            record[x][y]=max(record[x][y],dfs(matrix,record,x,y+1,rows,columns));
        //两种情况 1.四面的元素都小于中心点，record[x][y]由原来的0变为1,2.至少有一边是大于中心点的，record[x][y]在最长路基础上加一
        return ++record[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        if(rows==0) return 0;
        int columns=matrix[0].size();
        if(columns==0) return 0;
        int longestPath=0;
        vector<vector<int>> record(rows,vector<int>(columns,0));//备忘录法，record[x][y]表示记录过的以x,y为起点的最长递增子序列
        for(int x=0;x<rows;x++)
            for(int y=0;y<columns;y++)
                longestPath=max(longestPath,dfs(matrix,record,x,y,rows,columns));//求出以x,y为起点的最大值
        return longestPath;
    }
};
