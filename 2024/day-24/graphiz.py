import sys
from graphviz import Digraph

def parse_input_to_graphviz(input_text):
    # Create a Digraph instance
    dot = Digraph(format="png")
    
    # Split input into individual lines
    lines = input_text.strip().split("\n")
    
    for line in lines:
        # Skip empty lines or lines that do not contain '->'
        if '->' not in line:
            continue

        # Parse the line into nodes and the operation
        parts = line.split("->")
        left_part = parts[0].strip()
        right_node = parts[1].strip()
 #       print("left")
#        print(left_part)
        # Identify the operation and its inputs
        if "AND" in left_part:
            inputs = left_part.split(" AND ", 1)
            operation = "AND"
        elif "XOR" in left_part:
            inputs = left_part.split(" XOR ", 1)
            operation = "XOR"
        elif "OR" in left_part:
            inputs = left_part.split(" OR ", 1)
            operation = "OR"
        else:
            # If no valid operation, skip this line
            print(f"Skipping invalid line: {line}")
            continue
        
        input_nodes = inputs #.strip().split()
        print(inputs)
        
        # Add nodes and edges to the graph
        for input_node in input_nodes:
            dot.edge(input_node, right_node, label=operation)
    
    return dot

# Read input from stdin
input_text = sys.stdin.read()

# Generate the graph
graph = parse_input_to_graphviz(input_text)

# Render the graph and plot
graph.render("output_graph", format="pdf")
