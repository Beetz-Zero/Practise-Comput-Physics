import matplotlib.pyplot as plt
import numpy as np

plt.hist(np.random.randint(low=0, high=6, size=20))

plt.savefig('hist.png', fmt='png')
plt.show()
import matplotlib.patches as mpatches

figure, ax = plt.subplots(1)

rect = mpatches.Rectangle((2,5),5,2, edgecolor='r', facecolor="none")

ax.scatter(
    np.random.rand(10) * 10,  # абсциссы точек
    np.random.rand(10) * 10  # ординаты точек
)

ax.add_patch(rect)

plt.show()