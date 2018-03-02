%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                     % 
% Sudoku Solver for size n**2 by n**2 %
%                                     %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Inputs n = size of sudoku box

#const n=3.
#show spot/3.
#show size/1.

size(n).

1{spot(X,Y,1..n**2)}1 :- X=1..n**2,Y=1..n**2.
% One number per spot on the board

:- spot(X1,Y,N1), spot(X2,Y,N2), X1!=X2,N1=N2.
% No column has the same number
:- spot(X,Y1,N1), spot(X,Y2,N2), Y1!=Y2,N1=N2.
% No row has the same number

same_box(X,Y,X2,Y2) :- X=1..n**2,X2=1..n**2,Y2=1..n**2,Y=1..n**2, B=((Y-1)/n)*n+(X-1)/n, C=((Y2-1)/n)*n+(X2-1)/n, B=C.
% Will be filled with X,Y pairs that are in the same box.

:- same_box(X1,Y1,X2,Y2), spot(X1,Y1,N1), spot(X2,Y2,N2),X1 != X2,N1 = N2.
% Makes sure things in the same box do not have the same value
:- same_box(X1,Y1,X2,Y2), spot(X1,Y1,N1), spot(X2,Y2,N2),Y1 != Y2,N1 = N2.
% Makes sure things in the same box do not have the same value
