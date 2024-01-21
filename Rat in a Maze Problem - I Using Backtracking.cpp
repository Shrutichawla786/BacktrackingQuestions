link-->https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
Q.Rat in a Maze Problem - I
code-->
   bool isSafe(int x, int y, int n,   vector<vector<bool>>&visited, vector<vector<int>> &m){
        if((x>=0 && x<n) && (y>=0 && y<n) && visited [x][y] == 0 && m[x][y] == 1 ){
            return true;
        }
        else{
            return false;
        }
    }
    void solve(vector<vector<int>> &m , int n, vector<string> &ans,int x , int y,   vector<vector<bool>>&visited , string path){
        
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        visited[x][y]=1;
        
        //D
        int newx = x+1;
        int newy=y;
        if(isSafe(newx , newy , n , visited , m)){
            
            solve( m , n , ans , newx , newy , visited , path+'D');
            
        }
        
        //L
        newx = x;
        newy=y-1;
        if(isSafe(newx , newy , n , visited , m)){
            
            solve( m , n , ans , newx , newy , visited , path+'L');
            
        }
        
        //R
        newx = x;
        newy=y+1;
        if(isSafe(newx , newy , n , visited , m)){
            
            solve( m , n , ans , newx , newy , visited , path+'R');
        }
        
        //u
        newx = x-1;
        newy=y;
        if(isSafe(newx , newy , n , visited , m)){
           
            solve( m , n , ans , newx , newy , visited , path +'U');
            
        }
        
        visited[x][y]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        if(m[0][0]==0){
            return ans;
        }
           
        int srcx=0;
        int srcy=0;
        vector<vector<bool>>visited(n , vector<bool>(n,0));
        string path ="";
        solve(m , n , ans ,srcx , srcy , visited , path);
        return ans;
    }
Expected Time Complexity: O(4^(n^2)).
Expected Auxiliary Space: O(n * m), L = length of the path, X = number of paths.


