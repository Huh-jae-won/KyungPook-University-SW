function [fx,ea,iter] = Ch04_25(x,es,maxit)
% Maclaurin series of exponential function
% [fx,ea,iter] = IterMeth(x,es,maxit)
% input:
% x = value at which series evaluated
% es = stopping criterion (default = 0.0001)
% maxit = maximum iterations (default = 50)
% output:
% fx = estimated value
% ea = approximate relative error (%)
% iter = number of iterations
% defaults:
if nargin<2 || isempty(es),es=0.0001;end
if nargin<3 || isempty(maxit),maxit=50;end
% initialization
iter = 1; sol = 1; ea = 100;
fprintf("iter sol      ea\n")
% iterative calculation
while (1)
 solold = sol;
 sol = sol + power(-1,iter)*x^(2*iter) / factorial(2*iter);
 
 
 if sol~=0
 ea=abs((sol - solold)/sol)*100;
 end
 fprintf("%d    %.5f, %.5f\n",iter,sol,ea)
 iter = iter + 1;
 if ea<=es || iter>=maxit,break,end
end
fx = sol;
end