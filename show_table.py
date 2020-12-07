import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv('demo_data.csv', header=None)

plt.bar(x=data[1],height=data[0])

plt.xticks(rotation = 90)

plt.show()