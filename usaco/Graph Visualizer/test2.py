import netgraph
import matplotlib.pyplot as plt
from matplotlib import animation
plt.ion()

# Initialise figure and set size of axis to draw on.
fig, ax = plt.subplots(1, 1)
ax.set(xlim=[-2, 2], ylim=[-2, 2])

# Define a graph. Here we start with a single edge:
graph = [(0, 1), (1, 2)]

# Initialise plot:
plot_instance = netgraph.InteractivelyConstructDestroyGraph(graph, draw_arrows=False, ax=ax)

# As before, the node layout can be changed by selecting the nodes and moving them around
# using the mouse. The graph itself can be manipulated using the following hotkeys:
#   Pressing 'A' will add a node to the graph at the current cursor position.
#   Pressing 'D' will remove a selected node.
#   Pressing 'a' will add edges between all selected nodes.
#   Pressing 'd' will remove edges between all selected nodes.
#   Pressing 'r' will reverse the direction of edges between all selected nodes.

# To access the new node positions:
node_positions = plot_instance.node_positions

# The new graph can be accessed via the edge list:
edge_list = plot_instance.edge_list
plt.show(block=True)