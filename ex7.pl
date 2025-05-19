G

% Graph definition using directed edges

edge(a, b).

edge(a, c).

edge(b, d).

edge(b, e).

edge(c, f).

edge(e, f).

% Entry point for DFS

dfs(Start) :-
	dfs_visit(Start, []).

% Visit a node if not already visited.
dfs_visit(Node, Visited) :-
	\+ member(Node, Visited),
	write(Node), nl,
	dfs_explore(Node, [Node | Visited]).

% Explore all unvisited neighbors.
dfs_explore(Node, Visited) :-
	edge(Node, Neighbor),
	\+ member(Neighbor, Visited),
	dfs_visit(Neighbor, Visited),
	fail. % Force backtracking to find all neighbors
dfs_explore(_, _). % Base case to stop backtracking