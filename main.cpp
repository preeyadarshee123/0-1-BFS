// 0-1 BFS
void dfs(int node) {
    //Traverse through the 0-connected component
    for(auto v : G0[node])
        if(!Seen[v]) {
            Seen[v] = 1;
            D[v] = D[node];
            dfs(v);
        }
    //Push the unvisited 1-cost neighbours
    for(auto v : G1[node])
        if(!Seen[v]) {
            Seen[v] = 1;
            D[v] = D[node] + 1;
            Q.push(v);
        }
}

void bfs0_1(int start) {
    Q.push(start);
    Seen[start] = 1;
    
    while(!Q.empty()) {
        int top = Q.front();
        Q.pop();
        dfs(top);
    }
}
