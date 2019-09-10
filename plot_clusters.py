import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import pandas as pd
import numpy as np
"""
train = pd.read_csv("C:/Users/Francesco/Desktop/unifi/Competizioni/OkCupid/101.csv")
test = pd.read_csv("C:/Users/Francesco/Desktop/unifi/Competizioni/OkCupid/102.csv")

train['TARGET'] = 1
test['TARGET'] = 0
train.describe()
print(train)
print(train.describe())
print(test.describe())
"""

data=pd.read_csv("C:/Users/Francesco/CLionProjects/kmeans_seriale/cmake-build-debug/output.csv")
"""print(data[["x1"]])"""

print(data.describe())
fig = plt.figure()
ax = fig.add_subplot(111)
x1 = data[["x1"]]
x2 = data[["x2"]]
"""
cluster = data[["cluster"]]
scatter = ax.scatter(x1,x2,c=cluster)
ax.set_xlabel('x')
ax.set_ylabel('y')
plt.colorbar(scatter)
#plt.show()
#plt.savefig('plot1.png')
#plot 3D
x3 = data[["x3"]]
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(x1,x2,x3)
ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')
col = np.arange(30)
print(col)

#plt.show()

#prova3
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
x = np.array(data['x1'])
y = np.array(data['x2'])
z = np.array(data['x3'])
ax.scatter(x,y,z, c=data["cluster"])
ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')
plt.colorbar(scatter)
plt.show()
"""

thread=(1,2,3,4,5,6,7,8,9,10)
tempo=(929.932,554.635,434.368,375.278,340.358,317.651,301.63,295.699,317.819,307.321)
tempo=(929.932,554.635,434.368,375.278,340.358,317.651,301.63,295.699,317.819,307.321) #dinamico
sequenziale=(929.932,929.932,929.932,929.932,929.932,929.932,929.932,929.932,929.932,929.932)
speedup=np.array(sequenziale)/np.array(tempo)
print(speedup)
#plot speedup
plt.scatter(thread,speedup)
plt.plot(thread,speedup)
plt.title("Speedup plot")
plt.xlabel("Threads")
plt.ylabel("Speedup")
plt.show()
#histogram
n_bins = 10
y=tempo
x=thread
plt.bar(x,y,align='center',color="c") # A bar chart
plt.title("Timing esecution")
plt.xlabel('Threads')
plt.ylabel('Seconds')
plt.show()



#al variare di K
K=(2,3,4,5,6,7,8,9,10)
tempo=(14.9144,6.49016,5.89734,15.2924,19.7024,8.26355,18.2491,19.8818,13.9527)
sequenziale=(68.6242,29.5848,28.3802,98.0321,135.063,50.6547,131.082,130.242,89.1437)
speedup=np.array(sequenziale)/np.array(tempo)
print(speedup)
#plot speedup
plt.scatter(K, speedup)
plt.plot(K, speedup)
plt.title("Speedup plot of K")
plt.xlabel("K")
plt.ylabel("Speedup")
plt.show()

#con la nuova parallelizzazione su k, dataset 2M
thread=(1,2,3,4,5,6,7,8,9,10)
#tempo=(929.932,485.726,314.031, 254.987, 219.757, 196.695, 180.139, 166.975, 197.157, 192.232)
tempo=(929.932,485.726,314.031, 254.987, 219.757, 196.695, 180.139, 166.975, 177.287, 177.153) #dinamico
sequenziale=(929.932,929.932,929.932,929.932,929.932,929.932,929.932,929.932,929.932,929.932)
speedup=np.array(sequenziale)/np.array(tempo)
print(speedup)
#plot speedup
plt.scatter(thread,speedup)
plt.plot(thread,speedup)
plt.title("Speedup plot")
plt.xlabel("Threads")
plt.ylabel("Speedup")
plt.show()
#histogram
n_bins = 10
y=tempo
x=thread
plt.bar(x,y,align='center',color="c") # A bar chart
plt.title("Timing esecution")
plt.xlabel('Threads')
plt.ylabel('Seconds')
plt.show()


#al variare di K dataset 200k con 200 iterazioni fisso
K=(2,3,4,5,6,7,8,9,10)
#tempo=(11.1947,12.4869,13.8921,15.5385,16.7009,18.4992,19.9722,23.9036,25.4356)
tempo=(11.1947,12.4869,13.8921,15.5385,16.7009,18.4992,19.9722,25.0537,26.8584) #dinamico
sequenziale=(47.127,63.6255,77.9589,92.9375,104.945,120.332,133.822,149.229,161.503)
speedup=np.array(sequenziale)/np.array(tempo)
print(speedup)
#plot speedup
plt.scatter(K, speedup)
plt.plot(K, speedup)
plt.title("Speedup plot of K")
plt.xlabel("K")
plt.ylabel("Speedup")
plt.show()


#2 parallelizzazioni dataset 10.csv
K=(1,2,3,4,5,6,7,8)
#tempo=(11.1947,12.4869,13.8921,15.5385,16.7009,18.4992,19.9722,23.9036,25.4356)
tempo=(0.00726657,0.0093103,0.05392,0.0443879,0.0158788,0.00782038,0.00869078,0.00787969) #dinamico
sequenziale=(0.00726657,0.00726657,0.00726657,0.00726657,0.00726657,0.00726657,0.00726657,0.00726657)
speedup=np.array(sequenziale)/np.array(tempo)
print(speedup)
#plot speedup
plt.scatter(K, speedup)
plt.plot(K, speedup)
plt.title("Speedup plot of K")
plt.xlabel("K")
plt.ylabel("Speedup")
plt.show()








