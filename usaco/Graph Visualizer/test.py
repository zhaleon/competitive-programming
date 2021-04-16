import numpy as np
import matplotlib.pyplot as plt
plt.ion()
import netgraph

plt.rcParams['axes.linewidth'] = 0.05 #set the value globally
plt.figure(figsize=(20,10))
# Construct sparse, directed, weighted graph
# with positive and negative edges:
total_nodes = 10
weights = np.random.randn(total_nodes, total_nodes)
connection_probability = 0.2
is_connected = np.random.rand(total_nodes, total_nodes) <= connection_probability
graph = np.zeros((total_nodes, total_nodes))
graph[is_connected] = weights[is_connected]

# Make a standard plot:
#netgraph.draw(graph)

# Create an interactive plot.
# NOTE: you must retain a reference to the object instance!
# Otherwise the whole thing will be garbage collected after the initial draw
# and you won't be able to move the plot elements around.
plot_instance = netgraph.InteractiveGraph(graph, draw_arrows=False, edge_color = 'black')

# The position of the nodes can be adjusted with the mouse.
# To access the new node positions:
node_positions = plot_instance.node_positions
plt.show(block=True)