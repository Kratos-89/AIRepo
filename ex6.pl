% Defining the graph structure using facts.

edge(a, b).
edge(a, c).
edge(b, d).
edge(b, e).
edge(c, f).
edge(e, f).

% BFS predicate that initializes the search.

bfs(Start) :-
	bfs_visit([Start], []).

% bfs_visit/2 keeps track of the visited nodes and the queue.

bfs_visit([], _) :-
	!. % stop if there are no more nodes in the queue.

bfs_visit([Node | Queue], Visited) :-
	\+ member(Node, Visited), % Ensure Node is not visited
	write(Node), write(' '),  % print the current node
	findall(NextNode, (edge(Node, NextNode), \+ member(NextNode, Visited)), Neighbors),
	append(Queue, Neighbors, NewQueue),
	bfs_visit(NewQueue, [Node | Visited]).

% If a node is already visited, skip it.

bfs_visit([Node | Queue], Visited) :-
	member(Node, Visited),
	bfs_visit(Queue, Visited).