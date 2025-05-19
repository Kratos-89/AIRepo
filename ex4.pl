queens(N,Solution):-
  length(Solution,N),
  place_queens(Solution,N),
  safe(Solution).

place_queens([],_).
place_queens([Q|Qs],N):-
  place_queens(Q5,N),
  between(1,N,Q),
  \+member(Q,Qs).

safe([]).
safe([Q|Q5]):-
  safe(Qs),
  no_attack(Q,Qs,1).

no_attack(_,[],_).
no_attack(Q,[Q1|Q5],D):-
  Q=\=Q1+D,
  Q=\=Q1-D,
  D1 is D+1
  no_attack(Q,Qs,D1).

%replace 5 with s if its is not working correctly%