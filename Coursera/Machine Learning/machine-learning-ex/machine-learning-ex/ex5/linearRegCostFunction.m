function [J, grad] = linearRegCostFunction(X, y, theta, lambda)
%LINEARREGCOSTFUNCTION Compute cost and gradient for regularized linear 
%regression with multiple variables
%   [J, grad] = LINEARREGCOSTFUNCTION(X, y, theta, lambda) computes the 
%   cost of using theta as the parameter for linear regression to fit the 
%   data points in X and y. Returns the cost in J and the gradient in grad

% Initialize some useful values
m = length(y); % number of training examples

% You need to return the following variables correctly 
J = 0;
grad = zeros(size(theta));

% ====================== YOUR CODE HERE ======================
% Instructions: Compute the cost and gradient of regularized linear 
%               regression for a particular choice of theta.
%
%               You h θ (x (ishould set J to the cost and grad to the gradient.
%
h=X*theta;
cost_reg(1)=0;
grad_reg(1)=0;
for i=2:size(theta)
  cost_reg(i)=(lambda/(2*m))*theta(i)^2;
  grad_reg(i)=(lambda/m)*theta(i);
endfor
sqrError= (h-y).^2;
J=(1/(2*m))*sum(sqrError)+sum(cost_reg);
grad=((1/m)*(h-y)'*X)+grad_reg;













% =========================================================================

grad = grad(:);

end
