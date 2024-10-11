class largest_island{
	public static void main (String args[]){
		int island[][] = {
                            {1, 0, 0, 1, 0},
                            {1, 0, 1, 0, 0},
                            {0, 0, 1, 0, 1},
                            {1, 0, 1, 1, 1},
                            {1, 0, 1, 1, 0}
                            };
        int res = 0;
        int count = 0;
        for(int i=0;i<island.length;i++){
        	for(int j=0;j<island[0].length;j++){
        		if(island[i][j]!=0){
        			count++;
        		res = Math.max(largest(island, i,j), res);
        		}
        		
        	}
        }
        System.out.println("largest island: "+res+" operations: "+count);
    }
    public static int largest(int graph[][], int i, int j){
    	if(i<0 || i>=graph.length || j<0 || j>=graph[0].length || graph[i][j]==0){
    		return 0;
    	}
    	int dx[] = {1,-1,0, 0};
    	int dy[] = {0, 0,1,-1};
    	int l = 0;
    	graph[i][j]=0;
    	for(int k =0;k<4;k++){

    		l += largest(graph,i+dx[k],j+dy[k]);
    		// max_l = Math.max(l, max_l);
    	}
    	return l+1;
    }
	
}