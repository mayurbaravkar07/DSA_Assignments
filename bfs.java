 public ArrayList<Integer> bfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        Queue<Integer>queue=new ArrayDeque<>();
        Map<Integer,Boolean>visited=new HashMap<>();
        ArrayList<Integer> result=new ArrayList<>();
          queue.add(0);
          visited.put(0,true);
       while(!queue.isEmpty()){
           int source=queue.remove();
           result.add(source);
           var list=adj.get(source);
           for(var l:list){
                if(!visited.containsKey(l)){
                  queue.add(l);
                  visited.put(l,true);
              }
           }
       }
       return result;
       
    }


///DFS of the graph



class Solution {
      /// ArrayList<Integer>list=new ArrayList<>();
    // Function to return a list containing the DFS traversal of the graph.
    public ArrayList<Integer> dfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        boolean visited[]=new boolean[V+1];
        ArrayList<Integer>list=new ArrayList<>();
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                helper(V,adj,visited,i,list);
            }
        }
    return list;
    }
    public void helper(int V, ArrayList<ArrayList<Integer>> adj,boolean visited[],int source,ArrayList<Integer>list){

        list.add(source);
        visited[source]=true;
        for(var u:adj.get(source)){
            if(visited[u]==false){
              helper(V,adj,visited,u,list);
            }
        }
        
       
    }
}
