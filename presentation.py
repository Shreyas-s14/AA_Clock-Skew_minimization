import matplotlib.pyplot as plt
import networkx as nx
import grave
import sys
import numpy as np
import time
#csvs to read : taken as argument for the function
#csv1 format: serial, x coordinate, y coordinate, highlighted(0/1)
#csv2 format: edge number, node1, node2
#using matplotlib, map the graph with x and y coordinates

def present(csv1,csv2):
    x_cord=np.array([])
    y_cord=np.array([])
    G=nx.Graph()
    with open(csv1,'r') as f1:
        for line in f1:
            line=line.strip()
            line=line.split(',')
            x_cord=np.append(x_cord,float(line[1]))
            y_cord=np.append(y_cord,float(line[2]))
            if(line[3]=='1'): # edge is red
                #plt.plot(float(line[1]),float(line[2]),'ro')
                G.add_node(int(line[0]),pos=(float(line[1]),float(line[2])),color='red')
            else:#blue
                #plt.plot(float(line[1]),float(line[2]),'bo')
                G.add_node(int(line[0]),pos=(float(line[1]),float(line[2])),color='blue')
    with open(csv2,'r') as f2:
        for line in f2:
            line=line.strip()
            line=line.split(',')
            #plt.plot([x_cord[int(line[1])],x_cord[int(line[2])]], [y_cord[int(line[1])],y_cord[int(line[2])]], 'k-')
            G.add_edge(int(line[1]),int(line[2]))  
    #plot the graph with axis labeled as x and y
    grave.draw_networkx(G,node_color='color')
    plt.show()                         
