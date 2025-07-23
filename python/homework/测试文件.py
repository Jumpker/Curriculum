import cvxpy as cp
import numpy as np
c = np.array([40,50])
a = np.array([[1,2],[4,3]])
b = np.array([40,120])
x = np.Variable(2, pos=True)
obj = cp.Maximize(c @ x)
cons = [a @ x <= b]
prob = cp.Problem(obj, cons)
prob.solve(solver='GLPK_MI')
print('最优解为: ',x.value)
print('最优值为: ',prob.value)