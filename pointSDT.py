import matplotlib.pyplot as plt

def load_examples(x1, x2):
    # Open the file in read mode
    with open("examplesSDT.txt", "r") as fp:
       lines = fp.readlines()
    # Extract the x and y coordinates from each line
    for line in lines:
        values = line.split()
        x1.append(float(values[0]))
        x2.append(float(values[1]))

def find_category(listX1, listX2, categories):
    for i in range(len(listX1)):
        x1, x2 = listX1[i], listX2[i]
        if (x1 - 0.5) ** 2 + (x2 - 0.5) ** 2 < 0.2 and x2 > 0.5:
            categories.append("C1")
        elif (x1 - 0.5) ** 2 + (x2 - 0.5) ** 2 < 0.2 and x2 < 0.5:
            categories.append("C2")
        elif (x1 + 0.5) ** 2 + (x2 + 0.5) ** 2 < 0.2 and x2 > -0.5:
            categories.append("C1")
        elif (x1 + 0.5) ** 2 + (x2 + 0.5) ** 2 < 0.2 and x2 < -0.5:
            categories.append("C2")
        elif (x1 - 0.5) ** 2 + (x2 + 0.5) ** 2 < 0.2 and x2 > -0.5:
            categories.append("C1")
        elif (x1 - 0.5) ** 2 + (x2 + 0.5) ** 2 < 0.2 and x2 < -0.5:
            categories.append("C2")
        elif (x1 + 0.5) ** 2 + (x2 - 0.5) ** 2 < 0.2 and x2 > 0.5:
            categories.append("C1")
        elif (x1 + 0.5) ** 2 + (x2 - 0.5) ** 2 < 0.2 and x2 < 0.5:
            categories.append("C2")
        else:
            categories.append("C3")



def plot_points(listX1 , listX2 , categories):
  # Set up a color map
  cmap = {'C1': 'b', 'C2': 'g', 'C3': 'r'}
  # Plot the points with the corresponding colors
  for x1 , x2 , c in zip(listX1,listX2,categories):
    plt.scatter(x1, x2, color=cmap[c], marker = '+', s=10)
  # Show the plot
  plt.show()


listX1 = []
listX2 = []
categories = []
load_examples(listX1 , listX2)
find_category(listX1 , listX2 , categories)
plot_points(listX1 , listX2 , categories)
