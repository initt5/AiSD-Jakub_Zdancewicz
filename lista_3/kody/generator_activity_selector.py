import random
import sys

length = int(sys.argv[1])
mode = sys.argv[2]

def generate_activities(length, mode, filename="input.txt"):
    """
    Generates a test file with activities, ensuring the end times are sorted in ascending order.

    Args:
        num_activities (int): Number of activities to generate.
        mode (str): Generator mode (s: start, e: end)
        filename (str): The name of the file to save the activities.
    """
    activities = []

    for _ in range(length):
        start = random.randint(0, length+1)  # Start times distributed over a larger range
        duration = random.randint(1, 20)  # Random durations between 1 and 20 units
        end = start + duration
        activities.append((start, end))

    # Sort activities by their end times
    if mode == "e":
      activities.sort(key=lambda x: x[1])
    elif mode == "s":
      activities.sort(key=lambda x: x[0])

    # Write to file
    with open(filename, "w") as f:
        f.write(f"{length}\n")
        for start, end in activities:
            f.write(f"{start} {end}\n")

# Example usage
generate_activities(length, mode)
