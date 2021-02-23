import matplotlib.pyplot as plt
import sys
import numpy as np

if len(sys.argv) < 3:
    print("Usage: python3 plot.py [type] [separate]")
    print("\nPass type as 'Element-to-Element-Comparisons-Only' or 'Including-Loop-Comparisons'")
    print("Pass separate as 0 to plot both graphs in the same figure or any other integer to plot them in two different figures")
    exit()
else:
    data = sys.argv[1]
    separate = int(sys.argv[2])

markers = ["P", "x", "P", "x"]
algorithms = ["MergeSort", "QuickSort", "SelectionSort", "BubbleSort"]

if(separate):
    fig1, ax1 = plt.subplots(1)
    fig2, ax2 = plt.subplots(1)
else:
    fig, (ax1, ax2) = plt.subplots(2)

for i in range(4):
    timing = np.genfromtxt("Analytics/" + algorithms[i] + "/" + data + "/Timing.csv", delimiter=",", names=["x", "y"])[1::]
    comparisons = np.genfromtxt("Analytics/" + algorithms[i] + "/" + data + "/Comparisons.csv", delimiter=",", names=["x", "y"])[1::]
    ax1.plot(timing['x'], timing['y'], marker = markers[i])
    ax2.plot(comparisons['x'], comparisons['y'], marker = markers[i])

max = int(timing['x'].max() + timing['x'].min())
step = int(timing['x'].min())//2

ax1.legend(algorithms)
ax1.set(
    xlabel="Input array size", ylabel="Time taken in seconds", 
    xticks=range(0, max, step),
    title="Comparison of time taken by various sorting algorithms"
    )
ax1.grid(True)

ax2.legend(algorithms)
ax2.set(
    xlabel="Input array size", ylabel="Number of comparisons", 
    xticks=range(0, max, step),
    title="Number of comparisons required by various sorting algorithms"
    )
ax2.grid(True)
plt.show()