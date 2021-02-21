import matplotlib.pyplot as plt
import sys
import numpy as np

max = int(sys.argv[2]) + int(sys.argv[3])
step = int(sys.argv[3])
markers = ["+", "x", "P", "X"]

data1 = np.genfromtxt("Analytics/MergeSort/" + sys.argv[1] + "/Timing.csv", delimiter=",", names=["x", "y"])
data2 = np.genfromtxt("Analytics/QuickSort/" + sys.argv[1] + "/Timing.csv", delimiter=",", names=["x", "y"])
data3 = np.genfromtxt("Analytics/SelectionSort/" + sys.argv[1] + "/Timing.csv", delimiter=",", names=["x", "y"])
data4 = np.genfromtxt("Analytics/BubbleSort/" + sys.argv[1] + "/Timing.csv", delimiter=",", names=["x", "y"])

comp1 = np.genfromtxt("Analytics/MergeSort/" + sys.argv[1] + "/Comparisons.csv", delimiter=",", names=["x", "y"])
comp2 = np.genfromtxt("Analytics/QuickSort/" + sys.argv[1] + "/Comparisons.csv", delimiter=",", names=["x", "y"])
comp3 = np.genfromtxt("Analytics/SelectionSort/" + sys.argv[1] + "/Comparisons.csv", delimiter=",", names=["x", "y"])
comp4 = np.genfromtxt("Analytics/BubbleSort/" + sys.argv[1] + "/Comparisons.csv", delimiter=",", names=["x", "y"])

fig, (ax1, ax2) = plt.subplots(2)

ax1.plot(data1['x'], data1['y'], marker = markers[0])
ax1.plot(data2['x'], data2['y'], marker = markers[1])
ax1.plot(data3['x'], data3['y'], marker = markers[2])
ax1.plot(data4['x'], data4['y'], marker = markers[3])
ax1.legend(["Merge Sort", "Quick Sort", "Selection Sort", "Bubble Sort"])
ax1.set(
    xlabel="Input array size", ylabel="Time taken in seconds", 
    xticks=range(0, max, step),
    title="Comparison of time taken by various sorting algorithms"
    )
ax1.grid(True)

ax2.plot(comp1['x'], comp1['y'], marker = markers[0])
ax2.plot(comp2['x'], comp2['y'], marker = markers[1])
ax2.plot(comp3['x'], comp3['y'], marker = markers[2])
ax2.plot(comp4['x'], comp4['y'], marker = markers[3])
ax2.legend(["Merge Sort", "Quick Sort", "Selection Sort", "Bubble Sort"])
ax2.set(
    xlabel="Input array size", ylabel="Number of comparisons", 
    xticks=range(0, max, step),
    title="Number of comparisons required by various sorting algorithms"
    )
ax2.grid(True)
plt.show()