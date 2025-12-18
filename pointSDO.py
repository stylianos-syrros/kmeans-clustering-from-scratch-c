import matplotlib.pyplot as plt

def load_examples(x1, x2):
    # Open the file in read mode
    with open("examplesSDO.txt", "r") as fp:
       lines = fp.readlines()
    # Extract the x and y coordinates from each line
    for line in lines:
        values = line.split()
        x1.append(float(values[0]))
        x2.append(float(values[1]))

def plot_points(listX1 , listX2 ):
  # Plot the points 
  for x1 , x2 in zip(listX1,listX2):
    plt.scatter(x1, x2, color='blue', marker = '+', s=10)
  # Show the plot
  plt.show()


listX1 = []
listX2 = []
load_examples(listX1 , listX2)
plot_points(listX1 , listX2 )
