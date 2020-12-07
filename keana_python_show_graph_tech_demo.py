import matplotlib.pyplot as plt
import pandas as pd

#read in the data from the csv file
data = pd.read_csv('demo_data.csv', header=None)

#plot the histogram on a bar graph. The data is already in histogram buckets of one minute. 
plt.bar(x=data[1],height=data[0])

#rotate the labels for the x-axis to make the long names easy to read.
plt.xticks(rotation = 90)

#display the graph. 
plt.show()
