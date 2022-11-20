import matplotlib.pyplot as plt
import networkx as nx
import grave
import sys
import numpy as np
import time
#csvs to read : taken as argument for the function
#csv1 format: serial, x coordinate, y coordinate, highlighted(0/1)
#csv2 format: node1, node2


def present(csv1,csv2):
    x_cord=np.array([])
    y_cord=np.array([])
    G=nx.Graph()
    color_map=[]; edge_color=[]
    with open(csv1,'r') as f1:
        
        for line in f1:
            line=line.strip()
            line=line.split(',')
            x_cord=np.append(x_cord,float(line[1]))
            y_cord=np.append(y_cord,float(line[2]))
            if(line[3]=='1'): # edge is red
                #plt.plot(float(line[1]),float(line[2]),'ro')
                G.add_node(int(line[0]),pos=(float(line[1]),float(line[2])),color='r')
                color_map.append('r')
            else:#blue
                #plt.plot(float(line[1]),float(line[2]),'bo')
                G.add_node(int(line[0]),pos=(float(line[1]),float(line[2])),color='b')
                color_map.append('b')
    with open(csv2,'r') as f2:
        for line in f2:
            line=line.strip()
            line=line.split(',')

            if(G._node[int(line[0])]['color']=='r' or G._node[int(line[1])]['color']=='r'):
                G.add_edge(int(line[0]),int(line[1]),color='r')
                edge_color.append('r')
            else:
                G.add_edge(int(line[0]),int(line[1]),color='b')
                edge_color.append('b')

            
    nx.draw_networkx(G,pos=nx.get_node_attributes(G,'pos'),node_color=color_map,edge_color=edge_color)
    plt.show()

if __name__ == "__main__":
    present(sys.argv[1],sys.argv[2])
