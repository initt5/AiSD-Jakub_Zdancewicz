import matplotlib.pyplot as plt
import numpy as np

# Data points
X = [2, 5, 10, 100, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000]
Y1 = [11, 54, 151, 10585, 25215263, 100178631, 400596113, 900914459, 1598399305, 2493582891, 3595595917, 4900025671, 6400476209, 8106207457, 10000652537]
Y2 = [13, 44, 127, 7261, 16698227, 66530101, 266719083, 599931175, 1065964161, 1666834814, 2398527221, 3263567620, 4262851602, 5405866935, 6665620341]
Y3 = [34, 165, 426, 7060, 579448, 1238912, 2637840, 4087840, 5595696, 7125696, 8655696, 10221408, 11831408, 13441408, 15051408]
Y4 = [46, 166, 436, 6351, 512511, 1037546, 2274581, 3412671, 4812671, 6198811, 7423811, 8648811, 9873811, 11138026, 12638026]
Y5 = [48, 155, 415, 7870, 743815, 1612708, 3475225, 5429501, 7450608, 9518727, 11609467, 13734508, 15899883, 18084690, 20286778]
Y6 = [44, 161, 406, 7093, 637934, 1370101, 2951211, 4586432, 6294063, 8038634, 9803551, 11585944, 13376727, 15184447, 17034789]

# Scatter plot for each sorting algorithm
plt.scatter(X, Y3, label="Merge Sort", color='green')
plt.scatter(X, Y4, label="Modyfikacja Merge Sort", color='red')
plt.scatter(X, Y5, label="Heap Sort", color='purple')
plt.scatter(X, Y6, label="Modyfikacja Heap Sort", color='brown')

# Polynomial fit for each dataset
z3 = np.polyfit(X, Y3, 2)
z4 = np.polyfit(X, Y4, 2)
z5 = np.polyfit(X, Y5, 2)
z6 = np.polyfit(X, Y6, 2)

# Creating polynomial functions
p3 = np.poly1d(z3)
p4 = np.poly1d(z4)
p5 = np.poly1d(z5)
p6 = np.poly1d(z6)

# Drawing trend lines
plt.plot(X, p3(X), label="Merge Sort Trend", color='green', linestyle='--')
plt.plot(X, p4(X), label="Modyfikacja Merge Sort Trend", color='red', linestyle='--')
plt.plot(X, p5(X), label="Heap Sort Trend", color='purple', linestyle='--')
plt.plot(X, p6(X), label="Modyfikacja Heap Sort Trend", color='brown', linestyle='--')

# Axis labels
plt.xlabel('Wielkość tablicy wejściowej')
plt.ylabel('Ilość operacji')

# Legend
plt.legend()

# Show plot
plt.show()