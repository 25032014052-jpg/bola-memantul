import numpy as np
import matplotlib.pyplot as plt
from matplotlib import animation

# Setup the figure and axes...
fig, ax = plt.subplots(figsize=(8,8))

## Adjust axes limits according to your problem. Here we don't need more than a couple of meters left or right, and 600 meters up
ax.set(xlim=(0, 10), ylim=(0, 60), xlabel='Position, meters', ylabel='Height, meters')

r = np.loadtxt("posisi_bola.txt", delimiter=",")
waktu = 20
dt = 0.01

## drawing the first data point  
scat = ax.scatter(r[0,0], r[0,1], marker='o', c='b', s=300)

## animating 
def animate(i):
    scat.set_offsets(r[i])

ani = animation.FuncAnimation(fig, func=animate, frames=int(waktu/dt))
ani.save('simulasi_bola.html', writer=animation.HTMLWriter(fps= 1//dt))
plt.close()
