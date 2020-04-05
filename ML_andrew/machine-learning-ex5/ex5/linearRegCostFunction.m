function [J, grad] = linearRegCostFunction(X, y, theta, lambda)
%LINEARREGCOSTFUNCTION Compute cost and gradient for regularized linear 
%regression with multiple variables
%   [J, grad] = LINEARREGCOSTFUNCTION(X, y, theta, lambda) computes the 
%   cost of using theta as the parameter for linear regression to fit the 
%   data points in X and y. Returns the cost in J and the gradient in grad

% Initialize some useful values
m = length(y); % number of training examples
n=size(theta,1);
% You need to return the following variables correctly 
J = 0;
grad = zeros(size(theta));

% ====================== YOUR CODE HERE ======================
% Instructions: Compute the cost and gradient of regularized linear 
%               regression for a particular choice of theta.
%
%               You should set J to the cost and grad to the gradient.
%

for i=1:m
  x=X(i,:);
  Hx=x*theta;
  J=J+power(Hx-y(i),2);
end
J=J/2/m;
J=J+lambda/2/m*sum(power(theta(2:end),2));

for i=1:m
  x=X(i,:);
  grad=grad+(x*theta-y(i))*x';
end
grad=grad/m;
for i=2:n
  grad(i)+=lambda/m*theta(i);
end;


% =========================================================================

grad = grad(:);

end
