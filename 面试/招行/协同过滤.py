import numpy as np

a1 = [3, 4, 3]
b1 = [2, 4, 4]
c1 = [3, 5, 4]
d1 = [2, 2, 3]
e1 = [4, 1, 4]

sim_list = []
for i in (a1, b1, c1, d1):
    sim_list.append(1/sum([(x-y)**2 for (x, y) in zip(e1, i)])**0.5)

print(sim_list)

a2 = [3, 4, 3]
b2 = [5, 1, 2]
c2 = [2, 5, 5]
d2 = [4, 2, 3]

rec_list = []
for i, k in enumerate([a2, b2, c2, d2]):
    rec_list.append([sim_list[i] * x for x in k])

print(np.sum(rec_list, axis=0))
