function [x,res,A,b,detA]= sistema(dataFile)
% SISTEMA.M:
% Read the file 'dataFile' in the format specified for the
% files .DAT. Then extracts matrix A and the rhs b, solves
% the system and compute the norm of the residue.
%
% INPUT
%   dataFile:
%         text string delimited between' ',for ex.:'M00.DAT',
%         which is the name from which matrix A and the rhs
%         b of the system will be extracted.
% OUTPUT
%   x   : solution of the system.
%   res : norm inf. of the residue res = ||A x - b||.
 

TOL=1.0e-11;
fIn=fopen(dataFile,'r');
n=fscanf(fIn,'%d',[1,1]);
p=fscanf(fIn,'%d',[1,1]);
B=fscanf(fIn,'%d %d %e',[3,p]);
B=B';
q=fscanf(fIn,'%d',[1,1]);
V=fscanf(fIn,'%d %e',[2,q]);
V=V';
fclose(fIn);

% Matrix A
A=zeros(n);
for k=1:p
    i=B(k,1)+1;
    j=B(k,2)+1;
    A(i,j)=B(k,3);
end

% Vector b of the rhs of the system:
b=zeros(n,1);
for k=1:q
    i = V(k,1)+1;
    b(i) = V(k,2);
end

fprintf('Solution of the system A x = b\n')
rangA=rank(A,TOL);
if (rangA < n)
  error('rang A = %d <  n = %d: matrix A is singular\n',...
        rangA,n);
else
    x = A\b;
    res = norm(A*x-b,Inf);
end
detA= det(A);
end % end of function SISTEMA
