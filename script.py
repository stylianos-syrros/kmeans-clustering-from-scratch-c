import matplotlib.pyplot as plt
import random

#open file with examples
file=open('teams_data.txt','r')
read=file.readlines() #oles tis grammes tou arxeiou me/n

#open file with the centers
file1=open('centers_data.txt','r')
read1=file1.readlines()
modified1=[] #coordinates kentrwn
for line in read1:
    modified1.append(line.split())


modified=[] #oles tis grammes xwris to /n
for line in read:
    modified.append(line.split())

#preparing the points for the graph
colors=["red","black","orange","purple","green","yellow","maroon","brown","blue","violet","yellowgreen","grey"]
team=[] #teams
listX1=[] #xAxis
listX2=[] #yAxis
for element in modified:
    team.append(int(element[0]))
    listX1.append(float(element[1]))
    listX2.append(float(element[2]))
no_of_teams=team[len(team)-1]+1 #num of teams


rnd_colors=[] #list with random colors
for i in range(no_of_teams):
    x=random.randint(0,len(colors)-1)
    while colors[x] in rnd_colors:
        x=random.randint(0,len(colors)-1)
    rnd_colors.append(colors[x])
print(rnd_colors)
#plot the points
current_color=rnd_colors[0]
counter=0

#plot the examples
for i in range(len(team)):
    if i!=len(team)-1:
        if team[i+1] != team[i]:
            plt.scatter(listX1[i],listX2[i],color=rnd_colors[counter],marker='+',s=100)
            counter+=1
        else:
            plt.scatter(listX1[i],listX2[i],color=rnd_colors[counter],marker='+',s=100)
    else:
        plt.scatter(listX1[i],listX2[i],color=rnd_colors[-1],marker='+',s=100)

#plot the centers
counter=0
for i in range(len(modified1)):
    plt.scatter(float(modified1[i][0]),float(modified1[i][1]),color='black',marker='*',s=200)
    counter+=1
plt.title("K-means output")
plt.show()



#diagramma me sfalma omadopoihshs
X1=[621.960449,325.041260,225.237823,201.638275]
X2=[3,6,9,12]
plt.plot(X2,X1)
plt.title("Total team error")
plt.xlabel("Number of clusters")
plt.ylabel("Total team error of each cluster")
plt.xticks(X2,X2)
plt.show()
